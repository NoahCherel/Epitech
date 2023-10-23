/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
{
    _vitamins = 15;
    _peeled = false;
}

std::string Coconut::getName() const
{
    return "coconut";
}