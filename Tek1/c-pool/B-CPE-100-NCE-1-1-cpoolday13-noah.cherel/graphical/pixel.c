/*
** EPITECH PROJECT, 2021
** pixel
** File description:
** task02
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>

struct framebuffer_t {
    unsigned int width;
    unsigned int height;
    sfUint8 pixels;
};
typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
voif framebuffer_destroy(framebuffe_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);

#endif /* FRAMEBUFFER_T_ */

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    t_my_framebuffer *framebuffer;
    framebuffer = malloc(sizeof(32)) * (width * height);

    framebuffer->width = width;
    framebuffer->height = height;
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    sfVector2f test = {10, 10};
    sfVector2f pos = {x ,y}
    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setSize(rectangle, test);
    sfRectangleShape = setPosition(rectangle, pos);    
}

int main(void)
{
    int width = 800;
    int height = 600;
    int bitsPerPixels = 32;
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, bitsPerPixels};
    sfEvent event;
    my_put_pixel(framebuffer, 100, 100, sfRed);
    

    window = sfRenderWindow_create(video_mode, "My first Window", sfClose | sfResize, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRenderWindow_display(window);
    }
}

