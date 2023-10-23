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
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

typedef struct window_s {
    sfRenderWindow *window;
} window_t;

typedef struct sprite_s {
    sfSprite *image_menu;
    sfSprite *button_menu;
    sfVector2f pos_fond;
    sfSprite *sound_on;
    sfSprite *sound_off;
    sfSprite *back;
    sfSprite *pause;
    sfSprite *life;
    sfSprite *play;
    sfSprite *quit;
    sfSprite *tuto;
} sprite_t;

typedef struct sprite2_s {
    sfSprite *test;
} sprite2_t;

typedef struct pos_s {
    sfVector2f pos_sound;
    sfVector2f pos_back;
    sfVector2f menu_hard1;
    sfVector2f menu_hard2;
    sfBool bool_sound;
    sfBool music_menu;
} pos_t;

typedef struct event_s {
    sfEvent event;
} event_t;

typedef struct clocks_s {
    sfClock *para;
    sfClock *mob;
} clocks_t;

typedef struct time12_s {
    sfTime para_time;
    sfTime mob_time;
} time12_u;

typedef struct menu_s {
    sfText *menu[4];
    sfTexture *hover;
    int selectedItemIndex;
} menu_t;

typedef struct menu_button_s {
    sfSprite *button[4];
    sfTexture *text;
    sfIntRect rect[4];
} menu_button_t;

typedef struct mouse_s {
    sfSprite *cursor;
    sfTexture *text;
    sfVector2f pos;
} mouse_t;

typedef struct title_s {
    sfSprite *title;
    sfText *text;
    sfTexture *textu;
    sfVector2f pos;
} title_t;

typedef struct music_s {
    sfMusic *music_menu;
    sfSound *selection;
    sfSoundBuffer *select;
    sfMusic *music_game;
} music_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfClock *clock;
    sfTexture *texture;
    sfIntRect frame;
    sfTime time123;
    sfVector2f xy;
    sfBool alive;
    int hp;
} enemy_t;

typedef struct tower_t {
    sfRectangleShape *rect;
    sfIntRect frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
    sfTime time1;
} tower_t;

typedef struct map_s {
    int width;
    int height;
    sfTexture *tiletext;
    sfSprite *tile;
    sfIntRect tile_1[10];
    char *name_map;
    char *map_array;
    char **map_2d;
    int nbr_line;
    int nbr_col;
    int **list;
} map_t;

typedef struct tower_menu_s {
    sfSprite *tower[4];
    sfTexture *text;
    sfIntRect rect[4];
    sfText *menu[4];
    sfSprite *tower_m[4];
    sfTexture *text1;
    sfIntRect rect1[4];
    sfTexture *hover;
    int selectedItemIndex;
} tower_menu_t;

typedef struct var_s {
    int heart;
    sfBool lose;
} var_t;

typedef struct text_s {
    sfText *score;
    sfText *fps_30;
    sfText *fps_60;
    sfText *fps_120;
    sfFont *font;
} text_t;

typedef struct score_s {
    int money;
    sfText *text;
    sfSprite *money_s;
    sfTexture *money_t;
    int sco;
    sfVector2f ps;
    sfText *score;
    sfText *score1;
} score_t;

typedef struct logo_s {
    sfSprite *logo;
    sfTexture *text;
    sfTexture *text2;
} logo_t;

typedef struct hud_play_s {
    sfSprite *tower;
    sfTexture *text;
    sfSprite *money;
    sfTexture *text1;
} hud_play_t;

typedef struct lose_s {
    sfSprite *lose;
    sfSprite *lose1;
    sfSprite *play;
    sfTexture *text;
    sfTexture *text1;
    sfTexture *text3;
    sfText *text2;
} lose_t;

typedef struct win_s {
    sfSprite *win;
    sfSprite *win1;
    sfSprite *play;
    sfTexture *text;
    sfTexture *text1;
    sfTexture *text3;
    sfText *text2;
} win_t;

typedef struct clock_sprite_s {
    sfClock *clock;
    int tmp;
    sfTime time;
    sfBool pause;
    sfBool win;
} clock_sprite_t;
typedef struct bird_s {
    sfSprite *bird;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} bird_t;

typedef struct global_s {
    int nb_enemy1; bird_t *bird; clock_sprite_t *clock_sprite;
    sfClock *clocl; sfClock *cls;
    sfTime clds; sfTime clsd;
    int mob, index, spawn, row, placement, nb_t1, pos1x, postx, pos1y, posty;
    int column; char *path; sfClock *clock; sfTime time1;
    int nb_wave; sfBool waveEnded;
    win_t *win; music_t *music;
    tower_t tower1[6]; enemy_t enemy1[100];
    window_t *window; sprite_t *sprite;
    sprite2_t *sprite2; event_t *event;
    score_t *money; clocks_t *clo;
    menu_t *menu; menu_button_t *m_button;
    mouse_t *mouse; title_t *title;
    map_t *map; tower_menu_t *tower;
    time12_u *time_struct; pos_t *pos;
    var_t *var; text_t *text;
    logo_t *logo; hud_play_t *hud;
    lose_t *lose;
} global_t;

/*animatedspritefortheaer*/
bird_t *set_bird(bird_t *bird);
clock_sprite_t *set_clock139(clock_sprite_t *cl);
void bird(global_t *a);
void move_rect1(sfIntRect *rect, int offset, int max_value);

