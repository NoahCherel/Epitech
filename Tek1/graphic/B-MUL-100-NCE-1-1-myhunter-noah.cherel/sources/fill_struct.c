/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** fill_struct
*/

#include "../include/my.h"

bird_t *set_bird(bird_t *bird)
{
    bird = malloc(sizeof(bird_t));
    bird->bird = sfSprite_create();
    bird->text = sfTexture_createFromFile("bird.png",NULL);
    sfSprite_setTexture(bird->bird, bird->text, sfTrue);
    bird->rect.top = 150; bird->rect.left = 0; bird->rect.width = 150;
    bird->rect.height = 150;
    sfSprite_setTextureRect(bird->bird, bird->rect);
    return (bird);
}

background_t *set_background(background_t *background)
{
    background = malloc(sizeof(background_t));
    background->background = sfSprite_create();
    background->text = sfTexture_createFromFile("text_lvl.png",NULL);
    background->cloud = sfSprite_create();
    background->cloud_txt = sfTexture_createFromFile("cloud.png", NULL);
    sfSprite_setTexture(background->background, background->text, sfTrue);
    sfSprite_setTexture(background->cloud, background->cloud_txt, sfTrue);
    return (background);
}

cursor_t *set_cursor(cursor_t *cursor)
{
    cursor = malloc(sizeof(cursor_t));
    cursor->cursor = sfSprite_create();
    cursor->text = sfTexture_createFromFile("scope.png",NULL);
    sfSprite_setTexture(cursor->cursor, cursor->text, sfTrue);
    return (cursor);
}

clocks_t *set_clock(clocks_t *cl)
{
    cl = malloc(sizeof(clocks_t));
    cl->clock = sfClock_create();
    cl->time;
    cl->tmp = 0;
    return (cl);
}

void music_toplay(global_t *obj)
{
    obj->Music = sfMusic_createFromFile("chill.ogg");
    sfMusic_setVolume(obj->Music, 10);
    sfMusic_play(obj->Music);
}
