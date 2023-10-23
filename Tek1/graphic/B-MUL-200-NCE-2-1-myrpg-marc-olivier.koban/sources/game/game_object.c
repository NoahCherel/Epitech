/*
** EPITECH PROJECT, 2022
** GAME_OBJECT.C
** File description:
** Intialize game objects
*/

#include "rpg.h"

void init_obj(game_object_t *obj, sfVector2f pos, sfVector2f sz, char *file)
{
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(file, NULL);
    obj->pos = pos;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setScale(obj->sprite, sz);
}
