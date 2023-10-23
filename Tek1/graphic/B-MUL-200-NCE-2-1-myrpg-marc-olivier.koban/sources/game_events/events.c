/*
** EPITECH PROJECT, 2022
** events.c
** File description:
** events
*/

#include "rpg.h"

int game_events(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_texts; i++)
        sfText_setFont(scene->texts[i], sfFont_createFromFile(choice_font(g->font)));
    g->scene = 0; g->statu_menu = 0; event_text(g, 1);
    if (WINDOW->event.type == sfEvtKeyReleased &&
    KEYCODE == sfKeyEscape) {
        scene->inventory = 0; return (4);
    } event_inv(g, scene);
    close_btn_inv(scene, g);
    if (g->red == 1) {
        g->exit_house = g->pos_player;
        g->pos_player.x = 900; g->pos_player.y = 480; g->red = 0; return (5);
    } if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyA) {
        g->text_choice = 0; return (8);
    }
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyC) {
        g->st->money += 100;
    }
    return (1);
}

int first_zone_events(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_texts; i++)
        sfText_setFont(scene->texts[i], sfFont_createFromFile(choice_font(g->font)));
    g->scene = 1; g->statu_menu = 0;
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape)
        return (4);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyE) {
        int a = condition_battle(g);
        if (a == 9) return (9);
    }
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyA) {
        g->text_choice = 0; return (8);
    }
    event_inv(g, scene); close_btn_inv(scene, g);
    int c; c = (first_zone_event2(g, scene));
    if (c != 0) return (c);
    event_text(g, 2); return (5);
}

int help_events(scene_t *scene, global_t *g)
{
    if (WINDOW->event.type == sfEvtKeyPressed && KEYCODE == sfKeyEscape)
        return (0);
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (0);
    pause_button(scene, g);
    return (2);
}

int sets_events(scene_t *scene, global_t *g)
{
    if (WINDOW->event.type == sfEvtKeyPressed && KEYCODE == sfKeyEscape)
        return (0);
    set_volume(scene, g);
    set_fps(scene, g);
    pause_button(scene, g);
    if (button_click(scene->btn_sprite[3].rect,
    (sfVector2i){M_POS_X, M_POS_Y})) {
        if (WINDOW->event.type == sfEvtMouseButtonReleased)
            return (0);
    }
    return (3);
}

int paus_events(scene_t *scene, global_t *g)
{
    g->statu_menu = 1;
    if (WINDOW->event.type == sfEvtKeyPressed && KEYCODE == sfKeyEscape)
        return (0);
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (get_game_scene(g));
    if (button_click(scene->buttons[1].rect, (sfVector2i){M_POS_X, M_POS_Y})) {
        sfMusic_pause(g->music->music_game);
        sfMusic_play(g->music->music_menu); return (0);
    } if (button_click(scene->buttons[2].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        closewin(WINDOW->window); pause_button(scene, g);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEnter) {
        if (scene->buttons[0].sel == 1) return (get_game_scene(g));
        if (scene->buttons[1].sel == 1) return (0);
        if (scene->buttons[2].sel == 1) closewin(WINDOW->window);
    } if (WINDOW->event.type == sfEvtKeyReleased) change_sel(scene, g);
    return (4);
}
