/*
** EPITECH PROJECT, 2021
** main
** File description:
** task05
*/
#include <unistd.h>

int my_putchar(char c);

int my_putstr(char const *str);

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
