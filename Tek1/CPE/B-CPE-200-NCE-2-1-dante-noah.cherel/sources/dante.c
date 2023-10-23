/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** My_hunter
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help(ac, av);
        return (0);
    }
    return (0);
}
