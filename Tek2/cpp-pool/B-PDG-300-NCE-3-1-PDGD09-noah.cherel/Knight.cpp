/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>
#include <string>

#include "Peasant.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << getName() << " takes off his armor." << std::endl;
}

int Knight::attack() {
    if (getHp() == 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() >= 10) {
        std::cout << getName() << " strikes with his sword." << std::endl;
        setPower(getPower() - 10);
        return 20;
    } else {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
}

int Knight::special() {
    if (getHp() == 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() >= 30) {
        std::cout << getName() << " impales his enemy." << std::endl;
        setPower(getPower() - 30);
        return 50;
    } else {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
}

void Knight::rest() {
    if (getHp() == 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    else {
        std::cout << getName() << " eats." << std::endl;
        setPower(getPower() + 50);
    }
}
