/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** my_ls
*/

#include "../include/my.h"

int check_which_flag(int ac, char **av)
{
    switch (av[1][1]) {
        case 'l' : ls_l(ac, av); break;
        case 'R' : ls_r_maj(ac, av); break;
        case 'd' : ls_d(ac, av); break;
        case 'r' : ls_r(ac, av); break;
        case 't' : ls_t(ac, av); break;
    }
    return (0);
}

int my_ls(int ac, char **av)
{
    if (ac == 1 || ac > 1 && av[1][0] != '-') {
        my_true_base_ls(ac, av);
        return (0);
    }
    if (av[1][0] == '-') {
        check_which_flag(ac, av);
        return (0);
    }
    return (0);
}
