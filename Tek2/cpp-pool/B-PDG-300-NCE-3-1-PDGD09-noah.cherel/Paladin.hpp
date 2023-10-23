/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "ICharacter.hpp"
#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest {
    public:
        ~Paladin();
        Paladin(const std::string &name, int power);
        int attack();
        int special();
        void rest();
        void damage(int damage);
    protected:
    private:
        int _power;
        int _health;
        std::string _name;
};

#endif /* !PALADIN_HPP_ */
