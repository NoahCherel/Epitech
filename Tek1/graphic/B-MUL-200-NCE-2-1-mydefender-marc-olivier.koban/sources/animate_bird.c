/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** animetedspritefortheaer
*/

#include "../include/my.h"

clock_sprite_t *set_clock139(clock_sprite_t *cl)
{
    cl = malloc(sizeof(clocks_t));
    cl->clock = sfClock_create();
    cl->time;
    cl->tmp = 0;
    return (cl);
}

bird_t *set_bird(bird_t *bird)
{
    bird = malloc(sizeof(bird_t));
    bird->bird = sfSprite_create();
    bird->text = sfTexture_createFromFile("img/bird.png", NULL);
    sfSprite_setTexture(bird->bird, bird->text, sfTrue);
    bird->rect.top = 150; bird->rect.left = 0; bird->rect.width = 150;
    bird->rect.height = 150;
    sfSprite_setTextureRect(bird->bird, bird->rect);
    return (bird);
}

void bird(global_t *a)
{
    a->clock_sprite->time = sfClock_getElapsedTime(a->clock_sprite->clock);
    a->clock_sprite->tmp = sfTime_asMilliseconds(a->clock_sprite->time);
    sfRenderWindow_drawSprite(a->window->window, a->bird->bird, NULL);
    if (a->bird->pos.x > 1600 || a->bird->pos.y > 900)
        a->bird->pos.x = rand() % 10, a->bird->pos.y = rand() % 500;
    if (a->clock_sprite->time.microseconds / 1000000.0 > 0.5) {
        if (a->bird->pos.x < 2000) {
        move_rect(&a->bird->rect, 150, 450); a->bird->pos.x += 150;
        sfSprite_setPosition(a->bird->bird, a->bird->pos);
        }
        sfClock_restart(a->clock_sprite->clock);
        sfSprite_setTextureRect(a->bird->bird, a->bird->rect);
    }
}

void move_rect1(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value) rect->left = 0;
}
