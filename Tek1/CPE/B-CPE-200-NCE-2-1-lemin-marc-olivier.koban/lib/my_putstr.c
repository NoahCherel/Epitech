/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Function displaying a string
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
}
