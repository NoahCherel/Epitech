/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** options_menu
*/

#include "rpg.h"

void init_settings_v2(scene_t *scene, global_t *g)
{
    change_text(scene, g); scene->nb_test = 10;
    scene->btn_sprite = malloc(sizeof(button_sprite_t) * scene->nb_test + 1);
    init_btn_mod(&scene->btn_sprite[0], vect{580, 160}, BTN, vect{150, 125});
    init_btn_mod(&scene->btn_sprite[1], vect{810, 160}, BTN, vect{150, 125});
    init_btn_mod(&scene->btn_sprite[2], vect{1040, 160},
    BTN, vect{150, 125});
    init_btn_mod(&scene->btn_sprite[3], vect{635, 880},
    "img/menu_opt/accept.png", vect{450, 200});
    init_btn_mod(&scene->btn_sprite[4], vect{1070, 380},
    "img/menu_opt/plus.png", vect{100, 100});
    init_btn_mod(&scene->btn_sprite[5], vect{620, 380},
    "img/menu_opt/minus.png", vect{100, 100});
    init_btn_mod(&scene->btn_sprite[6], vect{600, 555},
    "img/menu_opt/left.png", vect{103, 70});
    init_btn_mod(&scene->btn_sprite[7], vect{1070, 555},
    "img/menu_opt/right.png", vect{103, 70});
    init_btn_mod(&scene->btn_sprite[8], vect{600, 725},
    "img/menu_opt/left.png", vect{103, 70});
    init_btn_mod(&scene->btn_sprite[9], vect{1075, 725},
    "img/menu_opt/right.png", vect{103, 70});
}

void init_btn_mod(button_sprite_t *button, sfVector2f position, char *file,
sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, position);
    sfSprite_setScale(button->sprite, vect{1.2, 1.2});
    button->form.top = 0;
    button->form.left = 0;
    button->form.width = size.x;
    button->form.height = size.y;
    sfSprite_setTextureRect(button->sprite, button->form);
}

rect_t init_rect_mod(sfVector2f sz, sfVector2f rs, sfVector2f pos, char *file)
{
    rect_t rect;
    rect.sprite = sfSprite_create();
    sfTexture *font_sprite = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(rect.sprite, font_sprite, sfTrue);
    rect.rect.left = 0;
    rect.rect.top = 0;
    rect.rect.width = sz.x;
    rect.rect.height = sz.y;
    sfSprite_scale(rect.sprite, vect{rs.x, rs.y});
    sfSprite_setPosition(rect.sprite, pos);
    sfSprite_setTextureRect(rect.sprite, rect.rect);
    return (rect);
}

void change_text(scene_t *scene, global_t *g)
{
    ftext = init_txt(vect{838, 400}, 75, intoa(g->vol),
    D_FONT);
    scene->texts[1] = init_txt(vect{830, 330}, 40, "Volume :",
    D_FONT);
    scene->texts[2] = init_txt(vect{615, 195}, 65, "30", D_FONT);
    scene->texts[3] = init_txt(vect{845, 195}, 65, "60", D_FONT);
    scene->texts[4] = init_txt(vect{1070, 195}, 65, "120", D_FONT);
    scene->texts[5] = init_txt(vect{855, 110}, 40, "FPS :", D_FONT);
    scene->texts[6] = init_txt(vect{767, 15}, 70, "SETTINGS", D_FONT);
    scene->texts[7] = init_txt(font_pos(g->font),
    font_size(g->font), "Dialogues", choice_font(g->font));
}
