/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** task07
*/
#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb < '0') {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb == -2147483648) {
        my_putchar("2147483648");
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
