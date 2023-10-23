/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** events4.c
*/

#include "rpg.h"

int condition_battle(global_t *g)
{
    if (X_BTW(1020, 1028) && g->pos_player.y == 724 && g->head == 1 &&
    g->quest->is_active == sfTrue) {
        if (g->text_choice == 8) {
            g->text_choice2 = 0; g->text_choice = 0;
            sfMusic_pause(g->music->music_game);
            sfMusic_play(g->music->music_battle);
            return (9);
        } else {
            g->text_choice = 8;
        }
    }
}

int first_zone_events3(global_t *g, scene_t *scene)
{
    if (g->red == 4) {
        g->pos_player.x = g->exit_house.x;
        g->pos_player.y = g->exit_house.y - 4; g->red = 0; return (1);
    }
}

int credits_events(scene_t *scene, global_t *g)
{
    g->scene = 4;
    if (WINDOW->event.type == sfEvtKeyPressed) {
        closewin(WINDOW->window);
        return (6);
    }
    return (10);
}
