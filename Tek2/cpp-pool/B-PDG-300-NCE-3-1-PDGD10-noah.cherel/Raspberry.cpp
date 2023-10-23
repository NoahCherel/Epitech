/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Raspberry
*/

#include "Raspberry.hpp"

Raspberry::Raspberry()
{
    _vitamins = 15;
    _peeled = false;
}

std::string Raspberry::getName() const
{
    return "raspberry";
}