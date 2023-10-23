/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** tracer
*/

#include "../include/core.hpp"

void createPointLight(ImageBuilder& builder, const Setting& light) {
    Vec3f position((int)light["x"], (int)light["y"], (int)light["z"]);
    Vec3f color(0);
    float radius = 3;
    float intensity = 0;
    builder.addSphere(Sphere(position, radius, color, intensity, 0, Vec3f(3)));
}
