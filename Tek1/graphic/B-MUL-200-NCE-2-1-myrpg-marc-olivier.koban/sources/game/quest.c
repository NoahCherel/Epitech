/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** quest
*/

#include "rpg.h"

quest_t *quest_create(void)
{
    quest_t *quest = malloc(sizeof(quest_t));
    quest->quest_choice = 0;
    quest->quest_pnj_menu = 0;
    quest->reminder = 0;
    quest->end_quest = 0;
    quest->is_active = sfFalse;
    return (quest);
}

void quest_scene(global_t *g, scene_t *scene)
{
    scene->nb_test = 1; scene->nb_talk = 14;
    scene->btn_sprite = malloc(sizeof(button_sprite_t) * scene->nb_test + 1);
    init_btn_mod(&scene->btn_sprite[0], vect{1500, 500}, SH, vect{190, 55});
    scene->nb_texts = 1; scene->nb_shop_btn = 2; scene->nb_quest_txt = 11;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{1510, 510}, 35, "Accept (Enter)", FONT);
    scene->shop_btn = malloc(sizeof(button_sprite_t) * scene->nb_shop_btn + 1);
    init_btn_mod(&scene->shop_btn[0], vect{1020, 370}, NPC, vect{35, 35});
    init_btn_mod(&scene->shop_btn[1], vect{1690, 105}, EXIT, vect{128, 128});
    sfSprite_setScale(scene->shop_btn[0].sprite, vect{3.0, 3.0});
    sfSprite_setScale(scene->shop_btn[1].sprite, vect{0.3, 0.3});
    scene->txt_quest = malloc(sizeof(sfText *) * scene->nb_quest_txt + 1);
    scene->txt_quest[0] = txt2(vect{1030, 100}, 40, TXT_QUEST, FONT);
    scene->txt_quest[1] = txt2(vect{1030, 200}, 20, "Marco the evil doer has "
    "been sighted inside the town, you will be rewarded", FONT);
    scene->txt_quest[2] = txt2(vect{1030, 355}, 20, "Requester:", FONT);
    scene->txt_quest[3] = txt2(vect{1100, 400}, 20, "Justin the Barman", FONT);
    scene->txt_quest[4] = txt2(vect{1030, 500}, 20, "Location:", FONT);
    scene->txt_quest[5] = txt2(vect{1050, 530}, 20, TXT_QUEST_2, FONT);
    init_text_scene2(scene, g);
}

void quest_mnu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/quest_menu.png", NULL);
    sfVector2f pos = {1000, 100};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.0});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}

void reminder_mnu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(REMINDER, NULL);
    sfVector2f pos = {1000, 220};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.0});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}

void event_btn_quest(global_t *g, scene_t *s)
{
    if (button_click(s->shop_btn[1].rect, (sfVector2i){M_POS_X, M_POS_Y})) {
        g->text_choice = 0; g->quest->quest_choice = 0;
        g->statu_menu = 0; g->quest->quest_pnj_menu = 0;
        g->quest->quest_pnj_menu = 0;
    }
    if (button_click(s->btn_sprite[0].rect, (sfVector2i){M_POS_X, M_POS_Y})) {
        g->text_choice = 0; g->quest->quest_choice = 0;
        g->statu_menu = 0; g->quest->quest_pnj_menu = 0;
        g->quest->quest_pnj_menu = 0; g->quest->is_active = sfTrue;
    }
    if (WINDOW->event.type == sfEvtKeyReleased && KEYCODE == sfKeyEnter
    && g->quest->quest_pnj_menu == 1) {
        g->text_choice = 0; g->quest->quest_choice = 0;
        g->statu_menu = 0; g->quest->quest_pnj_menu = 0;
        g->quest->quest_pnj_menu = 0; g->quest->is_active = sfTrue;
    }
}
