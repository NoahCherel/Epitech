/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>
#include <iostream>
#include <fstream>

class ICharacter
{
    public:
        ICharacter(const std::string& name, int power) : _name(name), _power(power), _health(100) {};
        virtual ~ICharacter() {};
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        std::string getName() {return _name;};
        int getHp() {return _health;};
        int getPower() {return _power;};
    protected:
        std::string _name;
        int _health;
        int _power;
    private:
};

#endif /* !ICHARACTER_HPP_ */
