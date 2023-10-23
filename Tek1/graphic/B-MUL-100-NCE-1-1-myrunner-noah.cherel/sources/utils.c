/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** utils
*/

#include "../include/my.h"

void my_help(int ac, char **av)
{
    if (av[1][0] == 'h' || av[1][1] == 'h') {
        my_putstr("My Runner : Epitech Project where you must make a game");
        my_putchar(' ');
        my_putstr("like geometry dash with obstacles and such in a parralax.");
        my_putchar('\n');
        my_putstr("USAGE :");
        my_putchar('\n');
        my_putstr("Use arrow to move (up to jump, etc...) and space to pause");
        my_putchar('\n');
        my_putstr("1 on the map is the monster");
        my_putchar('\n');
    }
}

void music_toplay(global_t *obj)
{
    obj->Music = sfMusic_createFromFile("chill.ogg");
    sfMusic_setVolume(obj->Music, 10);
    sfMusic_play(obj->Music);
}

gravity_t *set_gravity(gravity_t *g)
{
    g = malloc(sizeof(gravity_t));
    g->velocityY = 0;
    g->velocityX = 0;
    g->gravity = 1;
    return (g);
}

clocks_t *set_clock(clocks_t *cl)
{
    cl = malloc(sizeof(clocks_t));
    cl->clock = sfClock_create();
    cl->time;
    cl->tmp = 0;
    cl->win = sfFalse;
    cl->pause = sfFalse;
    return (cl);
}

void display_all(global_t *obj)
{
    sfRenderWindow_drawSprite(obj->window, obj->p->far, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->p->back, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->p->Forefront, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->g->c->s, NULL);
    sfRenderWindow_drawSprite(obj->window,obj->c->sprite, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->c->health, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->g->monster->m, NULL);
}
