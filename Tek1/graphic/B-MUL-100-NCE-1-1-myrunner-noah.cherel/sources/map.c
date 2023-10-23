/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** map
*/

#include "../include/my.h"

map_t *set_map(map_t *a)
{
    a = malloc(sizeof(map_t));
    a->nb_coin = 0;
    a->nb_monster = 0;
    a->a = 0;
    return (a);
}

void map_basic(global_t *a, char *file, int fd)
{
    char *buffer = malloc(sizeof(char*) * 100);
    int nb_read = read(fd, buffer, 100);
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '1')
            a->map->nb_coin++;
}
