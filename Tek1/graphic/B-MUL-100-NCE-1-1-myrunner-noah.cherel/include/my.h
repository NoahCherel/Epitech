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

typedef struct map_s {
    int nb_coin;
    int nb_monster;
    int a;
} map_t;
typedef struct parralax_s {
    sfSprite *far;
    sfSprite *back;
    sfSprite *Forefront;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
} parallax_t;

typedef struct character_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfSprite *health;
    sfIntRect health_rect;
    sfTexture *health_text;
    sfBool d;
    sfBool saut;
} character_t;

typedef struct coin_s {
    sfSprite *s;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} coin_t;

typedef struct menu_s {
    sfSprite *sprite;
    sfTexture *text;
    sfBool *menu;
} menu_t;

typedef struct monster_s {
    sfSprite *m;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} monster_t;
typedef struct gameobject_s {
    enum {
        MONSTER,
        TRAP,
        COIN,
    } type;
    coin_t *c;
    monster_t *monster;
    sfSprite *s;
    sfTexture *text;
} gameobject_t;

typedef struct gravity_s {
    float velocityY;
    float velocityX;
    float gravity;
} gravity_t;

typedef struct score_s {
    int sco;
} score_t;

typedef struct clocks_s {
    sfClock *clock;
    int tmp;
    sfTime time;
    sfBool pause;
    sfBool win;
} clocks_t;

typedef struct sounds_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sounds_t;

typedef struct global_s {
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *Music;
    map_t *map;
    sounds_t *sounds;
    clocks_t *clo;
    score_t *score1;
    parallax_t *p;
    character_t *c;
    gameobject_t *g;
    gravity_t *j;
    menu_t *m;
} global_t;

void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
char *my_inttostr(int num);
clocks_t *set_clock(clocks_t *cl);
static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title);
void my_help(int ac, char **av);
void score_fct(sfRenderWindow *window, int score2);
void music_toplay(global_t *obj);
void display_all(global_t *obj);
void collisions(global_t *g);
parallax_t *parallax(parallax_t *obj);
void move_parralax(parallax_t *obj);
score_t *score_init(score_t *score1);
gravity_t *set_gravity(gravity_t *g);
character_t *character_init(character_t *perso);
void move_rect(character_t *perso);
void physics(character_t *p, gravity_t *a);
gameobject_t *objet(gameobject_t *e);
void move_object(gameobject_t *c);
void rect_object(gameobject_t *c);
coin_t *coin(coin_t *g);
monster_t *monster(monster_t *g);
void pause_funct(global_t *a);
void set_sound(sounds_t *sounds);
void free_all(global_t *a);
void destroy_all(global_t *a);
void player_life(global_t *a);
void dead_funct(global_t *a);
map_t *set_map(map_t *a);
void map_basic(global_t *a, char *file, int fd);
void move(global_t *a);

#endif
