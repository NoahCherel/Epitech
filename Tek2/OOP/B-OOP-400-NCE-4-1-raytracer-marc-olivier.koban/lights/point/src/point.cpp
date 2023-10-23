/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** point
*/

#include "../include/point.hpp"

Point::Point() {
}

Point::~Point() {
}

extern "C" ILight *createLight() {
    return new Point();
}
