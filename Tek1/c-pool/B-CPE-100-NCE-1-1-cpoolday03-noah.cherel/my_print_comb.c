/*
** EPITECH PROJECT, 2021
** my_print_comb
** File description:
** task05
*/
#include <unistd.h>

int my_print_comb(void)
{
    for (int a = 48; a <= 57; ++a) {
        for (int b = a + 1; b <= 57; ++b) {
            for (int c = b + 1;c <= 57; ++c) {
                my_putchar(a);
                my_putchar(b);
                my_putchar(c);
                if ((a != 55) || (b != 56) || (c != 57)) {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }
    }
    my_putchar('\n');
}
