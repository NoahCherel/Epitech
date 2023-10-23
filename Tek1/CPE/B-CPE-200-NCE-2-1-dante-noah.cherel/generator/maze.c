/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** maze
*/

#include "../include/my.h"

int create_map(maze_t *maze)
{
    maze->tab = malloc(sizeof(char *) * maze->y + 1);
    int x_width = 0, y_width = 0;
    while (y_width < maze->y) {
        maze->tab[y_width] = malloc(sizeof(char *) * maze->x + 1);
        while (x_width < maze->x) {
            maze->tab[y_width][x_width] = 'X';
            x_width++;
        }
        x_width = 0, y_width++;
    }
    maze->tab[y_width] = '\0';
    path(maze);
    algo(maze);
}

int path(maze_t *maze)
{
    int y_width = 0, x_width = 0;
    while (y_width != maze->y) {
        while (x_width != maze->x) {
            maze->tab[0][x_width] = '*';
            maze->tab[y_width][0] = '*';
            x_width = x_width + 1;
        }
        x_width = 0, y_width++;
    }
}

int algo(maze_t *maze)
{
    int random = 0, y = 2, x = 2;
    while (y <= maze->y - 1) {
        while (x <= maze->x - 1) {
            maze->tab[y][x] = '*';
            random = rand() % 2 + 1;
            (random == 1) ? maze->tab[y][x - 1] = '*': 0;
            (random == 2) ? maze->tab[y - 1][x] = '*': 0;
            x = x + 2;
        }
        x = 2, y = y + 2;
    }
    if (maze->x % 2 == 0 && maze->y % 2 == 0 || maze->x > maze->y) {
        int x_width = 2, random = 0;
        while (x_width <= maze->x - 1) {
            maze->tab[maze->y - 1][x_width] = '*';
            x_width = x_width + 2;
        }
        maze->tab[maze->y - 1][maze->x - 1] = '*';
    }
}
