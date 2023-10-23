/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** utils2 my_defender
*/

#include "../include/my.h"

static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *Name)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, Name, sfResize | sfClose, NULL));
}

int analyse_events(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window->window, &a->event->event)) {
        if (a->event->event.type == sfEvtClosed)
            sfRenderWindow_close(a->window->window);
        if (a->event->event.mouseButton.button == sfMouseLeft &&
        a->mouse->pos.x > 550) {
            return (event_menu(a));
        }
        keybord_menu(a);
    }
    return 0;
}

global_t *fill_global(global_t *a)
{
    a = malloc(sizeof(global_t));
    a->window = set_window(a->window); a->bird = set_bird(a->bird);
    a->clock_sprite = set_clock139(a->clock_sprite);
    a->window->window = create_window(1920, 1080, 32, "My_Defender");
    a->sprite = set_sprite(a->sprite); a->sprite2 = set_sprite3(a->sprite2);
    a->event = set_event(a->event); a->title = title_setup(a->title);
    a->menu = menu(a->menu); a->mouse = set_cursor(a->mouse);
    a->m_button = button(a->m_button); a->music = creation_music(a->music);
    a->map = map(a->map); a->clo = set_clock(a->clo);
    a->time_struct = set_time(a->time_struct); a->pos = set_pos(a->pos);
    a->var = set_var(a->var); a->text = set_text(a->text);
    a->tower = tower_menu(a->tower);
    a->logo = logo_display(a->logo); a->hud = hud_init(a->hud);
    a->lose = lost(a->lose); a->spawn = rande(10, 1);
    a->nb_enemy1 = 0; a->nb_wave = 1; a->waveEnded = sfTrue;
    a->win = win(a->win); a->clock = sfClock_create();
    a->row = 0; a->column = 0; a->path = malloc(sizeof(char*) * 20);
    a->clocl = sfClock_create(); a->index = 0; a->nb_t1 = 0; a->placement = 0;
    a->money = score_init(a->money); return (a);
}

void while_open(global_t *a)
{
    while (sfRenderWindow_isOpen(a->window->window)) {
        sfRenderWindow_display(a->window->window);
        paralax(0.02, a); display_all(a); bird(a);
        a->mouse->pos.x = sfMouse_getPositionRenderWindow(a->window->window).x
        - 45;
        a->mouse->pos.y = sfMouse_getPositionRenderWindow(a->window->window).y;
        mouse_menu(a); mouse_menu2(a);
        sfSprite_setPosition(a->mouse->cursor, a->mouse->pos);
        int c = analyse_events(a);
        if (c != 0) option_menu(a, c);
    }
}
