/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Skat
*/

#include "Skat.hpp"
#include <iostream>
#include <string>

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > 0 && number <= _stimPaks) {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    } else {
        std::cout << "Don't be greedy" << std::endl;
    }
}


Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

int &Skat::stimPaks()
{
    return _stimPaks;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number > 0)
        _stimPaks += number;
    else if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks()
{
    if (_stimPaks > 0) {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}
