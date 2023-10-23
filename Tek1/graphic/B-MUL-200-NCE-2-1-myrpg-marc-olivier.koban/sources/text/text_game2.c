/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** text_game2.c
*/

#include "rpg.h"

void choice_text_3(global_t *g)
{
    g->i = 1; if (g->pos_player.x == 1020 && Y_BTW(388, 396) && g->head == 2)
        simple_text(1, g);
    if (g->pos_player.x == 1084 && Y_BTW(384, 392) && g->head == 3)
        if (g->pnj2_zone2 == sfTrue && g->text_choice == 0)
            simple_text(13, g);
        else
            g->pnj2_zone2 = double_text_exp((sfVector2f){2, 14},
            g->pnj2_zone2, g, 43);
    if (g->pos_player.x == 1084 && Y_BTW(288, 296) && g->head == 3)
        simple_text(3, g);
    else if (g->pos_player.x == 1020 && Y_BTW(288, 296) && g->head == 2)
        simple_text(4, g);
    if (g->pos_player.x == 704 && Y_BTW(288, 296) && g->head == 2)
        simple_text(5, g);
    else if (g->pos_player.x == 768 && Y_BTW(288, 296) && g->head == 3)
        if (g->pnj5_zone2 == sfTrue && g->text_choice == 0) simple_text(12, g);
        else
            g->pnj5_zone2 = double_text_coins((sfVector2f){6, 9},
            g->pnj5_zone2, g, 50);
    choice_text_3_2(g);
}

void choice_text_3_2(global_t *g)
{
    if (g->pos_player.x == 768 && Y_BTW(384, 396) && g->head == 3)
        simple_text(7, g);
    if (g->pos_player.x == 704 && Y_BTW(384, 396) && g->head == 2)
        simple_text(8, g);
    if (X_BTW(648, 660) && Y_BTW(304, 304) && g->head == 1)
        simple_text(10, g);
    if (X_BTW(1128, 1140) && Y_BTW(304, 304) && g->head == 1)
        g->chest_zone2 = chest_text((sfVector2f){9, 10}, g->chest_zone2, g,
        50);
}

void init_text_scene2(scene_t *scene, global_t *g)
{
    scene->txt_quest[6] = txt2(vect{1400, 355}, 20, "Reward(s):", FONT);
    scene->txt_quest[7] = txt2(vect{1450, 400}, 20, "THE END", FONT);
    scene->txt_quest[8] = txt2(vect{1030, 230}, 20, TXT_QUEST_3, FONT);
    scene->txt_quest[9] = txt2(vect{1030, 260}, 20, TXT_QUEST_4, FONT);
    scene->txt_quest[10] = txt2(vect{1010, 260}, 20, TXT_QUEST_5, FONT);
    scene->talk_npc = malloc(sizeof(sfText *) * scene->nb_talk + 1);
    scene->talk_npc[0] = init_txt(vect{150, 775}, 50,
    "EXP is important to level up ! \
    \nThe more you level up, the stronger you are !", FONT);
    scene->talk_npc[1] = init_txt(vect{150, 775}, 50,
    "Before, I was a great adventurer. Now I'm retired.\
    \nAccept a little of my EXP. You will need it !", FONT);
    scene->talk_npc[2] = init_txt(vect{150, 775}, 50, "Ehh damm Tibo...",
    FONT);
    scene->talk_npc[3] = init_txt(vect{150, 775}, 50,
    "Dammm it's TiboInshape it's a pleasure to speek you !\
    \nWe will hit protesters with captain ! Dammm Captain !", FONT);
    scene->talk_npc[4] = init_txt(vect{150, 775}, 50,
    "Yes it's the Giroud !", FONT);
    init_text_scene2_2(scene, g);
}

void init_text_scene2_2(scene_t *scene, global_t *g)
{
    scene->talk_npc[5] = init_txt(vect{150, 775}, 50,
    "You want some money, homeless man ?\
    \nYou're lucky, I have 50 coins in my wallet !", FONT);
    scene->talk_npc[6] = init_txt(vect{150, 775}, 50,
    "If you press I, you can see your inventory !", FONT);
    scene->talk_npc[7] = init_txt(vect{150, 775}, 50,
    "I love the sword shop !\
    \nIf you have the time, don't hesitate to give it a try !", FONT);
    scene->talk_npc[8] = init_txt_gain(vect{150, 775}, vect{50, 50}, FONT, 0);
    scene->talk_npc[9] = init_txt(vect{150, 775}, 50, "The chest is empty...",
    FONT);
    scene->talk_npc[10] = init_txt(vect{150, 775}, 50,
    "If you press I, you can see your inventory !", FONT);
    scene->talk_npc[11] = init_txt(vect{150, 775}, 50,
    "I don't have any money left ! Go away !", FONT);
    scene->talk_npc[12] = init_txt(vect{150, 775}, 50,
    "Enjoy this XP !", FONT);
    scene->talk_npc[13] = init_txt_gain(vect{150, 775}, vect{50, 43}, FONT, 1);
}

void choice_text_2_2(global_t *g)
{
    if (X_BTW(1020, 1028) && g->pos_player.y == 724 && g->head == 1 &&
    g->quest->is_active != sfTrue)
        g->text_choice = g->text_choice == 7 ? 0 : 7;
}
