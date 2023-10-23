/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_menu
*/

#include "rpg.h"

status_menu_t *init_status_menu(global_t *g)
{
    g->st = malloc(sizeof(status_menu_t));
    g->st->hp = 100;
    g->st->max_hp = 100;
    g->st->dmg = 10;
    g->st->lvl = 1;
    g->st->exp = 0;
    g->st->def = 10;
    g->st->money = 0;
    return (g->st);
}

void init_player_menu1(scene_t *scene, global_t *g)
{
    ftext = txt2(vect{80, 35}, 50, "Link", FONT);
    scene->texts[1] = txt2(vect{550, 35}, 50, "Hero", FONT);
    scene->texts[2] = txt2(vect{250, 100}, 50, "Level", FONT);
    scene->texts[3] = txt2(vect{250, 270}, 50, "HP", FONT);
    scene->texts[4] = txt2(vect{250, 440}, 50, "ATK", FONT);
    scene->texts[5] = txt2(vect{250, 500}, 50, "DEF", FONT);
    scene->texts[6] = txt2(vect{700, 35}, 50, "EXP", FONT);
    scene->texts[7] = txt2(vect{700, 100}, 50, "Next Level:", FONT);
    scene->texts[8] = txt2(vect{250, 600}, 50, "Money:", FONT);
    scene->texts[9] = txt2(vect{700, 230}, 50, "Equipement:", FONT);
    scene->texts[10] = txt2(vect{700, 730}, 50, "Bio:", FONT);
    scene->texts[11] = txt2(vect{400, 100}, 50, intoa(g->st->lvl), FONT);
    scene->texts[12] = txt2(vect{400, 270}, 50, intoa(g->st->hp), FONT);
    scene->texts[13] = txt2(vect{550, 440}, 50, intoa(g->st->dmg), FONT);
    scene->texts[14] = txt2(vect{550, 500}, 50, intoa(g->st->def), FONT);
    scene->texts[15] = txt2(vect{1200, 35}, 50, intoa(g->st->exp), FONT);
    scene->texts[16] = txt2(vect{1200, 100}, 50, intoa(100 - g->st->exp),
    FONT);
    scene->texts[17] = txt2(vect{550, 270}, 50, intoa(g->st->max_hp), FONT);
}

void init_player_menu(scene_t *scene, global_t *g)
{
    scene->name = PLAYER; scene->nb_objs = 3;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/bg2.png");
    init_obj(&scene->objs[1], vect{0, 0}, vect{2.1, 2.1}, "img/mc_menu1.png");
    init_obj(&scene->objs[2], vect{60, 120}, vect{1.0, 1.0}, "img/s_link.png");
    scene->nb_buttons = 1; scene->nb_texts = 25;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_button(&scene->buttons[0], vect{1920 - 450, 800}, "Back", 0);
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    init_player_menu1(scene, g);
    scene->texts[18] = txt2(vect{500, 270}, 50, " / ", FONT_G);
    scene->texts[19] = txt2(vect{700, 800}, 50, "Main Character", FONT_G);
    scene->texts[20] = txt2(vect{700, 300}, 50, "???", FONT_G);
    scene->texts[21] = txt2(vect{700, 400}, 50, "???", FONT_G);
    scene->texts[22] = txt2(vect{700, 500}, 50, "???", FONT_G);
    scene->texts[23] = txt2(vect{700, 600}, 50, "???", FONT_G);
    scene->texts[24] = txt2(vect{550, 600}, 50, intoa(g->st->money), FONT_G);
}

void update_player_menu(scene_t *scene, global_t *g)
{
    scene->texts[24] = txt2(vect{550, 600}, 50, intoa(g->st->money), FONT_G);
    scene->texts[11] = txt2(vect{400, 100}, 50, intoa(g->st->lvl), FONT);
    scene->texts[12] = txt2(vect{400, 270}, 50, intoa(g->st->hp), FONT);
    scene->texts[13] = txt2(vect{550, 440}, 50, intoa(g->st->dmg), FONT);
    scene->texts[14] = txt2(vect{550, 500}, 50, intoa(g->st->def), FONT);
    scene->texts[15] = txt2(vect{1200, 35}, 50, intoa(g->st->exp), FONT);
    scene->texts[16] = txt2(vect{1200, 100}, 50, intoa(100 - g->st->exp),
    FONT);
    scene->texts[17] = txt2(vect{550, 270}, 50, intoa(g->st->max_hp),
    FONT);
}
