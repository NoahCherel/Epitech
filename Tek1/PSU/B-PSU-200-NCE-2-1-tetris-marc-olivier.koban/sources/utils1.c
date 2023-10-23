/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** utils1.c
*/

#include "../include/my.h"

void init_color_game(void)
{
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
}

void print_set(global_t *a)
{
    initscr();
    start_color();
    print_tetris();
    print_board();
    print_scoreboard(a);
    print_tetris_bord(a);
    print_next(a);
}

int getch_nostop(void)
{
    int c;
    nodelay(stdscr, TRUE);
    c = getch();
    nodelay(stdscr, FALSE);
    return (c);
}

void clock_score(global_t *a)
{
    keypad(stdscr, TRUE);
    clock_t stopclock = clock() + 1 * CLOCKS_PER_SEC;
    refresh();
    int x = 14;
    while (a->timer != x) {
        if (clock() > stopclock) {
            stopclock += 1 * CLOCKS_PER_SEC;
            a->timer++;
            (a->y_arr_tetr != 0) ? clear_tetris(a) : 0;
            int ch = getch_nostop();
            (ch != -1) ? deplacement(ch, a) : 0;
            if (ch == a->debug->quit) return;
            deplacement_tetri(a);
            print_scoreboard(a);
            (ch == 259) ? a->timer = 14 : 0;
            refresh();
        }
    }
}
