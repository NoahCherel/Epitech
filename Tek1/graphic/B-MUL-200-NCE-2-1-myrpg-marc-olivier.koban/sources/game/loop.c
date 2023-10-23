/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** loop
*/

#include "rpg.h"

int game_loop(scene_t *scene, global_t *g)
{
    if (scene->name == GAME) {
        player_update(g, scene);
        return (1);
    }
}

int zone_1_loop(scene_t *scene, global_t *g)
{
    if (scene->name == ZONE_1) {
        player_update(g, scene);
        return (5);
    }
}

int zone_2_loop(scene_t *scene, global_t *g)
{
    if (scene->name == INN) {
        player_update(g, scene);
        return (6);
    }
}

int zone_3_loop(scene_t *scene, global_t *g)
{
    if (scene->name == SHOP) {
        player_update(g, scene);
        return (7);
    }
}

int credits_loop(scene_t *scene, global_t *g)
{
    if (scene->name == CREDITS) {
        scene->objs[0].pos.y -= 2;
        sfSprite_setPosition(scene->objs[0].sprite, scene->objs[0].pos);
        if (scene->objs[0].pos.y <= -3150) {
            closewin(WINDOW->window);
            return (6);
        }
        return (10);
    }
}
