/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Strawberry
*/

#include "Strawberry.hpp"
#include "ABerry.hpp"

Strawberry::Strawberry()
{
    _vitamins = 6;
    _peeled = true;
}

std::string Strawberry::getName() const
{
    return "strawberry";
}