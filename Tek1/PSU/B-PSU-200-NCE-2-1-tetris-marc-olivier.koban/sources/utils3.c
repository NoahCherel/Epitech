/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** utils3.c
*/

#include "../include/my.h"

void condition_end(global_t *a)
{
    for (int x = 0; x < 2; x++) {
        if (a->y_arr_tetr + 2 == a->debug->col || a->tetris[a->y_arr_tetr + 2]
        [a->x_arr_tetr + x] == '*') {
            end_list(a);
            return;
        }
    }
}

void array_tetris(global_t *a)
{
    a->tetris = malloc(a->debug->col * sizeof(a->tetris));
    for (int x = 0; x < a->debug->col; x++) {
        a->tetris[x] = malloc(a->debug->row * sizeof(a->tetris[x]));
    }
}
