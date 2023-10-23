/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** battle
*/

#include "rpg.h"

void init_battle(scene_t *scene, global_t *g)
{
    scene->name = BATTLE;
    scene->nb_objs = 3;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/battle.png");
    init_obj(&scene->objs[1], vect{510, 250}, vect{3.0, 3.0}, "img/link.png");
    init_obj(&scene->objs[2], vect{1020, 240}, vect{3.0, 3.0}, "img/mco.png");
    scene->nb_texts = 1;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{675, 60}, 120, "Battle Time !", D_FONT);
    scene->nb_buttons = 4;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_button(&scene->buttons[0], vect{1920 / 2 - 450, 1080 / 2 + 100},
    "Attack", 1);
    init_button(&scene->buttons[1], vect{1920 / 2 + 100, 1080 / 2 + 100},
    "Magic", 0);
    init_button(&scene->buttons[2], vect{1920 / 2 - 450, 1080 / 2 + 250},
    "Object", 0);
    init_button(&scene->buttons[3], vect{1920 / 2 + 100, 1080 / 2 + 250},
    "Leave", 0);
}

void change_sel_battle(scene_t *scene, global_t *g)
{
    if (KEYCODE == sfKeyRight) {
        if (scene->buttons[0].sel == 1) B_DWN(0);
        else if (scene->buttons[2].sel == 1) B_DWN(2);
    }
    if (KEYCODE == sfKeyLeft) {
        if (scene->buttons[1].sel == 1) B_UP(1);
        else if (scene->buttons[3].sel == 1) B_UP(3);
    }
    if (KEYCODE == sfKeyUp) {
        if (scene->buttons[2].sel == 1) B_USEL(2), B_SEL(0);
        else if (scene->buttons[3].sel == 1) B_USEL(3), B_SEL(1);
    }
    if (KEYCODE == sfKeyDown) {
        if (scene->buttons[0].sel == 1) B_USEL(0), B_SEL(2);
        else if (scene->buttons[1].sel == 1) B_USEL(1), B_SEL(3);
    }
}

int key_pressed_battle(scene_t *scene, global_t *g)
{
    if (KEYCODE == sfKeyEscape) {
        sfMusic_pause(g->music->music_battle);
        sfMusic_play(g->music->music_game);
        return (get_game_scene(g));
    }
    if (KEYCODE == sfKeyEnter) {
        if (scene->buttons[0].sel == 1) return (attack(scene, g));
        if (scene->buttons[1].sel == 1) return (magic(scene, g));
        if (scene->buttons[2].sel == 1) return (object(scene, g));
        if (scene->buttons[3].sel == 1) {
            sfMusic_pause(g->music->music_battle);
            sfMusic_play(g->music->music_game);
            return (get_game_scene(g));
        }
    }
    change_sel_battle(scene, g);
    return (9);
}

int battle_events(scene_t *scene, global_t *g)
{
    if (scene->state == 5) return (object_events(scene, g));
    if (scene->state == 4) return (magic_events(scene, g));
    if (scene->state >= 1) return (attack_events(scene, g));
    if (g->window->event.type == sfEvtKeyReleased)
        return (key_pressed_battle(scene, g));
    pause_button(scene, g);
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (attack(scene, g));
    if (button_click(scene->buttons[1].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (magic(scene, g));
    if (button_click(scene->buttons[2].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (object(scene, g));
    if (button_click(scene->buttons[3].rect, (sfVector2i){M_POS_X, M_POS_Y})) {
        sfMusic_pause(g->music->music_battle);
        sfMusic_play(g->music->music_game);
        return (get_game_scene(g));
    } return (9);
}
