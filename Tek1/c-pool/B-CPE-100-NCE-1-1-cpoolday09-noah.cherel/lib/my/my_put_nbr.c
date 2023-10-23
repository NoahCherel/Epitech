/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** putnbr
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < '0') {
        my_putchar('-');
        nb = nb * (-1);
        my_putchar(nb);
    } else {
        my_putchar(nb);
    }
}
