/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** tower
*/

#include "../include/my.h"

void init_tower1(global_t *a)
{
    for (int i = 0; i < 6; i++) {
        a->tower1[i].clock = sfClock_create();
        a->tower1[i].sprite = sfSprite_create();
        a->tower1[i].texture = sfTexture_createFromFile("img/tur1.png", NULL);
        sfSprite_setTexture(a->tower1[i].sprite, a->tower1[i].texture, sfTrue);
    }
}

void t1_placement(global_t *a, sfVector2f *turret_position)
{
    if (a->placement == 1 && a->money->money >= 100 &&
    turret_position->x >= 0 && turret_position->x <= 1300 &&
    turret_position->y >= 320) {
        a->tower1[a->nb_t1].position = *turret_position;
        sfSprite_setPosition(a->tower1[a->nb_t1].sprite,
        a->tower1[a->nb_t1].position);
        a->nb_t1++;
        a->money->money -= 100;
        sfText_setString(a->money->text, my_inttostr(a->money->money));
        a->placement = 0;
    }
}

void range_tower1(global_t *a, int i)
{
    int rand = rande(4, 0);
    for (int y = 0; y < a->nb_enemy1; ++y) {
        a->pos1x = a->tower1[i].position.x;
        a->postx = a->enemy1[y].xy.x - 50;
        a->pos1y = a->tower1[i].position.y;
        a->posty = a->enemy1[y].xy.y - 50;
        if (a->postx < a->pos1x + 150 && a->postx > a->pos1x - 250 &&
        a->posty < a->pos1y + 150 && a->posty > a->pos1y - 250 &&
        a->enemy1[y].hp > 0) {
            a->enemy1[y].hp -= 1;
            break;
        }
    }
}

void update_tower1(global_t *a)
{
    for (int i = 0; i < a->nb_t1; i += 1) {
        a->tower1[i].time1 = sfClock_getElapsedTime(a->tower1[i].clock);
        float sec = a->tower1[i].time1.microseconds / 1000000.0;
        if (sec > 0.5) {
            range_tower1(a, i);
            sfClock_restart(a->tower1[i].clock);
        }
    }
    for (int y = 0; y < a->nb_enemy1; ++y) {
        if (a->enemy1[y].alive == sfTrue && a->enemy1[y].hp <= 0) {
            a->money->money += 25;
            a->enemy1[y].alive = sfFalse;
            sfText_setString(a->money->text, my_inttostr(a->money->money));
        }
    }
}
