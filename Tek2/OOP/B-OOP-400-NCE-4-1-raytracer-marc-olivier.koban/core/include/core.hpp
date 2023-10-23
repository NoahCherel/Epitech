/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <iostream>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <vector>
    #include <cmath>
    #include <cstdlib>
    #include <cstdio>
    #include <fstream>
    #include <cassert>

    #include <libconfig.h++>
    using namespace libconfig;

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>

    #include "../../interfaces/IPrimitive.hpp"
    #include "../../interfaces/ILight.hpp"

    #define MAX_RAY_DEPTH 5

    template<typename T>
    class Vec3 {
        public:
            T x, y, z;
            Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
            Vec3(T xx) : x(xx), y(xx), z(xx) {}
            Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
            Vec3& normalize() {
                T nor2 = length2();
                if (nor2 > 0) {
                    T invNor = 1 / sqrt(nor2);
                    x *= invNor, y *= invNor, z *= invNor;
                }
                return *this;
            }
            Vec3<T> operator* (const T &f) const { return Vec3<T>(x * f, y * f, z * f); }
            Vec3<T> operator* (const Vec3<T> &v) const { return Vec3<T>(x * v.x, y * v.y, z * v.z); }
            T dot(const Vec3<T> &v) const { return x * v.x + y * v.y + z * v.z; }
            Vec3<T> operator - (const Vec3<T> &v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
            Vec3<T> operator + (const Vec3<T> &v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
            Vec3<T>& operator += (const Vec3<T> &v) { x += v.x, y += v.y, z += v.z; return *this; }
            Vec3<T>& operator *= (const Vec3<T> &v) { x *= v.x, y *= v.y, z *= v.z; return *this; }
            Vec3<T> operator - () const { return Vec3<T>(-x, -y, -z); }
            T length2() const { return x * x + y * y + z * z; }
            T length() const { return sqrt(length2()); }
            friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v)
            {
                os << "[" << v.x << " " << v.y << " " << v.z << "]";
                return os;
            }
    };
    typedef Vec3<float> Vec3f;

    class Sphere {
        public:
            Vec3f center;                           /// position of the sphere
            float radius, radius2;                  /// sphere radius and radius^2
            Vec3f surfaceColor, emissionColor;      /// surface color and emission (light)
            float transparency, reflection;         /// surface transparency and reflectivity
            Sphere(
                const Vec3f &c,
                const float &r,
                const Vec3f &sc,
                const float &refl = 0,
                const float &transp = 0,
                const Vec3f &ec = 0) :
                center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
                transparency(transp), reflection(refl)
            { /* empty */ }
            bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const
            {
                Vec3f l = center - rayorig;
                float tca = l.dot(raydir);
                if (tca < 0) return false;
                float d2 = l.dot(l) - tca * tca;
                if (d2 > radius2) return false;
                float thc = sqrt(radius2 - d2);
                t0 = tca - thc;
                t1 = tca + thc;
                return true;
            }
    };
    class Factory {
        public:
            template<typename T>
            static Vec3<T> createVec3(T x, T y, T z) {
                return Vec3<T>(x, y, z);
            }
            template<typename VecType>
            static Sphere createSphere(VecType center, float radius, VecType surfaceColor, float reflection = 0, float transparency = 0, VecType emissionColor = 0) {
                return Sphere(center, radius, surfaceColor, reflection, transparency, emissionColor);
            }

            template<typename VecType>
            std::vector<std::vector<sf::Color>> renderImage(const int width, const int height, const std::vector<Sphere>& spheres);
    };

    std::vector<std::vector<sf::Color>> renderImage(const int width, const int height, const std::vector<Sphere>& spheres);

    class ImageBuilder {
        public:
            ImageBuilder(int width, int height)
            : width_(width), height_(height) {}

            ImageBuilder& addSphere(const Sphere& sphere) {
                spheres_.push_back(sphere);
                return *this;
            }

            std::vector<std::vector<sf::Color>> build() const {
                return renderImage(width_, height_, spheres_);
            }

        private:
            int width_;
            int height_;
            std::vector<Sphere> spheres_;
    };

    // buffer.cpp
    std::vector<std::vector<sf::Color>> generate_buffer(int width, int height);

    // display.cpp
    void display_ppm(std::vector<std::vector<sf::Color>> &framebuffer);
    void display_window(std::vector<std::vector<sf::Color>> &framebuffer);
    void output_ppm(std::vector<std::vector<sf::Color>> &framebuffer, std::string filename);

    // tracer.cpp
    std::vector<std::vector<sf::Color>> raytrace(std::vector<std::vector<sf::Color>> framebuffer, Config *cfg);
    Vec3f trace(const Vec3f &rayorig, const Vec3f &raydir, const std::vector<Sphere> &spheres, const int &depth);
    void createSphere(ImageBuilder& builder, const Setting& sphere);
    void createPlane(ImageBuilder& builder, const Setting& plane);
    void createPointLight(ImageBuilder& builder, const Setting& light);

#endif /* !CORE_HPP_ */
