/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Function that returns the length of a string
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int len = 0;
    for (len; str[len] != '\0'; len++);
    return (len);
}
