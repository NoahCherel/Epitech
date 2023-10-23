/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char my_strdup(char const *src)
{
    char *str;
    int len = my_strlen(src);
    int i;
    str = malloc(sizeof(src));
    i = 0;
    while (i < len) {
        str[i] = src[i];
        i = i + 1;
    }
    return (str);
}
