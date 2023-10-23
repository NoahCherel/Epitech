/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for Lem-in project
*/

#include "../include/my.h"

int error(int ac, char **av, char **tab)
{
    if (ac > 2 || (av[1] != NULL && my_strcmp(av[1], "-h") != 0))
        return (84);
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '#' && tab[i][1] == '#'
        && my_strcmp(tab[i], "##start") != 0
        && my_strcmp(tab[i], "##end") != 0)
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    char *line = NULL, *read = NULL;
    size_t len = 0;
    getline(&read, &len, stdin);
    while (getline(&line, &len, stdin) != -1)
        read = my_strcat(read, line);
    if (my_strlen(read) == 0)
        return (84);
    char **tab = my_str_to_word_array(read, '\n');
    if (error(ac, av, tab) == 84)
        return (84);
    parser(tab);

    return (0);
}
