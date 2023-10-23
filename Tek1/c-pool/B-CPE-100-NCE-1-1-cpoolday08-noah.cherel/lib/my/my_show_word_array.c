/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** word_array
*/
#include <stdlib.h>

int my_putstr(char const *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i;
    for (i = 0; tab[i] != '\0'; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
