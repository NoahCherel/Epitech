/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Priest
*/

#include "Priest.hpp"
#include "Peasant.hpp"
#include <iostream>
#include <string>

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << Priest::getName() << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << Priest::getName() << " finds peace." << std::endl;
}

void Priest::rest() {
    if (Priest::getHp() < 0) {
        this->setHp(0);
        std::cout << Priest::getName() << " is out of combat." << std::endl;
        return;
    }
    if (Priest::getHp() == 0) {
        std::cout << Priest::getName() << " is out of combat." << std::endl;
        return;
    }
    if (Priest::getPower() < 0) {
        std::cout << Priest::getName() << " is out of power." << std::endl;
        this->setPower(0);
        return;
    }
    if (Priest::getHp() > 0) {
        Priest::setHp(Priest::getHp() + 100);
        Priest::setPower(Priest::getPower() + 100);
        if (Priest::getHp() > 100)
            Priest::setHp(100);
        if (Priest::getPower() > 100)
            Priest::setPower(100);
        std::cout << Priest::getName() << " prays." << std::endl;
        return;
    }
}
