/*
** EPITECH PROJECT, 2022
** koban
** File description:
** events3.c
*/

#include "rpg.h"

int third_zone_events2(scene_t *scene, global_t *g)
{
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape &&
    g->npc_shop == 0)
        return (4);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape &&
    g->npc_shop == 1) {
        g->text_choice = 0; g->npc_shop = 0;
        g->statu_menu = 0; g->npc_shop = 0;
    }
    event_inv(g, scene); close_btn_inv(scene, g);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyA) {
        g->text_choice = 0; return (8);
    }
    if (X_BTW(872, 924) && g->pos_player.y == 476 && LD && sname == INN) {
        g->scene = 1; g->exit_bii.x = g->pos_player.x;
        g->pos_player.x = g->enter_village.x;
        g->pos_player.y = g->enter_village.y + 4; return (5);
    }
    return 0;
}

int third_zone_eventsv2(scene_t *scene, global_t *g)
{
    if (button_click(scene->btn_sprite[0].rect, p_pos) && M_PRESS)
        g->buy_menu += 1, g->talk_shop = 0;
    if (button_click(scene->btn_sprite[1].rect, p_pos) && M_PRESS)
        g->talk_shop += 1, g->buy_menu = 0;
    if (button_click(scene->btn_sprite[2].rect, p_pos)) {
        g->text_choice = 0; g->statu_menu = 0;
        g->npc_shop = 0; g->buy_menu = 0; g->talk_shop = 0;
    }
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEscape) {
        g->text_choice = 0; g->statu_menu = 0;
        g->npc_shop = 0; g->buy_menu = 0; g->talk_shop = 0;
    }
    event_text(g, 3); scene->txt_shop[7] = init_txt(vect{1550, 115}, 20,
    intoa(g->st->money), FONT);
    if (g->pos_player.x >= 884 && g->pos_player.y == 476 && LD) {
        g->scene = 1; g->exit_shop.x = g->pos_player.x;
        g->pos_player.x = g->enter_village.x;
        g->pos_player.y = g->enter_village.y + 4; return (5);
    }
    return (7);
}

int third_zone_events(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_texts; i++)
        sfText_setFont(scene->texts[i], sfFont_createFromFile(choice_font(g->font)));
    for (int i = 0; i < scene->nb_talk; i++)
        sfText_setFont(scene->talk_npc[i], sfFont_createFromFile(choice_font(g->font)));
    for (int i = 0; i < scene->nb_talk; i++)
        sfText_setFont(scene->talk_npc[i], sfFont_createFromFile(choice_font(g->font)));
    g->scene = 3; int c = third_zone_events2(scene, g); if (c != 0) return (c);
    button_shop(scene, g); buy_item(scene, g);
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyA) {
        g->text_choice = 0; return (8);
    }
    for (int i = 0; i < scene->nb_test; i++) {
        if (button_is_hovered(scene->btn_sprite[i].rect, WINDOW->window)) {
            scene->btn_sprite[i].form.left += 190;
            setsprite(scene->btn_sprite[i].sprite, scene->btn_sprite[i].form);
        } else {
            scene->btn_sprite[i].form.left = 0;
            setsprite(scene->btn_sprite[i].sprite, scene->btn_sprite[i].form);
        }
    }
    return (third_zone_eventsv2(scene, g));
}

void button_shop(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_test; i++) {
        if (button_is_hovered(scene->btn_sprite[i].rect,
        g->window->window)) {
            scene->btn_sprite[i].form.left += 190;
            sfSprite_setTextureRect(scene->btn_sprite[i].sprite,
            scene->btn_sprite[i].form);
        } else {
            scene->btn_sprite[i].form.left = 0;
            sfSprite_setTextureRect(scene->btn_sprite[i].sprite,
            scene->btn_sprite[i].form);
        }
    }
}

void pause_button(scene_t *scene, global_t *g)
{
    for (int i = 0; i < scene->nb_buttons; i++) {
        if (button_is_hovered(scene->buttons[i].rect,
        g->window->window)) {
            sfRectangleShape_setOutlineColor(scene->buttons[i].rect, sfRed);
        } else {
            sfRectangleShape_setOutlineColor(scene->buttons[i].rect, sfWhite);
        }
    }
}
