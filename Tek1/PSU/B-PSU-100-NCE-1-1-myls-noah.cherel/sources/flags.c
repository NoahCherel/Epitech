/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flags
*/

#include "../include/my.h"
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

int ls_l(int ac, char **av)
{
    if (ac == 2) {
        my_ls_l("./");
    } else {
        my_ls_l_multiple(ac, av);
    }
    return (0);
}

int ls_r_maj(int ac, char **av)
{
    return (0);
}

int ls_d(int ac, char **av)
{
    return (0);
}

int ls_r(int ac, char **av)
{
    return (0);
}

int ls_t(int ac, char **av)
{
    return (0);
}
