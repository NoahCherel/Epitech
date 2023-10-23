/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

int exec_cmd(char *str)
{
    my_putstr(str, 1);
    str = get_next_line(0);
    if (detect_track_end(str) == 1) return (1);
    return (0);
}
