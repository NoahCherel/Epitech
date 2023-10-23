/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** function_struct1 my_defender
*/

#include "../include/my.h"

window_t *set_window(window_t *window)
{
    window = malloc(sizeof(window_t));
    return (window);
}

void *set_sprite2(sprite_t *sprite)
{
    sfTexture *font_sprite = sfTexture_createFromFile("img/a.png", NULL);
    sfTexture *sound_on = sfTexture_createFromFile("img/sound_on.png", NULL);
    sfTexture *sound_off = sfTexture_createFromFile("img/sound_off.png", NULL);
    sfTexture *back = sfTexture_createFromFile("img/back.png", NULL);
    sfTexture *pause = sfTexture_createFromFile("img/pause.png", NULL);
    sfTexture *life = sfTexture_createFromFile("img/life.png", NULL);
    sfTexture *quit = sfTexture_createFromFile("img/quit.jpg", NULL);
    sfTexture *play = sfTexture_createFromFile("img/play.jpg", NULL);
    sfTexture *tuto = sfTexture_createFromFile("img/tutorial.png", NULL);
    sfSprite_setTexture(sprite->image_menu, font_sprite, sfTrue);
    sfSprite_setTexture(sprite->sound_on, sound_on, sfTrue);
    sfSprite_setTexture(sprite->sound_off, sound_off, sfTrue);
    sfSprite_setTexture(sprite->back, back, sfTrue);
    sfSprite_setTexture(sprite->pause, pause, sfTrue);
    sfSprite_setTexture(sprite->life, life, sfTrue);
    sfSprite_setTexture(sprite->quit, quit, sfTrue);
    sfSprite_setTexture(sprite->play, play, sfTrue);
    sfSprite_setTexture(sprite->tuto, tuto, sfFalse);
}

sprite_t *set_sprite(sprite_t *sprite)
{
    sprite = malloc(sizeof(sprite_t));
    sprite->image_menu = sfSprite_create();
    sprite->sound_on = sfSprite_create();
    sprite->sound_off = sfSprite_create();
    sprite->back = sfSprite_create();
    sprite->pause = sfSprite_create();
    sprite->life = sfSprite_create();
    sprite->quit = sfSprite_create();
    sprite->play = sfSprite_create();
    sprite->tuto = sfSprite_create();
    set_sprite2(sprite);
    sfVector2f pos_fond = {0, 0};
    return (sprite);
}

event_t *set_event(event_t *events)
{
    events = malloc(sizeof(event_t));
    return (events);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value) rect->left = 0;
}
