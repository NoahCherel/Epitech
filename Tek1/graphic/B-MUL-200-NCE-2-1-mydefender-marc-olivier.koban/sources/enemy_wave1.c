/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** enemy_wave1
*/

#include "../include/my.h"

int rande(int max, int min)
{
    int nb = (rand() % max) + min;
    return nb;
}

void scene1(global_t *a)
{
    spawn(a);
    for (int i = 0; i < a->nb_enemy1; i++) {
        sfSprite_setTextureRect(a->enemy1[i].sprite, a->enemy1[i].frame);
        if (a->enemy1[i].hp > 0)
            sfRenderWindow_drawSprite(a->window->window, a->enemy1[i].sprite,
            NULL);
        if (a->enemy1[i].xy.x > 1200) {
            path_x(a); path_y(a);
            sfSprite_setPosition(a->enemy1[i].sprite, a->enemy1[i].xy);
            a->enemy1[i].hp--;
        }
        sfClock_restart(a->enemy1[i].clock);
    }
    for (int i = 0; i < a->nb_t1; i++)
        sfRenderWindow_drawSprite(a->window->window, a->tower1[i].sprite,
        NULL);
}

void reset_mob_pause(global_t *a)
{
    int tile_pos = find_beginning(a);
    for (int i = 0; i < a->nb_enemy1; ++i) {
        a->enemy1[i].frame.width = 75;
        a->enemy1[i].frame.height = 75;
        a->enemy1[i].frame.top = 0;
        a->enemy1[i].frame.left = 0;
        a->enemy1[i].xy.y = tile_pos * a->map->height + 320;
        a->enemy1[i].xy.x = 0;
        a->enemy1[i].hp = 3;
        a->enemy1[i].alive = sfTrue;
    }
    a->nb_enemy1 = 0;
    a->nb_wave = 1;
    a->nb_t1 = 0;
}
