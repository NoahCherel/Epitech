/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** item_description
*/

#include "rpg.h"

void item_desc_menu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/item_desc.png", NULL);
    sfVector2f pos = {800, 100};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.0});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}

items_t *init_stats_item(global_t *g)
{
    g->items = malloc(sizeof(items_t));
    g->items->damage = 0;
    g->items->defense = 0;
    g->items->magic = 0;
    g->items->price = 0;
    return (g->items);

}

void item_description_2(struct scene_s scene, global_t *g)
{
    if (BTN_HOVER[3].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 35; g->items->price = 25;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    } else if (BTN_HOVER[4].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 40; g->items->price = 30;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    } else if (BTN_HOVER[5].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 45; g->items->price = 35;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    }
}

void item_description(struct scene_s scene, global_t *g)
{
    if (BTN_HOVER[0].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 20; g->items->price = 10;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    } else if (BTN_HOVER[1].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 25; g->items->price = 15;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    } else if (BTN_HOVER[2].rect, WINDOW->window)) {
        item_desc_menu(g); g->items->damage = 30; g->items->price = 20;
        ITEM[4] = txt2(vect{910, 100}, 20, intoa(g->items->damage), FONT);
        ITEM[5] = txt2(vect{910, 123}, 20, intoa(g->items->price), FONT);
        for (int i = 0; i < scene.nb_items; i++) drawtxt(WIN, ITEM[i], NULL);
    }
    item_description_2(scene, g);
}
