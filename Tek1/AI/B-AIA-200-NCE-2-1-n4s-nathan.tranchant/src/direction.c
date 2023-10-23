/*
** EPITECH PROJECT, 2022
** NEED4STEK
** File description:
** ai project
*/

#include "ai.h"

int change_dir(float idx, char *val)
{
    my_putstr("WHEELS_DIR:", 1);
    if (idx < 0.0) my_putstr("-", 1);
    my_putstr(val, 1);
    if (detect_track_end(get_next_line(0)) == 1) return (1);
    return (0);
}

int get_direction(char **tab, float midlight)
{
    float left, right;
    int i = 0;
    left = my_strtof(tab[1]);
    right = my_strtof(tab[31]);
    if (midlight >= 1500)
        i = change_dir(left - right, "0.005\n");
    if (midlight < 1500 && midlight >= 1000)
        i = change_dir(left - right, "0.05\n");
    if (midlight < 1000 && midlight >= 600)
        i = change_dir(left - right, "0.1\n");
    if (midlight < 600 && midlight >= 400)
        i = change_dir(left - right, "0.2\n");
    if (midlight < 400 && midlight >= 200)
        i = change_dir(left - right, "0.3\n");
    if (midlight < 200)
        i = change_dir(left - right, "0.5\n");
    return (i);
}
