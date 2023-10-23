/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy(BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

std::ostream &operator<<(std::ostream &os, const Buzz &buzz)
{
    os << "BUZZ: " << buzz.getName() << " \"" << buzz.getAscii() << "\"";
    return os;
}

void Buzz::speak(const std::string &str)
{
    std::cout << "BUZZ: " << getName() << " \"" << str << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string &str)
{
    std::cout << "BUZZ: " << getName() << " senorita \"" << str << "\" senorita" << std::endl;
    return true;
}