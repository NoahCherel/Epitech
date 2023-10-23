/*
** EPITECH PROJECT, 2021
** display
** File description:
** task2-5
*/
#include <SFML/Graphics.h>

static sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL));
}

int main(void)
{
    sfRenderWindow *wndw = create_renderwindow(800, 600, 32, "Let's draw");
    sfEvent event;
    sfTexture *my_texture = sfTexture_createFromFile("my_image.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(wndw)) {
        sfRenderWindow_display(wndw);
        while (sfRenderWindow_pollEvent(wndw, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(wndw);
        sfRenderWindow_drawSprite(wndw, my_sprite, NULL);
    }
}
