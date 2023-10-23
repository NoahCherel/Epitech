/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu
*/

#include "../include/my.h"

void options_menu(int ch, WINDOW *win, global_t *a)
{
    int i = 0; int y, x, y_w, x_w; getmaxyx(win, y_w, x_w);
    while (ch = wgetch(win)) {
        if (ch == KEY_UP) {
            i = 0; wattron(win, A_STANDOUT);
            mvwprintw(win, y_w / 4, x_w / 2, "Play");
            wattroff(win, A_STANDOUT);
            mvwprintw(win, y_w / 4 + 1, x_w / 2, "Quit");
        }
        if (ch == KEY_DOWN) {
            i = 1; wattron(win, A_STANDOUT);
            mvwprintw(win, y_w / 4 + 1, x_w / 2, "Quit");
            wattroff(win, A_STANDOUT);
            mvwprintw(win, y_w / 4, x_w / 2, "Play");
        }
        if (ch == 10 && i == 1) return;
        if (ch == 10 && i == 0) {
            game(a->ac, a->av, a); free(a);
            return;
        }
    }
}

void menu_tetris(char **av, int ac, global_t *a)
{
    initscr();
    noecho();
    curs_set(0);
    int y, x, y_w, x_w, ch;
    getmaxyx(stdscr, y, x);
    WINDOW *win = newwin(y / 4, x / 4, y / 8, x / 8);
    keypad(win, true);
    getmaxyx(win, y_w, x_w);
    box(win, 0, 0);
    wattron(win, A_STANDOUT);
    mvwprintw(win, y_w / 4, x_w / 2, "Play");
    wattroff(win, A_STANDOUT);
    mvwprintw(win, y_w / 4 + 1, x_w / 2, "Quit");
    options_menu(ch, win, a);
    endwin();
}
