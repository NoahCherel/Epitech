/*
** EPITECH PROJECT, 2021
** MY H
** File description:
** Contains all prototypes
*/

#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct maze_s
{
    int x;
    int y;
    char **tab;
} maze_t;

void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int create_map(maze_t *maze);
int path(maze_t *maze);
int algo(maze_t *maze);

#ifndef MY_H_
    #define MY_H_

#endif
