/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** misc
*/

#include "../include/panoramix.h"

int help(int argc, char *argv[])
{
    if (argc != 5) {
        fprintf(stderr,
        "Usage: %s <nb_vill> <pot_size> <max_fights> <max_refills>", argv[0]);
        exit(84);
    }
    return (0);
}

int check_args(char **av)
{
    char *endptr;
    for (int i = 1; i < 5; i++) {
        long num = strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || num < 1) {
            fprintf(stderr, "Error: Arguments must be positive integers\n");
            return 84;
        }
    }
    return 0;
}
