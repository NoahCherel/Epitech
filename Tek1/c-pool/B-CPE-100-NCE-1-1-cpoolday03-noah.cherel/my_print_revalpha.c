/*
** EPITECH PROJECT, 2021
** my_print_revalpha
** File description:
** task02
*/
#include <unistd.h>

int my_print_revalpha(void)
{
    for	(int i = 122; i > 96; --i) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
