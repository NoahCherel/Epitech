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
        my_putstr("My Defender : Epitech Project where you must make a game");
        my_putchar(' ');
        my_putstr("like Bloons TD in a tower defense game.");
        my_putchar('\n');
        my_putstr("USAGE :");
        my_putchar('\n');
        my_putstr("");
        my_putchar('\n');
        my_putstr("");
        my_putchar('\n');
    }
}

void display_all(global_t *a)
{
    sfRenderWindow_drawSprite(a->window->window, a->sprite->image_menu, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->title->title, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->logo->logo, NULL);
    bouton_draw(a);
    menu_draw(a);
    sfRenderWindow_drawText(a->window->window, a->title->text, NULL);
    sfRenderWindow_drawSprite(a->window->window, a->mouse->cursor, NULL);
}

void free_all(global_t *a)
{
    destroy_all(a); free(a->menu); free(a->window); free(a->sprite);
    free(a->event); free(a->time_struct); free(a->title);
    free(a->clo); free(a->map); free(a->m_button); free(a->music);
    free(a->tower); free(a->pos); free(a->logo); free(a->hud);
    free(a->var); free(a->win); free(a->lose);
    free(a);
}

void paralax(float max, global_t *a)
{
    a->time_struct->para_time = sfClock_getElapsedTime(a->clo->para);
    float seconds = a->time_struct->para_time.microseconds / 1000000.0;
    if (seconds > max) {
        a->sprite->pos_fond.x -= 2;
        if (a->sprite->pos_fond.x == -1920) {
            a->sprite->pos_fond.x += 1920;
        }
        sfSprite_setPosition(a->sprite->image_menu, a->sprite->pos_fond);
        sfClock_restart(a->clo->para);
    }
}

void song_gestion2(global_t *a)
{
    if (a->pos->music_menu == sfFalse) {
        if (a->pos->bool_sound == sfFalse) {
            a->pos->bool_sound = sfTrue;
            sfMusic_setVolume(a->music->music_menu, 0);
            sfMusic_setVolume(a->music->music_game, 0);
        } else {
            a->pos->bool_sound = sfFalse;
            sfMusic_setVolume(a->music->music_menu, 50);
            sfMusic_setVolume(a->music->music_game, 50);
        }
    }
}
