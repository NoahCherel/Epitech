/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** movement
*/

#include "../include/my.h"

int move_right(char **map, int i, int j, mape_t *a)
{
    if (map[i][j + 1] == ' ') {
        map[i][j + 1] = 'P'; map[i][j] = ' ';
    }
    if (map[i][j + 1] == 'X' && map[i][j + 2] == ' ') {
        map[i][j] = ' '; map[i][j + 1] = 'P'; map[i][j + 2] = 'X';
    }
    if (map[i][j + 1] == 'X' && map[i][j + 2] == 'O') {
        map[i][j] = ' '; map[i][j + 1] = 'P'; map[i][j + 2] = 'X';
    }
    if (map[i][j + 1] == 'O') {
        map[i][j + 1] = 'P'; map[i][j] = ' '; a->x += 1;
    } else if (a->x > 0) {
        map[i][j] = ' '; map[i][j + 1] = 'P'; a->x = 0;
    }
    return (0);
}

int move_left(char **map, int i, int j, mape_t *a)
{
    if (map[i][j - 1] == ' ') {
        map[i][j - 1] = 'P'; map[i][j] = ' ';
    }
    if (map[i][j - 1] == 'X' && map[i][j - 2] == ' ') {
        map[i][j] = ' '; map[i][j - 1] = 'P'; map[i][j - 2] = 'X';
    }
    if (map[i][j - 1] == 'X' && map[i][j - 2] == 'O') {
        map[i][j] = ' '; map[i][j - 1] = 'P'; map[i][j - 2] = 'X';
    }
    if (map[i][j - 1] == 'O') {
        map[i][j - 1] = 'P'; map[i][j] = ' '; a->x += 1;
    } else if (a->x > 0) {
        map[i][j] = ' '; map[i][j - 1] = 'P'; a->x = 0;
    }
    return (0);
}

int move_down(char **map, int i, int j, mape_t *a)
{
    if (map[i + 1][j] == ' ') {
        map[i + 1][j] = 'P'; map[i][j] = ' ';
    }
    if (map[i + 1][j] == 'X' && map[i + 2][j] == ' ') {
        map[i][j] = ' '; map[i + 1][j] = 'P'; map[i + 2][j] = 'X';
    }
    if (map[i + 1][j] == 'X' && map[i + 2][j] == 'O') {
        map[i][j] = ' '; map[i + 1][j] = 'P'; map[i + 2][j] = 'X';
    }

    if (map[i + 1][j] == 'O') {
        map[i + 1][j] = 'P'; map[i][j] = ' '; a->x += 1;
    } else if (a->x > 0) {
        map[i][j] = ' '; map[i + 1][j] = 'P'; a->x = 0;
    }
    return (0);
}

int move_up(char **map, int i, int j, mape_t *a)
{
    if (map[i - 1][j] == ' ') {
        map[i - 1][j] = 'P'; map[i][j] = ' ';
    }
    if (map[i - 1][j] == 'X' && map[i - 2][j] == ' ') {
        map[i][j] = ' '; map[i - 1][j] = 'P'; map[i - 2][j] = 'X';
    }
    if (map[i - 1][j] == 'X' && map[i - 2][j] == 'O') {
        map[i][j] = ' '; map[i - 1][j] = 'P'; map[i - 2][j] = 'X';
    }
    if (map[i - 1][j] == 'O') {
        map[i - 1][j] = 'P'; map[i][j] = ' '; a->x += 1;
    } else if (a->x > 0) {
        map[i][j] = ' '; map[i - 1][j] = 'P'; a->x = 0;
    }
    return (0);
}

int move1(int key, char **map, mape_t *a)
{
    int i = 0, j = 0;
    for (; map[i][j] != 'P'; j++)
        if (map[i][j] == '\n' || map[i][j] == '\0') {
            i++; j = 0; }
    if (key == 65 && map[i - 1][j] != '#')
        move_up(map, i, j, a);
    if (key == 66 && map[i + 1][j] != '#')
        move_down(map, i, j, a);
    if (key == 67 && map[i][j + 1] != '#')
        move_right(map, i, j, a);
    if (key == 68 && map[i][j - 1] != '#')
        move_left(map, i, j, a);
    return (0);
}
