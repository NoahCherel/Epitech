/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu events
*/

#include "rpg.h"

void init_menu(scene_t *scene)
{
    scene->name = MENU;
    scene->nb_objs = 1;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/bg2.png");
    scene->nb_buttons = 4;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_button(&scene->buttons[0], vect{1920 - 450, 150}, "Play", 1);
    init_button(&scene->buttons[1], vect{1920 - 450, 300}, "Help", 0);
    init_button(&scene->buttons[2], vect{1920 - 450, 450}, "Settings", 0);
    init_button(&scene->buttons[3], vect{1920 - 450, 600}, "Exit", 0);
    scene->nb_texts = 1;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{60, 20}, 215, "My\nRPG", D_FONT);
}

void change_sel(scene_t *scene, global_t *g)
{
    if (KEYCODE == sfKeyUp) {
        int mv = 0;
        for (int i = 1; i < scene->nb_buttons; i++)
            (scene->buttons[i].sel == 1 && mv == 0) ? B_UP(i), mv = 1 : 0;
    }
    if (KEYCODE == sfKeyDown) {
        int mv = 0;
        for (int i = 0; i < scene->nb_buttons - 1; i++)
            (scene->buttons[i].sel == 1 && mv == 0) ? B_DWN(i), mv = 1 : 0;
    }
}

int key_pressed(scene_t *scene, global_t *g)
{
    if (KEYCODE == sfKeyEnter) {
        if (scene->buttons[0].sel == 1) {
            sfMusic_pause(g->music->music_menu);
            sfMusic_play(g->music->music_game);
        }
        if (scene->buttons[0].sel == 1 && get_game_scene(g) != 0)
            return (get_game_scene(g));
        if (scene->buttons[1].sel == 1) return (2);
        if (scene->buttons[2].sel == 1) return (3);
        if (scene->buttons[3].sel == 1) closewin(g->window->window);
    }
    change_sel(scene, g);
    return (0);
}

void select_button(scene_t *scene, int n)
{
    for (int i = 0; i < scene->nb_buttons; i++)
        if (scene->buttons[i].sel == 1)
            unsel_bt(scene->buttons, i);
    sel_bt(scene->buttons, n);
}

int menu_events(scene_t *scene, global_t *g)
{
    if (g->window->event.type == sfEvtKeyPressed &&
    KEYCODE == sfKeyEscape) {
        closewin(g->window->window); return (1);
    }
    if (button_click(scene->buttons[0].rect, vict{M_POS_X, M_POS_Y})) {
        sfMusic_pause(g->music->music_menu);
        sfMusic_play(g->music->music_game); select_button(scene, 0);
        sfSound_play(g->music->sound);
        if (g->scene == 0) return (1); if (g->scene == 1) return (5);
        if (get_game_scene(g) != 0) return (get_game_scene(g));
    }
    if (button_click(scene->buttons[1].rect, vict{M_POS_X, M_POS_Y})) {
        select_button(scene, 1); return (2);
    } if (button_click(scene->buttons[2].rect, vict{M_POS_X, M_POS_Y})) {
        select_button(scene, 2); return (3);
    } if (button_click(scene->buttons[3].rect, vict{M_POS_X, M_POS_Y}))
        closewin(g->window->window);
    pause_button(scene, g); if (g->window->event.type == sfEvtKeyReleased)
        return (key_pressed(scene, g)); return (0);
}
