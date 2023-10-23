/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** tracer
*/

#include "../include/core.hpp"

std::vector<std::vector<sf::Color>> renderImage(const int width, const int height, const std::vector<Sphere>& spheres) {
    std::vector<std::vector<sf::Color>> framebuffer(height, std::vector<sf::Color>(width));

    Vec3f *image = new Vec3f[width * height];
    Vec3f *pixel = image;
    float invWidth = 1 / float(width), invHeight = 1 / float(height);
    float fov = 30, aspectratio = width / float(height);
    float angle = tan(M_PI * 0.5 * fov / 180.0);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x, ++pixel) {
            float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio;
            float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
            Vec3f raydir(xx, yy, -1);
            raydir.normalize();
            *pixel = trace(Vec3f(0), raydir, spheres, 0);
        }
    }
    for (int i = 0; i < width * height; ++i) {
        framebuffer[i / width][i % width] = sf::Color(std::min(float(1), image[i].x) * 255, std::min(float(1), image[i].y) * 255, std::min(float(1), image[i].z) * 255);
    }
    delete[] image;
    return framebuffer;
}

bool findNearestIntersection(const Vec3f& rayorig, const Vec3f& raydir, const std::vector<Sphere>& spheres,
                            float& tnear, const Sphere*& sphere)
{
    tnear = INFINITY;
    sphere = nullptr;
    for (const auto& s : spheres) {
        float t0, t1;
        if (s.intersect(rayorig, raydir, t0, t1)) {
            if (t0 < 0) {
                t0 = t1;
            }
            if (t0 < tnear) {
                tnear = t0;
                sphere = &s;
            }
        }
    }
    return sphere != nullptr;
}

Vec3f computeReflectionAndRefraction(const Vec3f& phit, const Vec3f& nhit, const Vec3f& raydir, const Sphere* sphere, const float& bias, const bool& inside, const int& depth, const std::vector<Sphere>& spheres) {
    float facingratio = -raydir.dot(nhit);
    float fresneleffect = 1 * 0.1 + pow(1 - facingratio, 3) * 0.9;
    Vec3f refldir = raydir - nhit * 2 * raydir.dot(nhit);
    refldir.normalize();
    Vec3f reflection = trace(phit + nhit * bias, refldir, spheres, depth + 1);
    Vec3f refraction = 0;
    if (sphere->transparency) {
        float ior = 1.1, eta = (inside) ? ior : 1 / ior; // are we inside or outside the surface?
        float cosi = -nhit.dot(raydir);
        float k = 1 - eta * eta * (1 - cosi * cosi);
        Vec3f refrdir = raydir * eta + nhit * (eta *  cosi - sqrt(k));
        refrdir.normalize();
        refraction = trace(phit - nhit * bias, refrdir, spheres, depth + 1);
    }
    return (reflection * fresneleffect + refraction * (1 - fresneleffect) * sphere->transparency) * sphere->surfaceColor;
}

Vec3f computeLighting(const Vec3f& phit, const Vec3f& nhit, const Vec3f& surfaceColor, const std::vector<Sphere>& spheres) {
    Vec3f surfaceColorWithLighting = 0;
    for (unsigned i = 0; i < spheres.size(); ++i) {
        if (spheres[i].emissionColor.x > 0) {
            Vec3f transmission = 1;
            Vec3f lightDirection = spheres[i].center - phit;
            lightDirection.normalize();
            for (unsigned j = 0; j < spheres.size(); ++j) {
                if (i != j) {
                    float t0, t1;
                    if (spheres[j].intersect(phit + nhit * 1e-4, lightDirection, t0, t1)) {
                        transmission = 0;
                        break;
                    }
                }
            }
            surfaceColorWithLighting += surfaceColor * transmission *
            std::max(float(0), nhit.dot(lightDirection)) * spheres[i].emissionColor;
        }
    }
    return surfaceColorWithLighting;
}

Vec3f trace(const Vec3f &rayorig, const Vec3f &raydir, const std::vector<Sphere> &spheres, const int &depth)
{
    float tnear = INFINITY;
    const Sphere* sphere = NULL;
    if (!findNearestIntersection(rayorig, raydir, spheres, tnear, sphere)) {
        return Vec3f(2); // background color
    }
    Vec3f surfaceColor = 0; // color of the ray/surfaceof the object intersected by the ray
    Vec3f phit = rayorig + raydir * tnear; // point of intersection
    Vec3f nhit = phit - sphere->center; // normal at the intersection point
    nhit.normalize(); // normalize normal direction
    float bias = 1e-4; // add some bias to the point from which we will be tracing
    bool inside = false;
    if (raydir.dot(nhit) > 0) nhit = -nhit, inside = true;
    if ((sphere->transparency > 0 || sphere->reflection > 0) && depth < MAX_RAY_DEPTH) {
        surfaceColor = computeReflectionAndRefraction(phit, nhit, raydir, sphere, bias, inside, depth, spheres);
    } else {
        surfaceColor = computeLighting(phit, nhit, sphere->surfaceColor, spheres);
    }
    return surfaceColor + sphere->emissionColor;
}

std::vector<std::vector<sf::Color>> raytrace(std::vector<std::vector<sf::Color>> framebuffer, Config *cfg)
{
    srand48(13);
    int height = framebuffer.size();
    int width = framebuffer[0].size();
    ImageBuilder builder(width, height);
    const Setting &spheres_conf = cfg->getRoot()["primitives"]["spheres"];
    for (int i = 0; i < spheres_conf.getLength(); i++) {
        createSphere(builder, spheres_conf[i]);
    }
    const Setting &lights_conf = cfg->getRoot()["lights"]["point"];
    for (int i = 0; i < lights_conf.getLength(); i++) {
        createPointLight(builder, lights_conf[i]);
    }
    const Setting &planes_conf = cfg->getRoot()["primitives"]["planes"];
    for (int i = 0; i < planes_conf.getLength(); i++) {
        createPlane(builder, planes_conf[i]);
    }
    std::vector<std::vector<sf::Color>> result = builder.build();
    return result;
}
