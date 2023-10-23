/*
** EPITECH PROJECT, 2022
** SCENE.C
** File description:
** Intialize menu buttons
*/

#include "rpg.h"

void init_help(scene_t *scene)
{
    scene->name = HELP;
    scene->nb_objs = 3;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/bg2.png");
    init_obj(&scene->objs[1], vect{120, 30}, vect{1.5, 1.5},
    "img/controls.png");
    init_obj(&scene->objs[2], vect{120, 470}, vect{1.5, 1.5}, "img/help.png");
    scene->nb_buttons = 1;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_button(&scene->buttons[0], vect{1920 - 450, 800}, "Back", 0);
}

void init_settings(scene_t *scene, global_t *g)
{
    scene->name = SETTINGS; scene->nb_objs = 2;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/bg2.png");
    init_obj(&scene->objs[1], vect{500, 0}, vect{3.0, 2.8},
    "img/menu_opt/menu1.png");
    scene->nb_rects = 1;
    scene->rects = malloc(sizeof(rect_t) * scene->nb_rects + 1);
    scene->rects[0] = init_rect_mod(vect{1920, 270}, vect{0.16, 0.5},
    vect{750, 540}, "img/box_text.png");
    g->fps = 60; scene->nb_texts = 8;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{840, 405}, 65, intoa(g->vol), FONT);
    scene->texts[1] = init_txt(vect{850, 350}, 20, "Volume :", FONT);
    scene->texts[2] = init_txt(vect{600, 200}, 65, intoa(30), FONT);
    scene->texts[3] = init_txt(vect{830, 200}, 65, intoa(60), FONT);
    init_settings_v2(scene, g);
}

void init_pause(scene_t *scene)
{
    scene->name = PAUSE;
    scene->nb_objs = 1;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/bg2.png");
    scene->nb_buttons = 3;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_button(&scene->buttons[0], vect{1920 / 2 - 175, 300}, "Resume", 1);
    init_button(&scene->buttons[1], vect{1920 / 2 - 175, 450}, "Menu", 0);
    init_button(&scene->buttons[2], vect{1920 / 2 - 175, 600}, "Exit", 0);
}

void init_game(scene_t *scene, global_t *g)
{
    scene->name = GAME;
    scene->nb_player = 1; scene->nb_map = 1;
    scene->nb_texts = 2;
    g->rects = malloc(sizeof(rect_t) * 1);
    g->rects[0] = init_rect_mod(vect{1920, 270}, vect{1, 1},
    vect{0, 750}, "img/box_text.png");
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    scene->player = malloc(sizeof(player_t) * scene->nb_player + 1);
    scene->map = malloc(sizeof(map_t) * scene->nb_player + 1);
    scene->map->image = sfImage_createFromFile("img/collisions.png");
    init_player(&scene->player[0], g, 1);
    init_map(&scene->map[0], "img/house.png", (sfIntRect){65, 65, 1920, 1080});
    init_text_game(scene, g);
    openinv(scene, g);
}
