/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** inventory
*/

#include "rpg.h"

void openinv(scene_t *scene, global_t *g)
{
    scene->spriteinventory = sfSprite_create();
    scene->textureinventory = sfTexture_createFromFile("img/inv.jpg", NULL);
    sfSprite_setTexture(scene->spriteinventory, scene->textureinventory,
    sfTrue);
    sfSprite_setPosition(scene->spriteinventory, vect{1520, 80});
    scene->nb_buttons = 1;
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons + 1);
    init_buttoninv(&scene->buttons[0], vect{1840, 1080 - 997}, "X");
    scene->invboxnb = 35;
}

void init_buttoninv(button_t *button, sfVector2f position, char *text)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, vect{40, 40});
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    button->text = sfText_create();
    sfText_setString(button->text, text);
    sfText_setFont(button->text, sfFont_createFromFile(D_FONT));
    sfText_setCharacterSize(button->text, 30);
    sfText_setColor(button->text, sfWhite);
    sfText_setPosition(button->text, vect{position.x + 10, position.y});
}

void event_inv(global_t *g, scene_t *scene)
{
    if (WINDOW->event.type == sfEvtKeyReleased &&
    KEYCODE == sfKeyI) {
        if (scene->inventory == 0) {
            scene->inventory = 1;
            coininv(scene, g);
        } else
            scene->inventory = 0;
    }
}

void createitem(global_t *scene, int imgnb)
{
    char *imgneed;
    switch (imgnb) {
        case 1: imgneed = "img/item1.png"; break;
        case 2: imgneed = "img/item2.png"; break;
        case 3: imgneed = "img/item3.png"; break;
        case 4: imgneed = "img/item4.png"; break;
        case 5: imgneed = "img/item5.png"; break;
        case 6: imgneed = "img/item6.png"; break;
        default:
            break;
    }
    scene->spritebox = sfSprite_create();
    scene->texturebox = sfTexture_createFromFile(imgneed, NULL);
    sfSprite_setTexture(scene->spritebox, scene->texturebox, sfTrue);
    sfSprite_setPosition(scene->spritebox, vect{1920 - 380, 1080 - 940});
    sfSprite_setScale(scene->spritebox, vect{0.80, 0.80});
}

void buy_item(scene_t *scene, global_t *g)
{
    if (BTN_CLICK[0].rect, p_pos) && M_PRESS && MONEY >= 10)
        g->boxok = 1, g->shopbox = 1, MONEY -= 10, g->st->dmg += 20;
    if (BTN_CLICK[1].rect, p_pos) && M_PRESS && MONEY >= 15)
        g->boxok = 1, g->shopbox = 2, MONEY -= 15, g->st->dmg += 25;
    if (BTN_CLICK[2].rect, p_pos) && M_PRESS && MONEY >= 20)
        g->boxok = 1, g->shopbox = 3, MONEY -= 20, g->st->dmg += 30;
    if (BTN_CLICK[3].rect, p_pos) && M_PRESS && MONEY >= 25)
        g->boxok = 1, g->shopbox = 4, MONEY -= 25, g->st->dmg += 35;
    if (BTN_CLICK[4].rect, p_pos) && M_PRESS && MONEY >= 30)
        g->boxok = 1, g->shopbox = 5, MONEY -= 30, g->st->dmg += 40;
    if (BTN_CLICK[5].rect, p_pos) && M_PRESS && MONEY >= 35)
        g->boxok = 1, g->shopbox = 6, MONEY -= 35, g->st->dmg += 45;
}
