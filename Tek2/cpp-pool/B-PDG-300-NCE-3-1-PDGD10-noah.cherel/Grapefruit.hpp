/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Grapefruit
*/

#ifndef GRAPEFRUIT_HPP_
#define GRAPEFRUIT_HPP_

#include "ACitrus.hpp"

class Grapefruit : public ACitrus
{
    public:
    Grapefruit();
    std::string getName() const override;
};

#endif /* !GRAPEFRUIT_HPP_ */
