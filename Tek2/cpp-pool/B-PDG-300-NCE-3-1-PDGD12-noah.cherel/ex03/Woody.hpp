/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &file = "woody.txt");
        ~Woody();
        void speak(const std::string &str);
    protected:
    private:
};

std::ostream &operator<<(std::ostream &os, const Woody &woody);

#endif /* !WOODY_HPP_ */
