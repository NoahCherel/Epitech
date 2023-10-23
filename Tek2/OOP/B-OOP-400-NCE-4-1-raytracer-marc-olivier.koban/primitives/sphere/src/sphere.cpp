/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** sphere
*/

#include "../include/sphere.hpp"

Sphere::Sphere() {
}

Sphere::~Sphere() {
}

extern "C" IPrimitive *createPrimitive() {
    return new Sphere();
}
