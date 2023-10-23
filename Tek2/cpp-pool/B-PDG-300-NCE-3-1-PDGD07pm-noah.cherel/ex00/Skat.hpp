/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>
#include <string>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    protected:
    private:
        std::string _name;
        int _stimPaks;
};

#endif /* !SKAT_HPP_ */
