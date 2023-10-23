/*
** EPITECH PROJECT, 2021
** my_print_comb2
** File description:
** task06
*/
#include <unistd.h>

int chiffre(int d)
{
    int chiffre1;
    int chiffre2;

    if (d  > 9) {
        chiffre1 = d / 10;
	chiffre2 = d % 10;
        my_putchar(chiffre1 + 48);
        my_putchar(chiffre2 + 48);
    } else {
	my_putchar('0');
        my_putchar(d + 48);
    }
}

int my_print_comb2(void)
{
    int duo1;
    int duo2;

    duo1 = 0;
    while (duo1 <= 99) {
        duo2 = duo1 + 1;
        while (duo2 <= 99) {
            chiffre(duo1);
            my_putchar(' ');
            chiffre(duo2);
            if (duo1 < 98 || duo2 < 99) {
                my_putchar(',');
                my_putchar(' ');
            }
            ++duo2;
        }
        ++duo1;
    }
    my_putchar('\n');
}
