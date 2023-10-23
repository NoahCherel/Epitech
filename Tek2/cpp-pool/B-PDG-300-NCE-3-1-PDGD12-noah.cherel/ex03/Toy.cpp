/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy() : type(BASIC_TOY), name("toy"), picture(Picture())
{
}

Toy::~Toy()
{
}

Toy::Toy(ToyType type, std::string name, std::string file) : type(type), name(name), picture(Picture(file))
{
}

Toy::Toy(Toy const &toy) : type(toy.type), name(toy.name), picture(toy.picture)
{
}

Toy &Toy::operator=(Toy const &toy)
{
    type = toy.type;
    name = toy.name;
    picture = toy.picture;
    return *this;
}

Toy &Toy::operator<<(std::string const &str)
{
    picture.data = str;
    return *this;
}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

void Toy::setName(std::string name)
{
    this->name = name;
}

bool Toy::setAscii(std::string file)
{
    return picture.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return picture.data;
}

void Toy::speak(std::string const &str)
{
    std::cout << name << " \"" << str << "\"" << std::endl;
}