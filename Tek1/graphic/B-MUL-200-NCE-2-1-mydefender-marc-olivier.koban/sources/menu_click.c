/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** menu_click my_defender
*/

#include "../include/my.h"

int event_menu2(global_t *a)
{
    if (a->event->event.mouseButton.x >= 1409 &&
    a->event->event.mouseButton.x <= 1734 &&
    a->event->event.mouseButton.y >= 750 &&
    a->event->event.mouseButton.y <= 888)
        sfRenderWindow_close(a->window->window);
}

int event_menu(global_t *a)
{
    if (a->event->event.mouseButton.x >= 1409 &&
    a->event->event.mouseButton.x <= 1734 &&
    a->event->event.mouseButton.y >= 150 &&
    a->event->event.mouseButton.y <= 288) {
        sfSound_play(a->music->selection); return 1;
    }
    if (a->event->event.mouseButton.x >= 1409
    && a->event->event.mouseButton.x <= 1734 &&
    a->event->event.mouseButton.y >= 350 &&
    a->event->event.mouseButton.y <= 488) {
        sfSound_play(a->music->selection); return 2;
    }
    if (a->event->event.mouseButton.x >= 1409
    && a->event->event.mouseButton.x <= 1734 &&
    a->event->event.mouseButton.y >= 550 &&
    a->event->event.mouseButton.y <= 688) {
        sfSound_play(a->music->selection); return 3;
    }
    event_menu2(a); return 0;
}
