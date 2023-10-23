/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_lib_4
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int srclen = my_strlen(src);
    int destlen = my_strlen(dest);
    for (i = 0; i < destlen || i < srclen; i++) {
        if (i <= srclen) {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
    }
    return (dest);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[i] = src[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}
