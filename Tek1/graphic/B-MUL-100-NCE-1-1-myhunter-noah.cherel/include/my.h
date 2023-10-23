/*
** EPITECH PROJECT, 2021
** MY H
** File description:
** Contains all prototypes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#ifndef MY_H_
    #define MY_H_

typedef struct bird_s {
    sfSprite *bird;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} bird_t;

typedef struct clocks_s {
    sfClock *clock;
    int tmp;
    sfTime time;
    sfBool pause;
    sfBool win;
} clocks_t;

typedef struct Background_s {
    sfSprite *background;
    sfTexture *text;
    sfSprite *cloud;
    sfTexture *cloud_txt;
    sfVector2f pos;
} background_t;

typedef struct cursor_s {
    sfSprite *cursor;
    sfTexture *text;
    sfVector2f pos;
} cursor_t;

typedef struct global_s {
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *Music;
    int score2;
    bird_t *bird;
    background_t *background;
    cursor_t *cursor;
    clocks_t *clo;
} global_t;

void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
char *my_inttostr(int num);

background_t *set_background(background_t *background);

bird_t *set_bird(bird_t *bird);

void render_draw(global_t *a);

clocks_t *set_clock(clocks_t *cl);

cursor_t *set_cursor(cursor_t *cursor);

void music_toplay(global_t *obj);

void move_rect(sfIntRect *rect, int offset, int max_value);
static sfRenderWindow * create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title);
void my_help(int ac, char **av);
void score_fct(sfRenderWindow *window, sfClock *clock, int score2);
void free_all(global_t *a);
void utils(global_t *a);
void utils1(global_t *a);
void analyse_events1(global_t *a);

#endif
