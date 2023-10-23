/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** utils2
*/

#include "rpg.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        my_put_nbr(nb);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}

void zoom_fct(scene_t **scenes, global_t *g)
{
    const sfView *b = sfRenderWindow_getView(WINDOW->window);
    sfView *a = sfView_copy(b);
    float max = 1.40; float min = 0.6; float zoom_ratio = 0.05;
    if (g->window->event.type == sfEvtMouseWheelMoved) {
        if (g->window->event.mouseWheel.delta > 0 && g->zoom < max) {
            sfView_zoom(a, 0.9);
            g->zoom += zoom_ratio;
            sfRenderWindow_setView(g->window->window, a);
        } else if (g->window->event.mouseWheel.delta < 0 &&
        g->zoom > min) {
            sfView_zoom(a, 1 / 0.9);
            g->zoom -= zoom_ratio;
            sfRenderWindow_setView(g->window->window, a);
        }
    }
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
