/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** battle
*/

#include "rpg.h"

int attack3_events(scene_t *scene, global_t *g)
{
    if ((g->window->event.type == sfEvtKeyReleased &&
    (KEYCODE == sfKeyEscape || KEYCODE == sfKeyEnter)) ||
    button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y})) {
        scene->state = 0; g->beat_boss = sfTrue;
        for (int i = 0; i < scene->nb_texts; i++) free(scene->texts[i]);
        free(scene->texts); free(scene->buttons);
        scene->nb_texts = 0; scene->nb_buttons = 0;
        init_battle(scene, g);
        sfMusic_pause(g->music->music_battle);
        sfMusic_play(g->music->music_game);
        return (get_game_scene(g));
    }
    pause_button(scene, g);
    return (9);
}

void game_won(scene_t *scene, global_t *g)
{
    if (g->st->exp + 60 >= 100) scene->nb_texts = 5;
    else {
        scene->nb_texts = 3;
    } scene->nb_buttons = 1;
    scene->buttons = malloc(sizeof(button_t *) * (scene->nb_buttons + 1));
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    g->st->money += 50; g->st->exp += 60;
    g->st->dmg += 1; g->st->hp += 10; g->st->max_hp += 10;
    ftext = init_txt(vect{630, 150}, 150, "Battle won !", D_FONT);
    scene->texts[1] = init_txt(vect{530, 360}, WTXT("You gained 60 EXP !"));
    scene->texts[2] = init_txt(vect{530, 460}, WTXT("You gained 50 COINS !"));
    if (g->st->exp >= 100) {
        g->st->lvl += 1; g->st->exp -= 100;
        scene->texts[3] = init_txt(vect{530, 560}, 90,
        "You are now level     !", D_FONT);
        scene->texts[4] = init_txt(vect{1200, 560}, WTXT(intoa(g->st->lvl)));
    } init_button(&scene->buttons[0],
    vect{1920 / 2 - 170, 1080 / 2 + 200}, "OK", 1);
}