/*tower*/
void init_tower1(global_t *a);
void t1_placement(global_t *a, sfVector2f *turret_position);
void range_tower1(global_t *a, int i);
void update_tower1(global_t *a);

/*win*/
win_t *win(win_t *a);
void win_disp(global_t *a);

/*destroy*/
void destroy_all2(global_t *a);
void destroy_all1(global_t *a);
void destroy_all(global_t *a);

/*enemy_wave1*/
int rande(int max, int min);
void scene1(global_t *a);
void update_mob(global_t *a);
void reset_mob_pause(global_t *a);

/*ennemy_wave*/
void init_mob(global_t *a, int i);
void reset_mob(global_t *a);
void endwavedetec(global_t *a);
void spawn(global_t *a);
void init_mob1(global_t *a);
int find_beginning(global_t *a);
char *set_path(global_t *a);

/*utils2*/
static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *Name);
int analyse_events(global_t *a);
global_t *fill_global(global_t *a);
void while_open(global_t *a);

/*utils1*/
void my_help(int ac, char **av);
void display_all(global_t *a);
void free_all(global_t *a);
void paralax(float max, global_t *a);
void song_gestion2(global_t *a);

/*my_lib*/
void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);

/*my_lib2*/
int my_strtoint(char *str);
int my_chartoint(char str);
int my_compute_power_rec(int nb, int power);
void array_to_2d(char **final_list, char *new_list, int line);
char *my_inttostr(int num);

/*my_defender*/
void execution(global_t *global);
void preparation(void);

/*mouse*/
mouse_t *set_cursor(mouse_t *cursor);

/*menu*/
title_t *title_setup(title_t *title);
menu_t *menu_create(menu_t *menu, int i, sfVector2f pos, char *str);
menu_t *menu(menu_t *menu);
menu_button_t *button_create(menu_button_t *m_button, int i, sfVector2f pos);
menu_button_t *button(menu_button_t *m_button);

/*menu_play*/
void analyse_event_option(global_t *a);
void option_menu(global_t *a, int c);
void mouse_menu(global_t *a);
void mouse_menu2(global_t *a);
void mouse_condition_menu(int x, global_t *a);

/*fonction_struct1*/
window_t *set_window(window_t *window);
sprite_t *set_sprite(sprite_t *sprite);
void *set_sprite2(sprite_t *sprite);
event_t *set_event(event_t *events);
void move_rect(sfIntRect *rect, int offset, int max_value);

/*menu_utils*/
void menu_draw(global_t *a);
void bouton_draw(global_t *a);
void moveup(menu_t *menu, menu_button_t *button);
void movedown(menu_t *menu, menu_button_t *button);
int keybord_menu(global_t *a);

/*fonction_struct2*/
music_t *creation_music(music_t *music);
time12_u *set_time(time12_u *time1);
pos_t *set_pos(pos_t *pos_fond);
logo_t *logo_display(logo_t *a);
clocks_t *set_clock(clocks_t *cl);

/*menu_click*/
int event_menu(global_t *a);
int event_menu2(global_t *a);

/*tilemap*/
map_t *map(map_t *map);
void draw(global_t *win, map_t *mape);
map_t *set_tile(map_t *map, int i, int j, int k);
void draw_tile(global_t *win, sfIntRect placeHolder, int row, int column);

/*pathfinding*/
void path_x(global_t *a);
void path_y(global_t *a);
int enemy_move(global_t *a);
void pathfinding(global_t *a);
void pathfinder(global_t *a);

/*utils3*/
void while_open_tutorial(float max, global_t *a);
char *txttoint(char *filepath);
int count_line(global_t *a);
void conversion_int(global_t *a);
int count_collums(global_t *a);

/*option_menu*/
void display_option(global_t *a);
void while_open_options(float max, global_t *a);
int analyse_events_options(global_t *a);
void display_fps(global_t *a);

/*function_struct3*/
var_t *set_var(var_t *var);
text_t *set_text(text_t *text);
sprite2_t *set_sprite3(sprite2_t *sprite2);
void *set_sprite4(sprite2_t *sprite2);
hud_play_t *hud_init(hud_play_t *a);

/*play_menu*/
void while_open_play(float max, global_t *a);
void display_play(global_t *a);
void preparation_play(global_t *a);
void draw_sprite_play(global_t *a);

/*play_menu2*/
int analyse_events_play(global_t *a);
int analyse_events_play_2(global_t *a);
int analyse_event_play_3(global_t *a);

/*menu_pause*/
void while_open_pause(global_t *a);
void display_pause(global_t *a);
int analyse_events_menu(global_t *a);
int analyse_events_menu1(global_t *a);
void song_gestion(global_t *a);

/*tower_menu*/
tower_menu_t *menu_tower(tower_menu_t* tower, int i, sfVector2f pos);
tower_menu_t *menu_tower1(tower_menu_t* tower, int i, sfVector2f pos,
sfVector2f size);
tower_menu_t *tower_menu(tower_menu_t *tower);
tower_menu_t *tower_m_create(tower_menu_t *menu, int i, sfVector2f pos,
char *str);
void tower_draw(global_t *a);

/*money_score*/
score_t *score_init(score_t *score);

/*lose*/
lose_t *lost(lose_t *a);
void lose(global_t *a);

/*coding_style_option.c*/
int condition_events_options(global_t *a);
void condition_fps_2(global_t *a);
void condition_fps_3(global_t *a);

#endif
