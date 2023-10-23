/*
** EPITECH PROJECT, 2022
** PARSER
** File description:
** File parser for lem-in project
*/

#include "../include/my.h"

void remove_comment(char *str, char garbage)
{
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
        else
            break;
    }
    *dst = '\0';
    if (str[my_strlen(str) - 1] == ' ')
        str[my_strlen(str) - 1] = '\0';
}

void parser2(char **tab)
{
    bool tunnel = false;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_tablen(my_str_to_word_array(tab[i], '-')) == 2 && !tunnel)
            my_putstr("#tunnels\n"), tunnel = true;
        my_putstr(tab[i]), my_putstr("\n");
    }
    my_putstr("#moves\n");
}

void parser1(char **tab)
{
    if (my_strcmp(tab[0], "#number_of_ants")) {
        char **newtab = malloc(sizeof(char *) * (my_tablen(tab) + 2));
        int i = 0;
        for (i = 0; tab[i]; i++)
            newtab[i + 1] = tab[i];
        newtab[0] = "#number_of_ants"; newtab[i + 1] = NULL;
        free(tab); tab = newtab;
    }
    if (my_tablen(tab) > 2 && my_strcmp(tab[2], "#rooms")) {
        char **newtab = malloc(sizeof(char *) * (my_tablen(tab) + 2));
        int i = 0;
        for (i = 0; i < 2; i++) newtab[i] = tab[i];
        newtab[2] = "#rooms";
        for (i = 2; tab[i]; i++) newtab[i + 1] = tab[i];
        newtab[i + 1] = NULL; free(tab); tab = newtab;
    }
    parser2(tab);
}

void parser(char **tab)
{
    int j = 0, k = 0;
    for (int i = 0; tab[i]; i++)
        (tab[i][0] == '#' && tab[i][1] != '#') ? k++ : 0;
    char **newtab = malloc(sizeof(char *) * (my_tablen(tab) - k + 1));
    for (int i = 0; tab[i]; i++)
        !(tab[i][0] == '#' && tab[i][1] != '#') ? newtab[j++] = tab[i] : 0;
    newtab[j] = '\0'; free(tab); tab = newtab;
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] != '#' && tab[i][1] != '#')
            remove_comment(tab[i], '#');
    }
    parser1(tab);
}
