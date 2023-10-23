/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Orange
*/

#include "Orange.hpp"

Orange::Orange()
{
    _vitamins = 7;
    _peeled = false;
}

std::string Orange::getName() const
{
    return "orange";
}