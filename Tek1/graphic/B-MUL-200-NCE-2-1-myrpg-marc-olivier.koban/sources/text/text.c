/*
** EPITECH PROJECT, 2022
** SCENE.C
** File description:
** Intialize menu buttons
*/

#include "rpg.h"

sfText *init_txt(sfVector2f pos, int size, char *text, char *font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, text);
    sfText_setFont(txt, sfFont_createFromFile(font));
    sfText_setCharacterSize(txt, size);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    return (txt);
}

sfText *txt2(sfVector2f pos, int size, char *text, char *font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, text);
    sfText_setFont(txt, sfFont_createFromFile(font));
    sfText_setCharacterSize(txt, size);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    return (txt);
}

char *choice_font(int i)
{
    if (i == 0) return (D_FONT);
    if (i == 1) return ("fonts/kill.ttf");
    if (i == 2) return ("fonts/ancient_modern_tales.otf");
    if (i == 3) return ("fonts/super-legend-boy.otf");
    if (i == 4) return ("fonts/arial_narrow_7.ttf");
}

sfVector2f font_pos(int i)
{
    switch (i) {
        case 0:
            return vect {805, 735};
            break;
        case 1:
            return vect {795, 753};
            break;
        case 2:
            return vect {815, 737};
            break;
        case 3:
            return vect {795, 750};
            break;
        case 4:
            return vect {815, 737};
            break;
    }
}

int font_size(int i)
{
    if (i == 0) return 50;
    if (i == 1) return 30;
    if (i == 2) return 51;
    if (i == 3) return 34;
    if (i == 4) return 45;
}
