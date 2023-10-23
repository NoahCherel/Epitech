/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** print_default
*/

#include "../include/my.h"

void print_tetris(void)
{
    init_color_game(); attron(COLOR_PAIR(1)); printw("***\n *\n *\n *\n *");
    attroff(COLOR_PAIR(1)); move(0, 3); attron(COLOR_PAIR(2));
    printw("***"); move(1, 3); printw("*"); move(2, 3); printw("**");
    move(3, 3); printw("*"); move(4, 3); printw("***");
    attroff(COLOR_PAIR(2)); move(0, 6); attron(COLOR_PAIR(3));
    printw("***"); move(1, 6); printw(" *"); move(2, 6);
    printw(" *"); move(3, 6); printw(" *"); move(4, 6);
    printw(" *"); move(0, 9); attroff(COLOR_PAIR(3)); attron(COLOR_PAIR(4));
    printw("***"); move(1, 9); printw("* *"); move(2, 9);
    printw("** "); move(3, 9); printw("* *"); move(4, 9);
    printw("* *"); move(0, 12); attroff(COLOR_PAIR(4)); attron(COLOR_PAIR(5));
    printw("*"); move(2, 12); printw("*"); move(3, 12);
    printw("*"); move(4, 12); printw("*"); move(0, 13);
    attroff(COLOR_PAIR(5)); attron(COLOR_PAIR(7)); printw("***"); move(1, 13);
    printw("*"); move(2, 13); printw("***"); move(3, 13);
    printw("  *"); move(4, 13); printw("***"); move(0, 16);
    attroff(COLOR_PAIR(7));
}

void print_board(void)
{
    move(8, 0); attron(COLOR_PAIR(6)); int co = 9;
    for (int x = 0; x < 15; x++) {
        if (x == 0 || x == 14) printw("+");
        else {
            printw("-");
        }
    }
    for (co; co < 16; co++) {
        move(co, 0); printw("|");
        move(co, 14); printw("|");
    }
    move(16, 0);
    for (int x = 0; x < 15; x++) {
        if (x == 0 || x == 14) {
            printw("+");
        } else {
            printw("-");
        }
    }
}

void print_scoreboard(global_t *a)
{
    move(10, 2); printw("Score");
    move(10, 9); printw("%d", a->score);
    move(13, 2); printw("Timer");
    move(13, 9); printw("%d", a->timer);
}

void print_tetris_bord(global_t *a)
{
    move(0, 20);
    for (int x = 0; x < a->debug->row + 2; x++) {
        if (x == 0 || x == a->debug->row + 1) {
            printw("+");
        } else {
            printw("-");
        }
    }
    for (int y = 0; y < a->debug->col; y++) {
        move(y + 1, 20); printw("|");
        move(y + 1, 20 + a->debug->row + 1); printw("|");
    }
    move(a->debug->col + 1, 20);
    for (int z = 0; z < a->debug->row + 2; z++) {
        if (z == 0 || z == a->debug->row + 1) {
            printw("+");
        } else {
            printw("-");
        }
    }
}

void print_next(global_t *a)
{
    int m = 20 + a->debug->row + 5;
    move(0, m);
    for (int x = 0; x < 9; x++) {
        if (x == 0 || x == 8) {
            printw("+");
        } else
            printw("-");
    }
    for (int y = 0; y < 3; y++) {
        move(y + 1, m); printw("|");
        move(y + 1, m + 8); printw("|");
    }
    move(4, m);
    for (int z = 0; z < 9; z++) {
        if (z == 0 || z == 8) printw("+");
        else {
            printw("-");
        }
    }
}
