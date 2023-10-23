/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

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

void Woody::speak(const std::string &str)
{
    std::cout << "WOODY: " << getName() << " \"" << str << "\"" << std::endl;
}

bool Woody::speak_es(const std::string &str)
{
    lastError = Error{"wrong mode", "speak_es", Error::SPEAK};
    return false;
}
