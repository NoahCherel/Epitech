/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it
** File description:
** task01
*/
#include <unistd.h>

int my_compute_factorial_it(int nb)
{
    int base = nb;
    if (nb == 0) {
        return (1);
    }
    if (nb < 0 || nb > 12) {
        return (0);
    }
    while (nb > 1) {
        base = base * (nb - 1);
	nb--;
    }
    return (base);
}
