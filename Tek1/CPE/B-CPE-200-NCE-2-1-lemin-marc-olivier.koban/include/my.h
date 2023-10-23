/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** Header file for Lem-in project
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

void my_putstr(char const *str);
void my_putstr_error(char const *str);

int my_tablen(char **tab);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

char **my_str_to_word_array(char const *str, char sep);

#endif

#ifndef LEMIN_H_
    #define LEMIN_H_

typedef struct lemin {
    bool ants_printed;
    bool rooms_printed;
    bool start_printed;
    bool end_printed;
    bool tunnels_printed;
} t_lemin;

void parser(char **tab);

#endif
