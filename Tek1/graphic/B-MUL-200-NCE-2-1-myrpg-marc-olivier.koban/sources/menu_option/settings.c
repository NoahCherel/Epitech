/*
** EPITECH PROJECT, 2022
** settings.c
** File description:
** settings
*/

#include "rpg.h"

void set_volume(scene_t *scene, global_t *g)
{
    if (M_PRESS && button_click(scene->btn_sprite[4].rect,
    vict{M_POS_X, M_POS_Y})) {
        if (g->vol < 100) {
            g->vol += 5;
            sfMusic_setVolume(g->music->music_menu, g->vol);
            sfMusic_setVolume(g->music->music_game, g->vol);
            sfMusic_setVolume(g->music->music_battle, g->vol);
            sfText_setString(ftext, intoa(g->vol));
        }
    }
    if (M_PRESS && button_click(scene->btn_sprite[5].rect,
    vict{M_POS_X, M_POS_Y})) {
        if (g->vol > 0) {
            g->vol -= 5;
            sfMusic_setVolume(g->music->music_menu, g->vol);
            sfMusic_setVolume(g->music->music_game, g->vol);
            sfMusic_setVolume(g->music->music_battle, g->vol);
            sfText_setString(ftext, intoa(g->vol));
        }
    }
}

void setup_fps(scene_t *scene, int fps, int i, global_t *g)
{
    if (M_PRESS && button_click(scene->btn_sprite[i].rect,
    vict{M_POS_X, M_POS_Y})) {
        if (g->fps < 121) {
            g->fps = fps;
            setfps(g->window->window, g->fps);
        }
    }
}

void setup_action_button(scene_t *scene, int i, int left, global_t *g)
{
    if (button_is_hovered(scene->btn_sprite[i].rect, g->window->window)) {
        scene->box_rect.top += 100;
        scene->btn_sprite[i].form.left = left;
        sfSprite_setTextureRect(scene->btn_sprite[i].sprite,
        scene->btn_sprite[i].form);
    }
    if (M_PRESS && button_click(scene->btn_sprite[i].rect,
        vict{M_POS_X, M_POS_Y})) {
            if (set_box(scene, i, g) == 1) {
                scene->btn_sprite[i].form.left = left;
                sfSprite_setTextureRect(scene->btn_sprite[i].sprite,
                scene->btn_sprite[i].form);
            }
        } else {
            scene->btn_sprite[i].form.left = 0;
            scene->box_rect.top += 100;
            sfSprite_setTextureRect(scene->btn_sprite[i].sprite,
            scene->btn_sprite[i].form);
        }
}

void color_fps(scene_t *scene, global_t *g, int i, int nb)
{
    if (g->fps == i) {
        sfText_setColor(scene->texts[nb], sfRed);
    } else {
        sfText_setColor(scene->texts[nb], sfBlack);
    }
}

void set_fps(scene_t *scene, global_t *g)
{
    color_fps(scene, g, 30, 2); color_fps(scene, g, 60, 3);
    color_fps(scene, g, 120, 4); setup_fps(scene, 30, 0, g);
    setup_fps(scene, 60, 1, g); setup_fps(scene, 120, 2, g);
    setup_action_button(scene, 0, 375, g);
    setup_action_button(scene, 1, 375, g);
    setup_action_button(scene, 2, 375, g);
    setup_action_button(scene, 3, 480, g);
    setup_action_button(scene, 4, 100, g);
    setup_action_button(scene, 5, 100, g);
    setup_action_button(scene, 6, 103, g);
    setup_action_button(scene, 7, 103, g);
    setup_action_button(scene, 8, 103, g);
    setup_action_button(scene, 9, 103, g);
}
