/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ennemy_wave
*/

#include "../include/my.h"

int find_beginning(global_t *a)
{
    char b; int y;
    for (y = 0; y != a->map->nbr_col; y++) {
        b = a->map->map_2d[0][y];
        if (b == '2') {
            return (y);
        }
    }
}

void init_mob1(global_t *a)
{
    int tile_pos = find_beginning(a);
    for (int i = 0; i < 100; ++i) {
        a->enemy1[i].frame.width = 75; a->enemy1[i].frame.height = 75;
        a->enemy1[i].frame.top = 0; a->enemy1[i].frame.left = 0;
        a->enemy1[i].xy.x = 0;
        a->enemy1[i].xy.y = tile_pos * a->map->height + 320;
        a->enemy1[i].hp = 3;
        a->enemy1[i].alive = sfTrue;
        a->enemy1[i].clock = sfClock_create();
        a->enemy1[i].texture =
        sfTexture_createFromFile("img/Enemies/enemyBlack1.png" ,NULL);
        a->enemy1[i].sprite = sfSprite_create();
        sfSprite_setTexture(a->enemy1[i].sprite, a->enemy1[i].texture, sfTrue);
        sfSprite_setPosition(a->enemy1[i].sprite, a->enemy1[i].xy);
    }
}

void reset_mob(global_t *a)
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
        sfSprite_setPosition(a->enemy1[i].sprite, a->enemy1[i].xy);
    }
}

void endwavedetec(global_t *a)
{
    if (a->waveEnded == sfFalse) {
        a->waveEnded = sfTrue;
        for (int i = 0; i < a->nb_enemy1; ++i) {
            (a->enemy1[i].hp > 0) ? a->waveEnded = sfFalse : 0;
        }
        if (a->waveEnded == sfTrue) {
            (a->nb_enemy1 != 0) ? reset_mob(a) : 0;
            a->nb_enemy1 = 0;
        }
    }
}

void spawn(global_t *a)
{
    endwavedetec(a);
    if (a->waveEnded == sfTrue) {
        a->clds = sfClock_getElapsedTime(a->clocl);
        float sec = a->clds.microseconds / 1000000.0;
        if (sec > 0.1) {
            (a->spawn > 0) ? a->spawn-- : 0;
            (a->spawn == 0) ? ++a->nb_enemy1, a->spawn = rande(10, 1) : 0;
            sfClock_restart(a->clocl);
        }
    }
    for (; a->waveEnded == sfTrue && a->nb_enemy1 == a->nb_wave * 2;
    a->nb_wave++)
        a->waveEnded = sfFalse;
}
