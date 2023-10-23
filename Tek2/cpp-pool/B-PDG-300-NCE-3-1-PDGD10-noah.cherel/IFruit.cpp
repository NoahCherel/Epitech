/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const IFruit& fruit)
{
    os << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << std::boolalpha << fruit.isPeeled() << "]";
    return os;
}
