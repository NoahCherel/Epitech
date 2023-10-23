/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Function that concatenates two strings
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int itr = 0, len = my_strlen(dest);

    for (itr; src[itr] != '\0'; itr++)
        dest[len + itr] = src[itr];
    dest[len + itr] = '\0';
    return (dest);
}
