/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** tracer
*/

#include "../include/core.hpp"

void createSphere(ImageBuilder& builder, const Setting& sphere) {
    builder.addSphere(Sphere(
        Vec3f(
            (int)sphere["x"],
            (int)sphere["y"],
            (int)sphere["z"]
        ),
        (int)sphere["r"],
        Vec3f(
            (int)sphere["color"]["r"] / 255.0,
            (int)sphere["color"]["g"] / 255.0,
            (int)sphere["color"]["b"] / 255.0
        ),
        (float)sphere["reflection"],
        (float)sphere["transparency"]
    ));
}

void createPlane(ImageBuilder& builder, const Setting& plane) {
    int x = 0, y = -10004, z = 0;
    const char* axis = plane["axis"];
    if (strcmp(axis, "X") == 0) x = (int)(plane["position"]);
    else if (strcmp(axis, "Y") == 0) y = (int)(plane["position"]);
    else if (strcmp(axis, "Z") == 0) z = (int)(plane["position"]);
    else return;
    const Setting& color = plane["color"];
    builder.addSphere(Sphere(
        Vec3f(x, y, z),
        10000,
        Vec3f(
            (int)color["r"] / 255.0,
            (int)color["g"] / 255.0,
            (int)color["b"] / 255.0
        ),
        0,
        0
    ));
}
