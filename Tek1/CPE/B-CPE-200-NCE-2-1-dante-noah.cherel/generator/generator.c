/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** generator
*/

#include "../include/my.h"

char **imperfect(maze_t *maze)
{
    int y_height = 0, x_width = 0, random = 0;
    while (y_height != maze->y) {
        while (x_width != maze->x) {
            random = rand() % 5 + 1;
            if (maze->tab[y_height][x_width] == 'X' && random == 1)
                maze->tab[y_height][x_width] = '*';
            x_width++;
        }
        x_width = 0, y_height++;
    }
}

int maze_print(maze_t *maze)
{
    int y_height = 0;
    while (maze->tab[y_height] != '\0') {
        printf("%s", maze->tab[y_height]);
        if (maze->tab[y_height + 1] != '\0') printf("%c", '\n');
        y_height++;
    }
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));
    if (ac != 3 && ac != 4) return 84;
    maze->x = atoi(av[1]);
    maze->y = atoi(av[2]);
    if (maze->x <= 0 || maze->y <= 0) return (84);
    srand(time(NULL));
    if (ac == 4) {
        create_map(maze);
        maze_print(maze);
    }
    if (ac == 3) {
        create_map(maze);
        imperfect(maze);
        maze_print(maze);
    }
    free(maze->tab);
    free(maze);
    return (0);
}
