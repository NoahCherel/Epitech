/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
#define ORANGE_HPP_

#include "ACitrus.hpp"

class Orange : public ACitrus
{
    public:
    Orange();
    std::string getName() const override;
};

#endif /* !ORANGE_HPP_ */
