/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** deplacement.c
*/

#include "../include/my.h"

void deplacement_left(global_t *a)
{
    if (a->x_arr_tetr > 1) {
        a->x_tetris -= 1;
        a->x_arr_tetr -= 1;
    }
}

void deplacement_right(global_t *a)
{
    if (a->x_arr_tetr < a->debug->row - 1) {
        a->x_tetris += 1;
        a->x_arr_tetr += 1;
    }
}
