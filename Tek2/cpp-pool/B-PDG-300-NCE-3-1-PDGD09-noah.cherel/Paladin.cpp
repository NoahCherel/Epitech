/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include "Peasant.hpp"
#include "Knight.hpp"
#include "Enchanter.hpp"
#include "Priest.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

/*
Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << Knight::getName() << " fights for the light." << std::endl;
}*/

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    if (power < 0)
        this->_power = 0;
    else if (power > 100)
        this->_power = 100;
    else
        this->_power = power;
    this->_health = 100;
    std::cout << this->getName() << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << Knight::getName() << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    Priest::rest();
}

void Paladin::damage(int damage)
{
    Knight::damage(damage);
}
