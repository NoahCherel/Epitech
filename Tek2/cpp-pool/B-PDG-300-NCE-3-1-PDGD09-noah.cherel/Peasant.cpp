/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>
#include <string>


Peasant::Peasant(const std::string &name, int power) : ICharacter(name, power)
{
    _name = name;
    _power = power;
    _health = 100;
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _health;
}

void Peasant::setHp(int hp)
{
    _health = hp;
}

void Peasant::setPower(int power)
{
    _power = power;
}

void Peasant::setName(const std::string &name)
{
    _name = name;
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::attack()
{
    if (_power > 100) {
        _power = 100;
    }
    if (_power < 0) {
        _power = 0;
    }
    if (_health < 0)
        _health = 0;
    if (_health > 100)
        _health = 100;
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << _name << " tosses a stone." << std::endl;
    _power -= 10;
    return 5;
}

int Peasant::special()
{
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (_health == 0 || _health < 0) {
        std::cout << _name << " is out of combat." << std::endl;
    } else {
        std::cout << _name << " takes a nap." << std::endl;
        _power += 30;
    }
    if (_power > 100) {
        _power = 100;
    }
}

void Peasant::damage(int damage)
{
    if (_health - damage <= 0) {
        _health = 0;
    }

    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
    }
    if (_health - damage > 0) {
    std::cout << _name << " takes " << damage << " damage." << std::endl;
    _health -= damage;
    }
}
