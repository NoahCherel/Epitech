/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
#define STRAWBERRY_HPP_

#include "ABerry.hpp"

class Strawberry : public ABerry
{
    public:
    Strawberry();
    std::string getName() const override;

};

#endif /* !STRAWBERRY_HPP_ */
