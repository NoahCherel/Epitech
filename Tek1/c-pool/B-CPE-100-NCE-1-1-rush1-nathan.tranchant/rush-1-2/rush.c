/*
** EPITECH PROJECT, 2021
** RUSH 1-2
** File description:
** 1-2 file
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void disp_char(int x, int y, int i, int j)
{
    int wrote = 0;
    if ((y > 1) && (x > 1)) {
        if (((i == 0) && (j == 0)) || ((i == y - 1) && (j == x - 1))) {
            my_putchar(47);
            wrote = 1;
        }
        if (((i == 0) && (j == x - 1)) || ((i == y - 1) && (j == 0))) {
            my_putchar(92);
            wrote = 1;
        }
    }
    if (wrote == 0) {
        if ((i == 0) || (j == 0) || (i == y - 1) || (j == x - 1)) {
            my_putchar(42);
        } else {
            my_putchar(32);
        }
    }
}

void create_square(int x, int y)
{
    int i, j;
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            disp_char(x, y, i, j);
        }
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if ((x <= 0) || (y <= 0)) {
        my_putstr("Invalid size");
        my_putchar('\n');
    } else {
        create_square(x, y);
    }
}
