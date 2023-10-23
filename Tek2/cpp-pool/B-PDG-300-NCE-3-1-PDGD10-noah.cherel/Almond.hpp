/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Almond
*/

#ifndef ALMOND_HPP_
#define ALMOND_HPP_

#include "ANut.hpp"

class Almond : public ANut
{
    public:
    Almond();
    std::string getName() const override;
};

#endif /* !ALMOND_HPP_ */
