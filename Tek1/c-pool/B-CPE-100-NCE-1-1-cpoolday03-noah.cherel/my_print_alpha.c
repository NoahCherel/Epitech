/*
** EPITECH PROJECT, 2021
** print_alpha
** File description:
** task01
*/
#include <unistd.h>

int my_print_alpha(void)
{
    for (int i = 97; i < 123; ++i) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
