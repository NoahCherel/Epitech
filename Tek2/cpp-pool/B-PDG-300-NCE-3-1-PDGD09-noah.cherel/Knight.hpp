/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();
        int attack();
        int special();
        void rest();
    protected:
    private:
};

#endif /* !KNIGHT_HPP_ */
