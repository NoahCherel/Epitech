/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** cat
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);
    int len2 = my_strlen(src);
    for (i = 0; i < len2; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';

    return (dest);
}
