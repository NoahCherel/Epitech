/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "ACitrus.hpp"

class Lemon : public ACitrus
{
    public:
    Lemon();
    std::string getName() const override;
};

#endif /* !LEMON_HPP_ */
