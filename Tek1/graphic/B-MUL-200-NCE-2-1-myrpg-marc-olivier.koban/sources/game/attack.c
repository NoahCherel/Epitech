/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** battle
*/

#include "rpg.h"

int attack(scene_t *scene, global_t *g)
{
    scene->state = 1;
    scene->nb_texts = 3;
    scene->nb_buttons = 1;
    init_button(&scene->buttons[0], vect{1920 / 2 + 230, 1080 / 2 + 320},
    "Continue", 1);
    ftext = init_txt(vect{1080, 620}, 80,
    "Enemy's attack deals", D_FONT);
    int enemy_dmgi;
    if (g->st->dmg >= 30) {
        enemy_dmgi = g->st->hp - rand() % 10;
        g->st->hp -= enemy_dmgi;
    } else {
        enemy_dmgi = g->st->hp + 1 + rand() % 10;
    }
    char *enemy_dmg = my_inttostr(enemy_dmgi);
    scene->texts[1] = init_txt(vect{1110, 720}, 80, enemy_dmg, D_FONT);
    scene->texts[2] = init_txt(vect{1250, 720}, 80, " damage !", D_FONT);
    return (9);
}

int attack_2(scene_t *scene, global_t *g)
{
    scene->state = 2;
    scene->nb_buttons = 1;
    scene->buttons = malloc(sizeof(button_t *) * scene->nb_buttons);
    init_button(&scene->buttons[0], vect{1920 / 2 - 400, 1080 / 2 + 320},
    "Continue", 1);
    scene->nb_texts = 3;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{300, 620}, 80,
    "Link's attack deals", D_FONT);
    scene->texts[1] = init_txt(vect{380, 720}, 80,
    my_inttostr(g->st->dmg), D_FONT);
    scene->texts[2] = init_txt(vect{500, 720}, 80, "damage !", D_FONT);
    return (9);
}

int attack_3(scene_t *scene, global_t *g)
{
    scene->state = 3; scene->nb_objs = 1;
    if (g->st->dmg > 25) {
        game_won(scene, g);
    } else {
        init_button(&scene->buttons[0], vect{1920 / 2 - 170, 1080 / 2 + 100},
        "Respawn", 1);
        scene->nb_texts = 1;
        scene->texts = malloc(sizeof(sfText *) * (scene->nb_texts + 1));
        ftext = init_txt(vect{630, 350}, 150, "Battle lost.", D_FONT);
    }
    return (9);
}

int attack2_events(scene_t *scene, global_t *g)
{
    if (scene->state >= 3) return (attack3_events(scene, g));
    if (g->window->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape) {
        scene->state = 0;
        sfMusic_pause(g->music->music_battle);
        sfMusic_play(g->music->music_game);
        init_battle(scene, g);
        return (get_game_scene(g));
    }
    if (g->window->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEnter)
        return (attack_3(scene, g));
    pause_button(scene, g);
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (attack_3(scene, g));
    return (9);
}

int attack_events(scene_t *scene, global_t *g)
{
    if (scene->state >= 2) return (attack2_events(scene, g));
    if (g->window->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape) {
        scene->state = 0;
        sfMusic_pause(g->music->music_battle);
        sfMusic_play(g->music->music_game);
        init_battle(scene, g);
        return (get_game_scene(g));
    }
    if (g->window->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEnter)
        return (attack_2(scene, g));
    pause_button(scene, g);
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (attack_2(scene, g));
    return (9);
}
