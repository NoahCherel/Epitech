/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** basic_ls
*/

#include "../include/my.h"

int my_ls_multiple(int ac, char **av)
{
    DIR *dir; struct dirent *de; struct stat st; stat(de->d_name, &st);
    int a = 0;
    for (int j = 1; j != ac; j++) if (opendir(av[j]) != NULL) {a++;}
    if (S_ISDIR(st.st_mode))
    for (int i = 1; i != ac; i++) {
        if (opendir(av[i]) != NULL) {
            dir = opendir(av[i]);
            if (a > 1) { my_putstr(av[i]); my_putstr(":\n"); }
            while (de = readdir(dir)) {
                if (de->d_name[0] != '.') {
                    my_putstr(de->d_name); my_putchar('\n');
                }
            }
            if (i != ac - 1 && a > 1) my_putchar('\n'); closedir(dir);
        } else {
            my_putstr(av[i]); my_putchar('\n');
        }
    }
    return (0);
}

int my_true_base_ls(int ac, char **av)
{
    DIR *dir; struct dirent *de; dir = opendir("."); struct stat st;
    if (ac == 1) {
        while ((de = readdir(dir)) != 0)
            if (de->d_name[0] != '.') {
                my_putstr(de->d_name); my_putchar('\n');
            }
        while (de) closedir(dir); return (0);
    } else {
        if (ac > 1)  my_ls_multiple(ac, av);
    }
    return (0);
}
