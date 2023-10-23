/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** events2.c
*/

#include "rpg.h"

int get_game_scene(global_t *g)
{
    if (g->scene == 0) return (1);
    if (g->scene == 1) return (5);
    if (g->scene == 2) return (6);
    if (g->scene == 3) return (7);
    return (0);
}

int second_zone_events(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_texts; i++)
        sfText_setFont(scene->texts[i], sfFont_createFromFile(choice_font(g->font)));
    for (int i = 0; i < scene->nb_talk; i++)
        sfText_setFont(scene->talk_npc[i], sfFont_createFromFile(choice_font(g->font)));
    g->scene = 2; if (WINDOW->event.type == sfEvtKeyReleased &&
    KEYCODE == sfKeyEscape && g->quest->quest_pnj_menu == 0) return (4);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape
    && g->quest->quest_pnj_menu == 1) {
        g->text_choice = 0; g->quest->quest_choice = 0;
        g->statu_menu = 0; g->quest->quest_pnj_menu = 0;
    } if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyA) {
        g->text_choice = 0; return (8);
    }
    event_btn_quest(g, scene); button_shop(scene, g); event_inv(g, scene);
    close_btn_inv(scene, g);
    if (event_text(g, 4) != 0) return (10); event_text(g, 5);
    if (X_BTW(872, 924) && g->pos_player.y == 476 && LD && sname == INN) {
        g->scene = 1; g->exit_bii.x = g->pos_player.x;
        g->pos_player.x = g->enter_village.x;
        g->pos_player.y = g->enter_village.y + 4; return (5);
    } return (6);
}

int first_zone_event2(global_t *g, scene_t *scene)
{
    if (g->red == 2) {
        g->enter_village.x = g->pos_player.x;
        g->enter_village.y = g->pos_player.y;
        g->pos_player.x = g->exit_bii.x;
        if (g->count != 0) g->pos_player.y = g->exit_bii.y - 4;
        else {
            g->pos_player.y = g->exit_bii.y; g->count = 1;
        }
        g->red = 0; g->scene = 2; return (6);
    }
    if (g->red == 3) {
        g->red = 0; g->enter_village.x = g->pos_player.x;
        g->enter_village.y = g->pos_player.y; g->pos_player.x = g->exit_shop.x;
        if (g->count_shop != 0) g->pos_player.y = g->exit_shop.y - 4;
        else {
            g->pos_player.y = g->exit_shop.y; g->count_shop = 1;
        }
        g->bool_exit = 1; return (7);
    } first_zone_events3(g, scene);
}

int player_menu_events(scene_t *scene, global_t *g)
{
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape)
        return (get_game_scene(g));
    if (button_click(scene->buttons[0].rect, (sfVector2i){M_POS_X, M_POS_Y}))
        return (get_game_scene(g));
    pause_button(scene, g); update_player_menu(scene, g);
    return (8);
}
