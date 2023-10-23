/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec
** File description:
** task02
*/
#include <unistd.h>

int my_compute_factorial_rec(int nb)
{
    int res;    
    if (nb < 0 || nb > 12) {
        return(0);
    }
    if (nb == 0) {
        return (1);
    }
    res = my_compute_factorial_rec(nb - 1) * nb;
    return(res);
}
