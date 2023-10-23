/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_lib
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        my_put_nbr(nb);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}

size_t my_strlen(char const *str)
{
    int i = 0;
    if (str[i] == 0)
        return (0);
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]); i = i + 1;
    }
}

char *my_strcat(char *dest, char *src)
{
    int i = 0, j = 0, k = 0;
    char *res = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(char));
    while (dest[i]) {
        res[i] = dest[i]; i++;
    }
    if (dest[my_strlen(dest)] != '/') {
        res[my_strlen(dest)] = '/'; k++;
    }
    while (src[j]) {
        res[i + j + k] = src[j]; j++;
    }
    res[i + j + k] = '\0';
    return (res);
}
