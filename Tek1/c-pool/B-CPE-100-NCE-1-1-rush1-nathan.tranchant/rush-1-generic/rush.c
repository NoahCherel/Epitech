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

int corner(int x, int y, int i, int j, char hg,
    char hd, char bg, char bd, char line)
{
    if ((i == 0) && (j == 0)) {
        my_putchar(hg);
        return (1);
    }
    if ((i == 0) && (j == x - 1)) {
        my_putchar(hd);
        return (1);
    }
    if ((i == y - 1) && (j == 0)) {
        my_putchar(bg);
        return (1);
    }
    if ((i == y - 1) && (j == x - 1)) {
        my_putchar(bd);
        return (1);
    }
    return (0);
}

void draw(int x, int y, int i, int j, char hg,
    char hd, char bg, char bd, char line)
{
    int wrote = 0;
    if ((y > 1) && (x > 1)) {
        int temp_wrote = corner(x, y, i, j, hg, hd, bg, bd, line);
        if (temp_wrote == 1)
            wrote = 1;
    }
    if (wrote == 0) {
        if ((i == 0) || (j == 0) || (i == y - 1) || (j == x - 1)) {
            my_putchar(line);
        } else {
            my_putchar(32);
        }
    }
}

void create_square(int x, int y, char hg, char hd, char bg, char bd, char line)
{
    int i, j;
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            draw(x, y, i, j, hg, hd, bg, bd, line);
        }
        my_putchar('\n');
    }
}

void rush_generic(int x, int y, char hg, char hd, char bg, char bd, char line)
{
    if ((x <= 0) || (y <= 0)) {
        my_putstr("Invalid size");
        my_putchar('\n');
    } else {
        create_square(x, y, hg, hd, bg, bd, line);
    }
}
