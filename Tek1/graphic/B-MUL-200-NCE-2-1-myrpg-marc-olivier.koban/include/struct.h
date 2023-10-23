/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "rpg.h"

typedef struct quest_s {
    int quest_choice;
    int quest_pnj_menu;
    int reminder;
    sfBool is_active;
    int end_quest;
} quest_t;

typedef struct player_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
} player_t;

typedef struct status_menu_s {
    int hp;
    int max_hp;
    int dmg;
    int lvl;
    int exp;
    int money;
    int def;
} status_menu_t;

typedef struct map_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfBool go_up;
    sfBool go_down;
    sfBool go_left;
    sfBool go_right;
    sfImage *image;
} map_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfText *text;
    int sel;
} button_t;

typedef struct button_sprite_s {
    sfIntRect form;
    sfRectangleShape *rect;
    sfSprite *sprite;
    sfTexture *texture;
} button_sprite_t;

typedef struct rect_s {
    sfSprite *sprite;
    sfIntRect rect;
} rect_t;

typedef struct music_s {
    sfMusic *music_menu;
    sfMusic *music_game;
    sfMusic *music_battle;
    sfSoundBuffer *soundbuf;
    sfSound *sound;
} music_t;

typedef struct game_object_s {
    enum type {
        BG,
        PATH,
        START,
        END,
        TOWER,
        ENEMY,
        ENEMY_DEAD
    } type;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int distance;
} game_object_t;

typedef struct scene_s {
    enum name {
        MENU, GAME, HELP, SETTINGS, PAUSE, GAMEOVER, ZONE_1, INN, SHOP, PLAYER,
        BATTLE, CREDITS
    } name;
    struct game_object_s *objs;
    struct button_s *buttons; struct button_sprite_s *btn_sprite;
    sfText **texts; struct rect_s *rects; struct button_sprite_s *shop_btn;
    struct player_t *player; struct map_t *map;
    int nb_objs; int nb_player; int nb_map; sfText **textscoin;
    int nb_textscoin;
    int nb_buttons; int nb_texts; int nb_test; int nb_rects; int nb_shop_btn;
    int select_tower; int inventory; int nb_txt_shop; int nb_talk;
    int nb_quest_txt; int nb_quest_btn; sfText **txt_quest; sfText **talk_npc;
    sfIntRect box_rect; sfText **txt_shop; int state; int nb_items;
    sfSprite *spriteinventory; sfTexture *textureinventory; sfText **items;
    int invboxnb; sfSprite *spritecoin; sfTexture *texturecoin;
} scene_t;

typedef struct window_s {
    sfVector2i position;
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct items_s {
    int damage;
    int defense;
    int magic;
    int price;
} items_t;

typedef struct global_s {
    struct window_s *window; struct status_menu_s *st; struct rect_s *rects;
    struct music_s *music; float zoom;
    int vol; int fps; int red; int scene; int font; int textbox;
    int text_choice; sfVector2f pos_player; int statu_menu; int statu_door;
    sfVector2f exit_house; int exit; int head; int test;
    sfVector2f enter_village; int count; sfVector2f enter_shop; int bool_exit;
    int npc_shop; int shop_choice; int buy_menu; struct quest_s *quest;
    sfVector2f exit_bii; int talk_shop; sfVector2f exit_shop; int count_shop;
    int text_choice2; int i; int text_zone2; sfBool chest_zone2;
    sfBool pnj2_zone2; items_t *items; sfBool pnj5_zone2; sfBool beat_boss;
    int shopbox; int boxok; sfSprite *spritebox; sfTexture *texturebox;
} global_t;

#endif
