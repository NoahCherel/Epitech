/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** isneg
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int nb)
{
    if (nb  >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
    return (0);
}
