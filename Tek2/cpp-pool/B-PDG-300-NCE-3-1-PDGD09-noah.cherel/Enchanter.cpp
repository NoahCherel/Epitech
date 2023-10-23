/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << Enchanter::getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << Enchanter::getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack() {
    if (Enchanter::getHp() < 0) {
        this->setHp(0);
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (Enchanter::getHp() == 0) {
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return 0;
    } else {
        std::cout << Enchanter::getName() << " doesn't know how to fight." << std::endl;
        return 0;
    }
}

int Enchanter::special() {
    if (Enchanter::getHp() < 0) {
        this->setHp(0);
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (Enchanter::getHp() == 0) {
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (Enchanter::getPower() < 0) {
        std::cout << Enchanter::getName() << " is out of power." << std::endl;
        this->setPower(0);
        return 0;
    }
    if (Enchanter::getPower() >= 50) {
        std::cout << Enchanter::getName() << " casts a fireball." << std::endl;
        Enchanter::setPower(Enchanter::getPower() - 50);
        return 99;
    } else {
        std::cout << Enchanter::getName() << " is out of power." << std::endl;
        return 0;
    }
}

void Enchanter::rest() {
    if (Enchanter::getHp() < 0) {
        this->setHp(0);
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return;
    }
    if (Enchanter::getHp() == 0) {
        std::cout << Enchanter::getName() << " is out of combat." << std::endl;
        return;
    }

    if (Enchanter::getHp() > 0) {
        Enchanter::setPower(Enchanter::getPower() + 100);
        if (Enchanter::getPower() > 100) {
            Enchanter::setPower(100);
        }
        std::cout << Enchanter::getName() << " meditates." << std::endl;
    }
}
