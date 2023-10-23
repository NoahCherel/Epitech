/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** quest2
*/

#include "rpg.h"

void win_mnu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(REMINDER, NULL);
    sfVector2f pos = {1000, 220};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.0});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}
