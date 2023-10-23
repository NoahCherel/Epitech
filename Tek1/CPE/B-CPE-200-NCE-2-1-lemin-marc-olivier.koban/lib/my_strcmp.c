/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** Function that compares two strings
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int itr = 0;

    while (s1[itr] != '\0' && s2[itr] != '\0' && s1[itr] == s2[itr])
        itr++;
    return (s1[itr] - s2[itr]);
}
