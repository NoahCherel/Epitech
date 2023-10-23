/*
** EPITECH PROJECT, 2023
** Repos
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>

typedef struct VillagerArgs {
    int id;
    int nb_fights;
    pthread_barrier_t* barr;
    pthread_barrier_t* barr2;
} VillagerArgs;

typedef struct panoramix_t {
    int nb_fights;
    int nb_villagers;
    int nb_vill, pot_size, max_fights, max_refills;
    int servings, refills;
} panoramix_t;

int help(int argc, char *argv[]);
void misc(int argc, char *argv[]);
int check_args(char **av);

#endif /* !PANORAMIX_H_ */
