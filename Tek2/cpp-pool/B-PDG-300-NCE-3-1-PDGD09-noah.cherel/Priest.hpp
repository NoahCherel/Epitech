/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Peasant.hpp"
#include "Enchanter.hpp"

class Priest : virtual public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();
        void rest();
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
