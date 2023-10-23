/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** shop_menu2
*/

#include "rpg.h"

void shop_scene3(global_t *g, scene_t *scene)
{
    scene->items = malloc(sizeof(sfText *) * scene->nb_items + 1);
    scene->items[0] = txt2(vect{810, 100}, 20, "Damage:", FONT);
    scene->items[1] = txt2(vect{810, 123}, 20, "Price:", FONT);
    scene->items[2] = txt2(vect{1012, 100}, 20, "Magic:", FONT);
    scene->items[3] = txt2(vect{1012, 123}, 20, "Defense", FONT);
    scene->items[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
    scene->items[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
    scene->items[6] = txt2(vect{1112, 100}, 20, intoa(g->items->magic), FONT);
    scene->items[7] = txt2(vect{1112, 123}, 20, intoa(g->items->defense),
    FONT);
}
