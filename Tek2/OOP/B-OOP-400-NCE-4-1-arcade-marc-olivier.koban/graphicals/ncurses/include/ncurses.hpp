/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

#include "../../../interfaces/ILibrary.hpp"
#include <ncurses.h>

class NCurses : public ILibrary {
    public:
        NCurses();
        ~NCurses();
        std::string getName();
        void init();
        void stop();
        void display(std::vector<std::string> map);
        void clear();
        std::string getEvent();

    protected:
    private:
        WINDOW *window;
};

#endif /* !NCURSES_HPP_ */
