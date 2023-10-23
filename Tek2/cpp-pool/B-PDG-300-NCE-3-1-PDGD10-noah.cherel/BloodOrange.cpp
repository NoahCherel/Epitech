/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** BloodOrange
*/

#include "BloodOrange.hpp"

BloodOrange::BloodOrange()
{
    _vitamins = 5;
    _peeled = false;
}

std::string BloodOrange::getName() const
{
    return "blood orange";
}