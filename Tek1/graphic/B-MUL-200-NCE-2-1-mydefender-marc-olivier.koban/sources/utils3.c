/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** utils3
*/

#include "../include/my.h"

void while_open_tutorial(float max, global_t *a)
{
    while (sfRenderWindow_isOpen(a->window->window)) {
        sfRenderWindow_display(a->window->window);
        paralax(0.02, a);
        sfRenderWindow_drawSprite(a->window->window,
        a->sprite->image_menu, NULL);
        sfRenderWindow_drawSprite(a->window->window, a->sprite->tuto, NULL);
        a->mouse->pos.x = sfMouse_getPositionRenderWindow(a->window->window).x
        - 45;
        a->mouse->pos.y = sfMouse_getPositionRenderWindow(a->window->window).y;
        sfSprite_setPosition(a->sprite->back, (sfVector2f){1760, 0});
        sfRenderWindow_drawSprite(a->window->window, a->sprite->back, NULL);
        sfSprite_setPosition(a->mouse->cursor, a->mouse->pos);
        sfRenderWindow_drawSprite(a->window->window, a->mouse->cursor, NULL);
        analyse_event_option(a);
    }

}

char *txttoint(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(20 * sizeof(char**));
    read(fd, buffer, 160);
    close (fd);
    return (buffer);
}

int count_line(global_t *a)
{
    int y = 0;
    for (int x = 0; a->map->map_array[x] != '\0'; x++) {
        if (a->map->map_array[x] == '\n') y++;
    }
    y++;
    a->map->nbr_line = y;
    return y;
}

void conversion_int(global_t *a)
{
    for (int x = 0; x != a->map->nbr_line; x++) {
        for (int y = 0; y != a->map->nbr_col; y++) {
            a->map->list[x][y] = my_chartoint(a->map->map_2d[x][y]);
        }
    }
}

int count_collums(global_t *a)
{
    int y = 0;
    for (int x = 0; a->map->map_array[x] != '\n'; x++) {
        y++;
    }
    a->map->nbr_col = y + 1;
    return y;
}
