/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}