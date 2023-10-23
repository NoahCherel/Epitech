/*
** EPITECH PROJECT, 2021
** my_computer_power_it
** File description:
** task03
*/
#include <unistd.h>

int my_compute_power_it(int nb, int p)
{
    int res = 1;
    if (nb == 0) {
        return (1);
    if (p < 0) {
        return (0);
    }
    for (int i = 1; i =< p; --p) {
        res = res * nb;
    }
    return (res);
}
