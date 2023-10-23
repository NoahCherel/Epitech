/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** My_hunter
*/

#include "../include/my.h"

static sfRenderWindow * create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *Name)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, Name, sfResize | sfClose, NULL));
}

global_t *fill_global(global_t *a)
{
    a->window = create_window(1600, 900, 32, "My_Runner");
    a->bird = set_bird(a->bird);
    a->background = set_background(a->background);
    a->clo = set_clock(a->clo);
    a->cursor = set_cursor(a->cursor);
    sfRenderWindow_setFramerateLimit(a->window, 60);
    return (a);
}

void analyse_events1(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window, &a->event)) {
        if (a->event.type == sfEvtClosed)
            sfRenderWindow_close(a->window);
    sfRenderWindow_setMouseCursorVisible(a->window, sfFalse);
    }
}

void while_open(global_t *a)
{
    while (sfRenderWindow_isOpen(a->window)) { utils(a);
        if (a->clo->time.microseconds / 1000000.0 > 0.3) {
            if (a->bird->pos.x < 1600) {
                move_rect(&a->bird->rect, 150, 450); a->bird->pos.x += 150;
                a->background->pos.x += 150;
                sfSprite_setPosition(a->bird->bird, a->bird->pos);
                sfSprite_setPosition(a->background->cloud, a->background->pos);
            }
            utils1(a); sfClock_restart(a->clo->clock);
        }
        render_draw(a); score_fct(a->window, a->clo->clock, a->score2);
        sfSprite_setTextureRect(a->bird->bird, a->bird->rect);
        sfRenderWindow_display(a->window);
        sfRenderWindow_clear(a->window, sfBlack);
    }
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_help(ac, av); return (0);
    }
    global_t *a = malloc(sizeof(global_t));
    srand(time(NULL));
    a = fill_global(a);
    music_toplay(a);
    while_open(a);
    analyse_events1(a);
    sfMusic_destroy(a->Music);
    free_all(a);
    return (0);
}
