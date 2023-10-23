/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** shop_menu
*/

#include "rpg.h"

void shop_scene(global_t *g, scene_t *scene)
{
    scene->nb_test = 3; scene->nb_txt_shop = 9; scene->nb_items = 8;
    scene->btn_sprite = malloc(sizeof(button_sprite_t) * scene->nb_test + 1);
    init_btn_mod(&scene->btn_sprite[0], vect{1601, 140}, SH, vect{190, 55});
    init_btn_mod(&scene->btn_sprite[1], vect{1601, 240}, SH, vect{190, 55});
    init_btn_mod(&scene->btn_sprite[2], vect{1601, 336}, SH, vect{190, 55});
    scene->nb_texts = 4;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    ftext = init_txt(vect{1660, 150}, 40, "Buy", FONT);
    scene->texts[1] = init_txt(vect{1660, 250}, 40, "Talk", FONT);
    scene->texts[2] = init_txt(vect{1650, 350}, 40, "Leave", FONT);
    scene->texts[3] = init_txt(vect{1615, 110}, 20, "Jawed the shopkeeper",
    FONT);
    scene->nb_shop_btn = 6;
    scene->shop_btn = malloc(sizeof(button_sprite_t) * scene->nb_shop_btn + 1);
    init_btn_mod(&scene->shop_btn[0], vect{1260, 160}, "img/item1.png",
    vect{80, 70});
    init_btn_mod(&scene->shop_btn[1], vect{1380, 160}, "img/item2.png",
    vect{80, 70});
    shop_scene2(g, scene);
}

void shop_scene2(global_t *g, scene_t *scene)
{
    init_btn_mod(&scene->shop_btn[2], vect{1490, 160}, PNG1, vect{80, 70});
    init_btn_mod(&scene->shop_btn[3], vect{1260, 290}, PNG2, vect{80, 70});
    init_btn_mod(&scene->shop_btn[4], vect{1380, 290}, PNG3, vect{80, 70});
    init_btn_mod(&scene->shop_btn[5], vect{1490, 290}, PNG4, vect{80, 70});
    scene->txt_shop = malloc(sizeof(sfText *) * scene->nb_txt_shop + 1);
    scene->txt_shop[0] = init_txt(vect{1255, 254}, 20, "BroadSword", FONT);
    scene->txt_shop[1] = init_txt(vect{1370, 254}, 20, "lightSword", FONT);
    scene->txt_shop[2] = init_txt(vect{1487, 254}, 20, "SkySword", FONT);
    scene->txt_shop[3] = init_txt(vect{1255, 381}, 20, "NightBlade", FONT);
    scene->txt_shop[4] = init_txt(vect{1370, 381}, 20, "Katana", FONT);
    scene->txt_shop[5] = init_txt(vect{1487, 381}, 20, "MasterSword", FONT);
    scene->txt_shop[6] = init_txt(vect{1380, 100}, 40, "SHOP", FONT);
    scene->txt_shop[7] = init_txt(vect{1550, 130}, 20, intoa(g->st->money),
    FONT);
    scene->txt_shop[8] = init_txt(vect{1490, 115}, 20, "Money:", FONT);
    scene->talk_npc = malloc(sizeof(sfText *) * scene->nb_talk + 1);
    scene->talk_npc[0] = init_txt(vect{150, 775}, 50, TXT_SHOP, FONT);
    shop_scene3(g, scene);
}

void shop_mnu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/shop_menu.png", NULL);
    sfVector2f pos = {1600, 100};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.0});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}

void buy_menu(global_t *g)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/buy_menu.png", NULL);
    sfVector2f pos = {1250, 100};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.15, 1.012});
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(g->window->window, sprite, NULL);
}

void interaction_npc(global_t *g)
{
    if (g->pos_player.x >= 812 && g->pos_player.x <= 820 &&
    g->pos_player.y >= 304 && g->pos_player.y <= 308 && g->head == 1) {
        if (g->text_choice == 1) {
            g->text_choice = 0;
            g->statu_menu = 0;
            g->npc_shop = 0;
            g->buy_menu = 0;
            g->talk_shop = 0;
        } else {
            g->text_choice = 1;
            g->statu_menu = 1;
            g->npc_shop = 1;
        }
    } else {
        g->npc_shop = 0;
    }
}
