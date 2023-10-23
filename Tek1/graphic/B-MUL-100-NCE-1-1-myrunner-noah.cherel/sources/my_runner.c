/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** My_hunter
*/

#include "../include/my.h"

static sfRenderWindow * create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *Name)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, Name, sfResize | sfClose, NULL));
}

void analyse_events(global_t *a)
{
    while (sfRenderWindow_pollEvent(a->window, &a->event)) {
        if (a->event.type == sfEvtClosed) sfRenderWindow_close(a->window);
        if (a->event.type == sfEvtKeyPressed) {
            move(a);
            if (a->event.key.code == sfKeySpace) {
                if (a->clo->pause == sfTrue) {
                    a->clo->pause = sfFalse; break;
                }
                set_sound(a->sounds); a->clo->pause = sfTrue;
            }
        }
    }
    sfSprite_setPosition(a->c->sprite, (sfVector2f){a->c->pos.x, a->c->pos.y});
}

void while_open(global_t *a)
{
    while (sfRenderWindow_isOpen(a->window)) {
        a->clo->time = sfClock_getElapsedTime(a->clo->clock);
        a->clo->tmp = sfTime_asMilliseconds(a->clo->time); analyse_events(a);
        if (a->clo->pause == sfTrue) sfClock_restart(a->clo->clock);
        if (a->c->d == sfTrue) sfClock_restart(a->clo->clock);
        if (a->clo->pause == sfFalse) sfClock_getElapsedTime(a->clo->clock);
        if (a->clo->tmp > 75 && a->clo->pause != sfTrue && a->c->d != sfTrue) {
            move_rect(a->c); sfClock_restart(a->clo->clock); }
        if (a->map->a != a->map->nb_coin && a->clo->tmp > 20) {
            move_object(a->g);
        } else if (a->map->a == a->map->nb_coin) a->clo->win = sfTrue;
        if (a->g->monster->pos.x < 1) a->map->a++;
        if (a->clo->tmp > 80 && a->clo->pause != sfTrue) rect_object(a->g);
        if (a->clo->tmp > 15 && a->clo->pause != sfTrue && a->c->d != sfTrue)
            move_parralax(a->p);
        sfSprite_setPosition(a->c->sprite, (sfVector2f){a->c->pos.y,
        a->c->pos.x}); display_all(a); score_fct(a->window, a->score1->sco);
        if (a->clo->pause != sfTrue && a->c->d != sfTrue) physics(a->c, a->j);
        player_life(a); dead_funct(a); pause_funct(a) ;collisions(a);
        sfRenderWindow_display(a->window);
    }
}

global_t *fill_global(global_t *a)
{
    a->clo = set_clock(a->clo);
    a->j = set_gravity(a->j);
    a->map = set_map(a->map);
    a->score1 = score_init(a->score1);
    a->window = create_window(1600, 900, 32, "My_Runner");
    a->p = parallax(a->p);
    a->c = character_init(a->c);
    a->g = objet(a->g);
    sfRenderWindow_setFramerateLimit(a->window, 60);
    return (a);
}

int main(int ac, char **av)
{
    global_t *a; a = malloc(sizeof(global_t));
    int fd = open(av[1], O_RDONLY);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help(ac, av); return (0);
    }
    if (fd == -1) {
        my_putstr("La map...");
        return (84);
    }
    srand(time(NULL));
    a = fill_global(a);
    map_basic(a, av[1], fd);
    music_toplay(a);
    while_open(a); sfMusic_destroy(a->Music);
    /*sfSound_destroy(a->sounds->sound);
    sfSoundBuffer_destroy(a->sounds->buffer);*/
    destroy_all(a); free_all(a);
    return (0);
}
