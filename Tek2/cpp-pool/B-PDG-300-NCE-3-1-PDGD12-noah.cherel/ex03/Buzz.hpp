/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"
#include <iostream>

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &file = "buzz.txt");
        ~Buzz();
        void speak(const std::string &str);
    protected:
    private:
};

std::ostream &operator<<(std::ostream &os, const Buzz &buzz);

#endif /* !BUZZ_HPP_ */
