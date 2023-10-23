/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** display_game
*/

#include "rpg.h"

void draw_scene(sfRenderWindow *window, struct scene_s scene, global_t *g)
{
    for (int i = 0; i < scene.nb_buttons; i++)
        if (scene.name == MENU && scene.buttons[i].sel == 1)
            sfRectangleShape_setOutlineColor(scene.buttons[i].rect, sfRed);
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < scene.nb_objs; i++)
        drawsprite(window, scene.objs[i].sprite, NULL);
    for (int i = 0; i < scene.nb_buttons; i++) {
        sfRenderWindow_drawRectangleShape(window, scene.buttons[i].rect, NULL);
        drawtxt(window, scene.buttons[i].text, NULL);
    }
    for (int i = 0; i < scene.nb_test; i++)
        drawsprite(window, scene.btn_sprite[i].sprite, NULL);
    for (int i = 0; i < scene.nb_rects; i++)
        drawsprite(window, scene.rects[i].sprite, NULL);
    for (int i = 0; i < scene.nb_texts; i++)
        drawtxt(window, scene.texts[i], NULL);
    for (int i = 0; i < scene.nb_map; i++)
        drawsprite(window, scene.map[i].sprite, NULL);
    draw_scene2(window, scene, g); sfRenderWindow_display(window);
}

void draw_scene2(sfRenderWindow *window, struct scene_s scene, global_t *g)
{
    for (int i = 0; i < scene.nb_player; i++)
        drawsprite(window, scene.player[i].sprite, NULL);
    if (scene.inventory == 1) {
        drawsprite(window, scene.spriteinventory, NULL);
        sfRenderWindow_drawRectangleShape(window, scene.buttons[0].rect, NULL);
        drawtxt(window, scene.buttons[0].text, NULL);
        drawsprite(window, scene.spritecoin, NULL);
        drawtxt(window, scene.textscoin[0], NULL);
        if (g->boxok == 1) {
            createitem(g, g->shopbox);
            drawsprite(window, g->spritebox, NULL);
        }
    } if (g->text_choice != 0 && g->statu_menu == 0) {
        drawsprite(window, g->rects[0].sprite, NULL);
        if (g->i == 0) drawtxt(window, scene.texts[g->text_choice - 1], NULL);
        if (g->i == 1)
            drawtxt(window, scene.talk_npc[g->text_choice2 - 1], NULL);
    } draw_scene3(window, scene, g);
}

void draw_scene3(sfRenderWindow *w, struct scene_s s, global_t *g)
{
    if (g->npc_shop == 1) {
        shop_mnu(g); for (int i = 0; i < s.nb_test; i++)
            drawsprite(w, s.btn_sprite[i].sprite, NULL);
        for (int i = 0; i < s.nb_texts; i++) drawtxt(w, s.texts[i], NULL);
    }
    int i; if (g->buy_menu % 2 == 1) {
        buy_menu(g); for (i = 0; i < s.nb_shop_btn; i++)
            drawsprite(w, s.shop_btn[i].sprite, NULL);
        for (i = 0; i < s.nb_txt_shop; i++) drawtxt(w, s.txt_shop[i], NULL);
        item_description(s, g);
    } if (g->quest->quest_pnj_menu == 1) {
        quest_mnu(g); for (i = 0; i < s.nb_test; i++)
        drawsprite(w, s.btn_sprite[i].sprite, NULL);
        for (i = 0; i < s.nb_texts; i++) drawtxt(w, s.texts[i], NULL);
        for (i = 0; i < 8; i++) drawtxt(w, s.txt_quest[i], NULL);
        for (i = 0; i < s.nb_shop_btn; i++)
            drawsprite(w, s.shop_btn[i].sprite, NULL);
    }
    draw_scene4(w, s, g, i);
}

void draw_scene4(sfRenderWindow *w, struct scene_s s, global_t *g, int i)
{
    if (g->quest->is_active == sfTrue && g->quest->reminder == 1) {
        reminder_mnu(g), drawtxt(w, s.txt_quest[9], NULL);
    }
    if (g->talk_shop % 2 == 1) {
        drawsprite(w, g->rects[0].sprite, NULL);
        for (i = 0; i < s.nb_talk; i++) drawtxt(w, s.talk_npc[i], NULL);
    }
    if (g->beat_boss == sfTrue && g->quest->end_quest == 1) {
        win_mnu(g); drawtxt(w, s.txt_quest[10], NULL);
    }
}
