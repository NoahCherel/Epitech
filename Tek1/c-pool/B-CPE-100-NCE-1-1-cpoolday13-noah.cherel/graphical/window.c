/*
** EPITECH PROJECT, 2021
** window
** File description:
** task01
*/
#include <SFML/Graphics.h>

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};
    sfEvent event;

    window = sfRenderWindow_create(video_mode, "My first Window", sfClose | sfResize, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
}
