/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** BloodOrange
*/

#ifndef BLOODORANGE_HPP_
#define BLOODORANGE_HPP_

#include "Orange.hpp"

class BloodOrange : public Orange 
{
    public:
    BloodOrange();
    std::string getName() const override;
};

#endif /* !BLOODORANGE_HPP_ */
