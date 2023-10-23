/*
** EPITECH PROJECT, 2023
** Repos
** File description:
** main
*/

#include "../include/panoramix.h"

int nb_vill, pot_size, max_fights, max_refills, servings, refills;
pthread_t druid, *villagers;
pthread_barrier_t barr, barr2;
pthread_mutex_t servings_mutex;
sem_t pot_sem, druid_sem;

void* druid_function(void* arg)
{
    printf("Druid: I'm ready... but sleepy...\n");
    while (max_refills >= 0) {
        sem_wait(&druid_sem);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can ");
        printf("only make %i more refills after this one.\n", max_refills -= 1);
        servings = pot_size;
        if (max_refills == 0) {
            printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
        }
        sem_post(&pot_sem);
    }
    pthread_exit(NULL);
}

void* v_fct(void* arg)
{
    struct VillagerArgs* args = (struct VillagerArgs*) arg; int id = args->id;
    printf("Villager %i: Going into battle!\n", id);
    int nb_fights = args->nb_fights; pthread_barrier_wait(args->barr);
    for (int i = 0; i < nb_fights; i++) { pthread_mutex_lock(&servings_mutex);
        if (servings == 0 && max_refills > 0) {
            printf("Villager %i: I need a drink... I see %i servings left.\n",
            id, servings);
            printf("Villager %i: Hey Pano wake up! We need more potion.\n", id);
            sem_post(&druid_sem); sem_wait(&pot_sem); max_refills--;
        }
        if (servings > 0) {
            printf("Villager %i: I need a drink... I see %i servings left.\n",
            id, servings); servings--;
        }
        pthread_mutex_unlock(&servings_mutex);
        printf("Villager %i: Take that roman scum! Only %i left.\n",
        id, nb_fights - i - 1);
    }
    pthread_barrier_wait(args->barr2);
    printf("Villager %i: I'm going to sleep now.\n", id); pthread_exit(NULL);
}

void clean_up(void)
{
    pthread_barrier_destroy(&barr);
    pthread_barrier_destroy(&barr2);
    pthread_mutex_destroy(&servings_mutex);
    sem_destroy(&pot_sem);
    sem_destroy(&druid_sem);
    free(villagers);
}

void misc(int argc, char *argv[])
{
    nb_vill = atoi(argv[1]);
    pot_size = atoi(argv[2]);
    max_fights = atoi(argv[3]);
    max_refills = atoi(argv[4]);
    servings = pot_size;
    refills = 0;
    pthread_barrier_init(&barr, NULL, nb_vill);
    pthread_barrier_init(&barr2, NULL, nb_vill);
    pthread_mutex_init(&servings_mutex, NULL);
    sem_init(&pot_sem, 0, 0);
    sem_init(&druid_sem, 0, 0);
    return;
}

int main(int argc, char* argv[])
{
    help(argc, argv);
    if (check_args(argv) == 84)
        return (84);
    villagers = malloc(sizeof(pthread_t) * nb_vill);
    pthread_create(&druid, NULL, druid_function, NULL);
    misc(argc, argv);
    for (int i = 0; i < nb_vill; i++) {
        struct VillagerArgs *args = malloc(sizeof(struct VillagerArgs));
        args->id = i;
        args->nb_fights = max_fights;
        args->barr = &barr;
        args->barr2 = &barr2;
        pthread_create(&villagers[i], NULL, v_fct, args);
    }
    for (int i = 0; i < nb_vill; i++)
        pthread_join(villagers[i], NULL);
    clean_up() ;return 0;
}
