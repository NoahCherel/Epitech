/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Raspberry
*/

#ifndef RASPBERRY_HPP_
#define RASPBERRY_HPP_

#include "ABerry.hpp"

class Raspberry : public ABerry
{
    public:
    Raspberry();
    std::string getName() const override;
};

#endif /* !RASPBERRY_HPP_ */
