/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** task04
*/
#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    if (power < 0) {
        return (1);
    }
    if (nb == 0) {
        return (0);
    }
    p = p - 1;
    nb = nb * my_compute_power_rec(nb, p - 1);
    return (nb);
}
