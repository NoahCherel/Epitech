/*
** EPITECH PROJECT, 2021
** my_print_digits
** File description:
** task03
*/
#include <unistd.h>

int my_print_digits(void)
{
    for	(char i = '0'; i <= '9'; ++i) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
