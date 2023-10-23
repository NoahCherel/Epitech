/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AFruit
*/

#include "AFruit.hpp"

unsigned int AFruit::getVitamins() const
{
    return _peeled ? _vitamins : 0;
}

bool AFruit::isPeeled() const
{
    return _peeled;
}

void AFruit::peel()
{
    _peeled = true;
}
