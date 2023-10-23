/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** open_tetrimino_bis
*/

#include "../include/my.h"

int count_files(char *dir)
{
    DIR *d = opendir(dir);
    struct dirent *dir_content;
    int i = 0;
    if (d == NULL) {
        return (84);
    }
    while ((dir_content = readdir(d)) != NULL) {
        if (dir_content->d_name[0] != '.')
            i++;
    }
    closedir(d);
    if (i < 1)
        return (84);
    return (i);
}

int get_first_number(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - '0');
            return (nb);
        } else {
            return (2);
        }
        i++;
    }
    return (nb);
}

int get_second_number(char *str)
{
    int i = 0;
    int nb = 0;
    int cpt = 0;
    while (str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            cpt++;
        }
        if (str[i] >= '0' && str[i] <= '9' && cpt == 2) {
            nb = nb * 10 + (str[i] - '0');
            return (nb);
        }
        i++;
    }
    return (nb);
}

int get_third_number(char *str)
{
    int i = 0;
    int nb = 0;
    int cpt = 0;
    while (str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            cpt++;
        }
        if (str[i] >= '0' && str[i] <= '9' && cpt == 3) {
            nb = nb * 10 + (str[i] - '0');
            return (nb);
        }
        i++;
    }
    return (nb);
}
