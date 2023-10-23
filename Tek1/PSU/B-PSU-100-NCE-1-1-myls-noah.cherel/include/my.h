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
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#ifndef HEADER_H
    #define HEADER_H

void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
char *my_strcat(char *dest, char *src);
int my_ls(int ac, char **av);
int my_ls_multiple(int ac, char **av);
int ls_l(int ac, char **av);
int ls_r_maj(int ac, char **av);
int ls_d(int ac, char **av);
int ls_r(int ac, char **av);
int ls_t(int ac, char **av);
void permissions(struct stat st);
int my_ls_l(char *file);
int my_ls_l_multiple(int ac, char **av);
int simple_ls(int ac, char **av);
int my_true_base_ls(int ac, char **av);
int check_which_flag(int ac, char **av);
int main(int ac, char **av);

#endif
