/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "ANut.hpp"

class Coconut : public ANut
{
    public:
    Coconut();
    std::string getName() const override;
};

#endif /* !COCONUT_HPP_ */
