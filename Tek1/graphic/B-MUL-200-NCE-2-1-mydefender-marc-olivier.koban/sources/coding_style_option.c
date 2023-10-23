/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** coding_style_option
*/

#include "../include/my.h"

int condition_events_options(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
    a->event->event.mouseButton.x >= 28 &&
    a->event->event.mouseButton.x <= 147 &&
    a->event->event.mouseButton.y >= 890 &&
    a->event->event.mouseButton.y <= 1020) {
        sfSound_play(a->music->selection); return 1;
    }
    return 0;
}

void condition_fps_2(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 818 &&
        a->event->event.mouseButton.x <= 1072 &&
        a->event->event.mouseButton.y >= 200 &&
        a->event->event.mouseButton.y <= 274) {
            sfText_setColor(a->text->fps_30, sfWhite);
            sfText_setColor(a->text->fps_60, sfRed);
            sfText_setColor(a->text->fps_120, sfWhite);
            sfRenderWindow_setFramerateLimit(a->window->window, 60);
        }
}

void condition_fps_3(global_t *a)
{
    if (a->event->event.mouseButton.type == sfEvtMouseButtonPressed &&
        a->event->event.mouseButton.x >= 1081 &&
        a->event->event.mouseButton.x <= 1335 &&
        a->event->event.mouseButton.y >= 200 &&
        a->event->event.mouseButton.y <= 274) {
            sfText_setColor(a->text->fps_30, sfWhite);
            sfText_setColor(a->text->fps_60, sfWhite);
            sfText_setColor(a->text->fps_120, sfRed);
            sfRenderWindow_setFramerateLimit(a->window->window, 120);
        }
}
