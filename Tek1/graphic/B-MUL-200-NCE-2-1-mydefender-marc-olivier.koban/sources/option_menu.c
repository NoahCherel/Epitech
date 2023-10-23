/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** option_menu
*/

#include "../include/my.h"

void display_option(global_t *a)
{
    paralax(0.02, a);
    sfRenderWindow_drawSprite(a->window->window, a->sprite->image_menu, NULL);
    if (a->pos->bool_sound == sfFalse) {
        sfRenderWindow_drawSprite(a->window->window, a->sprite->sound_on,
        NULL);
    } else {
        sfRenderWindow_drawSprite(a->window->window, a->sprite->sound_off,
        NULL);
    }
    sfRenderWindow_drawSprite(a->window->window, a->sprite->back, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->sprite2->test, NULL);
    sfRenderWindow_drawText(a->window->window, a->text->fps_30, NULL);
    sfRenderWindow_drawText(a->window->window, a->text->fps_60, NULL);
    sfRenderWindow_drawText(a->window->window, a->text->fps_120, NULL);
    sfSprite_setPosition(a->mouse->cursor, a->mouse->pos);
    sfRenderWindow_drawSprite(a->window->window, a->mouse->cursor, NULL);
}

void while_open_options(float max, global_t *a)
{
    sfSprite_setPosition(a->sprite->sound_on, a->pos->pos_sound);
    sfSprite_setPosition(a->sprite->sound_off, a->pos->pos_sound);
    sfSprite_setPosition(a->sprite->back, a->pos->pos_back);
    sfSprite_setPosition(a->sprite2->test, (sfVector2f){550, 200});
    sfText_setPosition(a->text->fps_30, (sfVector2f){635, 205});
    sfText_setPosition(a->text->fps_60, (sfVector2f){900, 205});
    sfText_setPosition(a->text->fps_120, (sfVector2f){1165, 205});
    int c = 0;
    while (sfRenderWindow_isOpen(a->window->window)) {
        sfRenderWindow_display(a->window->window);
        a->mouse->pos.x = sfMouse_getPositionRenderWindow(a->window->window).x
        - 45;
        a->mouse->pos.y = sfMouse_getPositionRenderWindow(a->window->window).y;
        display_option(a);
        c = analyse_events_options(a);
        if (c != 0) while_open(a);
    }
}

int analyse_events_options(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window->window, &a->event->event)) {
        if (a->event->event.type == sfEvtClosed)
            sfRenderWindow_close(a->window->window);
        if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 814 &&
        a->event->event.mouseButton.x <= 1005 &&
        a->event->event.mouseButton.y >= 515 &&
        a->event->event.mouseButton.y <= 680) {
            a->pos->music_menu = sfTrue;
            song_gestion(a);
            return 0;
        }
        if (condition_events_options(a) == 1) return 1;
        if (a->event->event.type == sfEvtKeyPressed &&
        a->event->event.key.code == sfKeyEscape) return 1;
        display_fps(a);
    }
    return 0;
}

void display_fps(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 553 &&
        a->event->event.mouseButton.x <= 810 &&
        a->event->event.mouseButton.y >= 200 &&
        a->event->event.mouseButton.y <= 274) {
            sfText_setColor(a->text->fps_30, sfRed);
            sfText_setColor(a->text->fps_60, sfWhite);
            sfText_setColor(a->text->fps_120, sfWhite);
            sfRenderWindow_setFramerateLimit(a->window->window, 30);
        }
    condition_fps_2(a);
    condition_fps_3(a);
}
