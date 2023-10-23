/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** main
*/

#include "../../../interfaces/ILibrary.hpp"
#include "../include/ncurses.hpp"


NCurses::NCurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    refresh();
    window = newwin(600, 800, 0, 0);
}

NCurses::~NCurses() {
    endwin();
}

void NCurses::init() {
    /* do nothing, window is already created in constructor */
}

void NCurses::clear() {
    wclear(window);
}

void NCurses::display(std::vector<std::string> map) {
    wclear(window);
    std::string newText;
    for (auto &line : map) {
        newText += line + "\n";
    }
    wprintw(window, newText.c_str());
    wrefresh(window);
}

std::string NCurses::getEvent() {
    nodelay(stdscr, TRUE);
    int ch = getch();
    switch (ch) {
        case KEY_BACKSPACE:
            return "BACKSPACE";
        case KEY_LEFT:
            return "LEFT";
        case KEY_RIGHT:
            return "RIGHT";
        case KEY_UP:
            return "UP";
        case KEY_DOWN:
            return "DOWN";
        case 27:
            return "ESC";
        case 10:
            return "ENTER";
        case 32:
            return "SPACE";
        case KEY_F(1):
            return "F1";
        case KEY_F(2):
            return "F2";
        case KEY_F(3):
            return "F3";
        case KEY_F(4):
            return "F4";
        default:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                char letter = 'A' + (ch - 'a');
                return std::string(1, letter);
            }
            break;
    }
    return "";
}

void NCurses::stop() {
    delwin(window);
    endwin();
}

std::string NCurses::getName() {
    return "ncurses";
}

extern "C" ILibrary *createLibrary() {
    return new NCurses();
}
