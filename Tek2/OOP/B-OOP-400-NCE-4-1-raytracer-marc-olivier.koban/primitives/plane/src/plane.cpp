/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** plane
*/

#include "../include/plane.hpp"

Plane::Plane() {
}

Plane::~Plane() {
}

extern "C" IPrimitive *createPrimitive() {
    return new Plane();
}
