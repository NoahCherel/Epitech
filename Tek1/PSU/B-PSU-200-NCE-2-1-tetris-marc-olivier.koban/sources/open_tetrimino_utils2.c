/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** open_tetrimino_utils2
*/

#include "../include/my.h"

int check2(char *str)
{
    int i = 0;
    int cpt = 0;
    while (str[i] != '\n') {
        if (str[i] > '0' && str[i] <= '9') {
            cpt++;
        }
        if (str[i] > '0' && str[i] <= '9' && cpt == 3) {
            return (0);
        }
        i++;
    }
    return (84);
}

int check_content_tetrimino(char *filepath)
{
    int i = 0;
    int j = 0;
    i = check(filepath);
    if (i == 84) {
        return (84);
    }
    i = check2(filepath);
    if (i == 84) {
        return (84);
    }
    return (0);
}

char *print_until_dot(char *str)
{
    int i = 0;
    int j = 0;
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '.') {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

void open_tetriminos(global_t *a)
{
    t_list *list = open_tetriminosk(a);
    a->debug->nb_tetriminos = count_valid(list);
    sort_list(list);
    print_list(list);
    free_list(list);
}

int count_valid(t_list *list)
{
    t_list *tmp = list;
    int cpt = 0;
    while (tmp != NULL) {
        if (check_tetrimino(tmp->full_name) == 0) {
            cpt++;
        }
        tmp = tmp->next;
    }
    return (cpt);
}
