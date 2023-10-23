/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** my_lib
*/

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
    if (str[i] == 0) return (0);
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

void my_putstr(char const *str)
{
    write(2 ,str, my_strlen(str));
}

char *my_inttostr(int num)
{
    int len = 0; if (num == 0) len++;
    for (int k = num; k != 0; k = k/10, len++);
    char *p = malloc(sizeof(char) * (len + 1));
    p[len] = '\0'; len--;
    for (; len >= 0; len--) {
        p[len] = num % 10 + 48;
        num /= 10;
    }
    return (p);
}
