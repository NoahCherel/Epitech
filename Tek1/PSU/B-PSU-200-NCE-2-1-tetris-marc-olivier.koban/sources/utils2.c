/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** utils2.c
*/

#include "../include/my.h"

void clear_tetris(global_t *a)
{
    int o = a->y_arr_tetr + 2;
    int j = a->y_arr_tetr - 1;
    int f = a->descente;
    move(f - 1, a->x_tetris);
    for (j; j < o; j++) {
        for (int m = 0; m < 2; m++) {
            a->tetris[j][a->x_arr_tetr + m] = ' ';
            printw("%c", a->tetris[j][a->x_arr_tetr + m]);
        }
        f += 1;
        move(f - 1, a->x_tetris);
    }
}

void deplacement_tetri(global_t *a)
{
    move(a->descente, a->x_tetris);
    for (int m = 0; m < 3; m++) {
        move(a->descente, a->x_tetris);
        for (int k = 0; k < 2; k++) {
            a->tetris[a->y_arr_tetr][a->x_arr_tetr] = a->tetrimino[m][k];
            (a->tetris[a->y_arr_tetr][a->x_arr_tetr] == '*') ?
            printw("%c", a->tetris[a->y_arr_tetr][a->x_arr_tetr]) : 0;
            a->x_arr_tetr += 1;
        }
        a->y_arr_tetr += 1; a->x_arr_tetr -= 2; a->descente += 1;
    }
    a->descente -= 2; a->y_arr_tetr -= 2;
    condition_end(a);
}

void malloc_tetrimino(global_t *a)
{
    a->tetrimino = malloc(sizeof(char *) * 3);
    for (int x = 0; x < 3; x++) {
        a->tetrimino[x] = malloc(sizeof(char) * 2);
    }
    for (int m = 0; m < 2; m++) {
        for (int k = 0; k < 1; k++) {
            a->tetrimino[m][k] = '*';
        }
    }
    a->tetrimino[2][0] = '*';
    a->tetrimino[2][1] = '*';
}

void end_list(global_t *a)
{
    a->descente = 1;
    a->x_tetris = 21 + a->debug->row / 2 - 1;
    a->x_arr_tetr = a->debug->row / 2;
    move(a->descente, a->x_tetris);
    a->y_arr_tetr = 0;
}

void deplacement(int ch, global_t *a)
{
    if (ch == a->debug->left) {
        deplacement_left(a);
    }
    if (ch == a->debug->right) {
        deplacement_right(a);
    }
}
