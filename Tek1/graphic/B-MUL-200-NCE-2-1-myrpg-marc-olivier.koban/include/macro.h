/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_

    #define BTN  "img/menu_opt/button.png"
    #define FONT choice_font(g->font)
    #define FONT_G choice_font(g->font)
    #define D_FONT "fonts/tadeo.otf"
    #define SH "img/shop_button.png"
    #define SH_BTN "img/btn_shop.png"
    #define TXT_QUEST "No. 001 Danger in the town"
    #define TXT_QUEST_2 "Somewhere in the town"
    #define TXT_QUEST_3 "if you defeat him."
    #define TXT_QUEST_4 "Search the town to fight Marco the evil doer"
    #define TXT_QUEST_5 "You have successfully finished the quest ! Thanks !"
    #define TXT_SHOP "Hey ! What do you want ?"
    #define EXIT "img/exit_button.png"
    #define REMINDER "img/reminder_quest.png"
    #define NPC "img/npc_quest.png"
    #define SPEED 4
    #define rstart sfClock_restart
    #define create sfRenderWindow_create
    #define closewin sfRenderWindow_close
    #define cr_ff sfTexture_createFromFile
    #define settext sfSprite_setTextureRect
    #define setsprite sfSprite_setTextureRect
    #define poll sfRenderWindow_pollEvent
    #define press sfKeyboard_isKeyPressed
    #define getpos sfSprite_getPosition
    #define setpos sfSprite_setPosition
    #define setfps sfRenderWindow_setFramerateLimit
    #define keyrepeat sfRenderWindow_setKeyRepeatEnabled
    #define drawtxt sfRenderWindow_drawText
    #define drawsprite sfRenderWindow_drawSprite
    #define evt sfEvtClosed
    #define intoa my_inttostr
    #define ns scene = scenes
    #define sname scene->name
    #define vect (sfVector2f)
    #define vict (sfVector2i)
    #define p_pos (sfVector2i) {M_POS_X, M_POS_Y}
    #define c_obj(n) &scene->objs[scene->nb_objs + n]
    #define loop scene = scenes[loops[g->scene](scene, g)]
    #define ftext scene->texts[0]
    #define MONEY g->st->money
    #define BTN_CLICK button_click(scene->shop_btn
    #define BTN_HOVER button_is_hovered(scene.shop_btn
    #define ITEM scene.items
    #define WTXT(s) 90, s, D_FONT

    #define IS_EVT g->window->event.type == evt
    #define GET_MICROS sfClock_getElapsedTime(clock).microseconds
    #define M_POS_X g->window->event.mouseButton.x
    #define M_POS_Y g->window->event.mouseButton.y
    #define WIN_SPEC sfResize | sfClose
    #define KEYCODE g->window->event.key.code
    #define WINDOW g->window
    #define WIN g->window->window

    #define CURR_SPT scene->objs[scene->nb_objs].sprite
    #define CURR_TEX scene->objs[scene->nb_objs].texture

    #define M_PRESS g->window->event.type == sfEvtMouseButtonPressed

    #define B_USEL(i) unsel_bt(scene->buttons, i)
    #define B_SEL(i) sel_bt(scene->buttons, i)
    #define B_UP(i) unsel_bt(scene->buttons, i), sel_bt(scene->buttons, i - 1)
    #define B_DWN(i) unsel_bt(scene->buttons, i), sel_bt(scene->buttons, i + 1)

    #define UP sfKeyUp
    #define DW sfKeyDown
    #define LT sfKeyLeft
    #define RT sfKeyRight
    #define ENTER sfKeyEnter

    #define X_BTW(a, b) g->pos_player.x >= a && g->pos_player.x <= b
    #define Y_BTW(a, b) g->pos_player.y >= a && g->pos_player.y <= b

    #define LD g->head == 0

    #define PNG1 "img/item3.png"
    #define PNG2 "img/item4.png"
    #define PNG3 "img/item5.png"
    #define PNG4 "img/item6.png"

#endif
