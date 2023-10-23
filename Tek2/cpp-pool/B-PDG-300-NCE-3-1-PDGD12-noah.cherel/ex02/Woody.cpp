/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file) : Toy(WOODY, name, file)
{
}

Woody::~Woody()
{
}

std::ostream &operator<<(std::ostream &os, const Woody &woody)
{
    os << "WOODY: " << woody.getName() << " \"" << woody.getAscii() << "\"";
    return os;
}