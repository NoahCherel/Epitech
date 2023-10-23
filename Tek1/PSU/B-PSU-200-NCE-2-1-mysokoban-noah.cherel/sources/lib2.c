/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** lib2
*/

#include "../include/my.h"

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(*array) * my_strlen(str) + 1);
    int i = 0, j = 0, k = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') for (; str[i] == '\n'; i++, j++, k = 0);
        array[j] = malloc(my_strlen(str) * sizeof(**array));
        for (; str[i] != '\n' && str[i] != '\0'; k++, i++)
            array[j][k] = str[i];
    }
    array[j + 1] = NULL;
    return (array);
    free(array);
}

int invalid_map(char *map, mape_t *a)
{
    int i = 0, p = 0, c = 0;
    while (i != my_strlen(map)) {
        if (map[i] == 'P')
            p += 1;
        if (map[i] == 'O')
            a->o += 1;
        if (map[i] == 'X')
            c += 1;
        i++;
    }
    if (p != 1 || a->o != c)
        return (84);
    return (0);
}

int *mem_pos_o(char **map, mape_t *a)
{
    int j = 0, x = 0, *tab = malloc(sizeof(int) * (a->o * 2));
    for (int i = 0; map[i] != NULL; i = i + 1) {
        for (j = 0; j != my_strlen(map[i]); j = j + 1) {
            if (map[i][j] == 'O') {
                tab[x] = i; tab[x + 1] = j; x = x + 2;
            }
        }
    }
    return (tab);
}

int count(char **map)
{
    int nb = 0, i = 0, j = 0;
    for (int i = 0; map[i] != NULL; i = i + 1) {
        for (j = 0; j != my_strlen(map[i]); j = j + 1) {
            if (map[i][j] == 'O') {
                nb++;
            }
        }
    }
    return (nb);
}

void pos_o(char **map, int *tab, int nb_o)
{
    for (int i = 0; i != nb_o * 2; i += 2) {
        if (map[tab[i]][tab[i + 1]] == ' ')
            map[tab[i]][tab[i + 1]] = 'O';
        if (map[tab[i]][tab[i + 1]] == 'X' && count(map) == 0) {
            endwin();
            exit(0);
        }
    }
}
