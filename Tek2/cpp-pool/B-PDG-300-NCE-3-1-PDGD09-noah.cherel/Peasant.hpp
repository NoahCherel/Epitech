/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_


#include "ICharacter.hpp"
#include <string>
#include <iostream>
#include <fstream>

/*
class  Peasant {
    public:
        ~Peasant();
        Peasant(const std::string &name, int power);
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        void setHp(int hp);
        void setPower(int power);
        void setName(const std::string &name);
        int attack();
        int special();
        void rest();
        void damage(int damage);
    protected:
    private:
        std::string _name;
        int _health;
        int _power;
};*/

class Peasant : public ICharacter {
    public:
        Peasant(const std::string& name, int power);
        ~Peasant();
        int attack();
        int special();
        void rest();
        void damage(int damage);
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        void setHp(int hp);
        void setPower(int power);
        void setName(const std::string &name);
    protected:
    private:
        std::string _name;
        int _health = 100;
        int _power;
};

#endif /* !PEASANT_HPP_ */