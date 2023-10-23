/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** My_hunter
*/

#include "../include/my.h"

void execution(global_t *global)
{
    while_open(global);
}

void init_map(global_t *a)
{
    a->map->name_map = "sources/map";
    a->map->map_array = txttoint(a->map->name_map);
    int x = count_line(a) * count_collums(a);
    a->map->map_2d = malloc(a->map->nbr_line * sizeof(a->map->map_2d));
    for (int i = 0; i < a->map->nbr_line; i++) {
        a->map->map_2d[i] = malloc(a->map->nbr_col * sizeof(**a->map->map_2d));
    }
    array_to_2d(a->map->map_2d, a->map->map_array, a->map->nbr_line);
    a->map->list = malloc(a->map->nbr_line * sizeof(a->map->list));
    for (int i = 0; i < a->map->nbr_line; i++) {
        a->map->list[i] = malloc(a->map->nbr_col * sizeof(**a->map->list));
    }
    conversion_int(a);
}

void preparation(void)
{
    global_t *global = malloc(sizeof(global_t));
    global = fill_global(global);
    sfRenderWindow_setFramerateLimit(global->window->window, 60);
    sfRenderWindow_setMouseCursorVisible(global->window->window, sfFalse);
    sfRenderWindow_setKeyRepeatEnabled(global->window->window, sfFalse);
    sfMusic_play(global->music->music_menu);
    init_map(global);
    init_mob1(global);
    init_tower1(global);
    global->path = set_path(global);
    global->pos->bool_sound = sfFalse;
    execution(global);
    free_all(global);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help(ac, av);
        return (0);
    }
    preparation();
    return (0);
}
