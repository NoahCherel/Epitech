/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Almond
*/

#include "Almond.hpp"

Almond::Almond()
{
    _vitamins = 2;
    _peeled = false;
}

std::string Almond::getName() const
{
    return "almond";
}