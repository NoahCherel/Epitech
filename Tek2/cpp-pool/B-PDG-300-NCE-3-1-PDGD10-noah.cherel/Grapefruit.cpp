/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Grapefruit
*/

#include "Grapefruit.hpp"

Grapefruit::Grapefruit()
{
    _vitamins = 4;
    _peeled = false;
}

std::string Grapefruit::getName() const
{
    return "grapefruit";
}
