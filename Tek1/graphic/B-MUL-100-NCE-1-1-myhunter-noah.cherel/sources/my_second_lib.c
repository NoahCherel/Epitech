/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_second_lib
*/

#include "../include/my.h"

void drawsprite(sfRenderWindow *window, sfSprite *background, sfSprite *Bird,
sfSprite *CursorSprite, sfVector2f pos_scope)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, Bird, NULL);
    sfSprite_setPosition(CursorSprite, pos_scope);
    sfRenderWindow_drawSprite(window, CursorSprite, NULL);
}

void render_draw(global_t *a)
{
    sfRenderWindow_drawSprite(a->window, a->background->background, NULL);
    sfRenderWindow_drawSprite(a->window, a->bird->bird, NULL);
    sfSprite_setPosition(a->cursor->cursor, a->cursor->pos);
    sfRenderWindow_drawSprite(a->window, a->cursor->cursor, NULL);
    sfRenderWindow_drawSprite(a->window, a->background->cloud, NULL);
}

void utils(global_t *a)
{
    a->cursor->pos.x = sfMouse_getPositionRenderWindow(a->window).x - 68;
    a->cursor->pos.y = sfMouse_getPositionRenderWindow(a->window).y - 68;
    a->clo->time = sfClock_getElapsedTime(a->clo->clock);
    a->clo->tmp = sfTime_asMilliseconds(a->clo->time);
    analyse_events1(a);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value) rect->left = 0;
}

void utils1(global_t *a)
{
    if (a->cursor->pos.x > a->bird->pos.x && a->cursor->pos.x <
        a->bird->pos.x + 150 && a->cursor->pos.y > a->bird->pos.y &&
        a->cursor->pos.y < a->bird->pos.y + 300) {
            a->bird->pos.x = rand()%10 - 500;
            a->bird->pos.y = rand()% 500; a->score2++;
        }
        if (a->background->pos.x > 1600 || a->background->pos.y > 900) {
            a->background->pos.x = rand()% 500;
            a->background->pos.y = rand()% 500;
        }
        if (a->bird->pos.x > 1600 || a->bird->pos.y > 900)
            a->bird->pos.x = rand()% 10, a->bird->pos.y = rand()% 500;
}
