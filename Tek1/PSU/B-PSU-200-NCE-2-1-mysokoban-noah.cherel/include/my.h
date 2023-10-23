/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

#ifndef HEADER_H
    #define HEADER_H

typedef struct mape_s {
    int x;
    int o;
} mape_t;

void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
char **my_str_to_word_array(char const *str);
void my_help(int ac, char **av);
int my_show_word_array(char **tab);
int move1(int key, char **map, mape_t *a);
int invalid_map(char *map, mape_t *a);
int *mem_pos_o(char **map, mape_t *a);
void pos_o(char **map, int *tab, int nb_o);

#endif
