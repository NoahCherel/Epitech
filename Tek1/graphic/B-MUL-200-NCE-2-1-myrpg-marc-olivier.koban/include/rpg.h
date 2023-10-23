/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>

    #include "macro.h"
    #include "struct.h"

/*game.c*/
int moove_player(int dir, scene_t* scene, global_t *g);
int condition_pixel(global_t *g, scene_t *scene);

/*inventory*/
void openinv(scene_t *scene, global_t *g);
void init_buttoninv(button_t *button, sfVector2f position, char *text);
void event_inv(global_t *g, scene_t *scene);
void createitem(global_t *scene, int imgnb);
void buy_item(scene_t *scene, global_t *g);

/*inventory2*/
void close_btn_inv(scene_t *scene, global_t *g);

/*loop*/
int game_loop(scene_t *scene, global_t *g);
int zone_1_loop(scene_t *scene, global_t *g);
int zone_2_loop(scene_t *scene, global_t *g);
int zone_3_loop(scene_t *scene, global_t *g);
int credits_loop(scene_t *scene, global_t *g);

/*map.c*/
map_t *init_map(map_t *map, char *the_map, sfIntRect rect);

/*pixel*/
int condition_getpixel(global_t *g, map_t *map);
int condition_pixel_red(global_t *g, map_t *map);
int condition_pixel_blue(global_t *g, map_t *map);
int condition_pixel_green(global_t *g, map_t *map);

/*player*/
player_t *init_player(player_t *player, global_t *g, int facing);
void change_sprt(player_t *p, int sx, int sy);
void player_update(global_t *g, scene_t *scene);
void color_switch(int color, global_t *g);
void coininv(scene_t *scene, global_t *g);

/*options_menu*/
void init_settings_v2(scene_t *scene, global_t *g);
void init_btn_mod(button_sprite_t *button, sfVector2f position, char *file,
sfVector2f size);
rect_t init_rect_mod(sfVector2f sz, sfVector2f rs, sfVector2f pos, char *file);
void change_text(scene_t *scene, global_t *g);

/*settings.c*/
void set_volume(scene_t *scene, global_t *g);
void set_fps(scene_t *scene, global_t *g);
void setup_action_button(scene_t *scene, int i, int left, global_t *g);
void setup_fps(scene_t *scene, int fps, int i, global_t *g);
void color_fps(scene_t *scene, global_t *g, int i, int nb);

/*settings2.c*/
int set_box(scene_t *scene, int i, global_t *g);

/*free_all*/
void free_all(scene_t **scenes, global_t *g);

/*utils*/
void my_putstr(char const *str);
char *my_inttostr(int num);
int my_strlen(char const *str);
int get_file_size(char *file_name);
char *get_content_of_file(char *file_name);

/*utils2*/
void my_putchar(char c);
void my_put_nbr(int nb);
void zoom_fct(scene_t **scenes, global_t *g);
char *my_strcat(char *dest, char const *src);

/*button_sel.c*/
void sel_bt(button_t *buttons, int i);
void unsel_bt(button_t *buttons, int i);

/*button.c*/
void init_button(button_t *button, sfVector2f position, char *text, int sel);
int button_click(sfRectangleShape *rect, sfVector2i mouse_pos);
int button_is_hovered(sfRectangleShape *rect, sfRenderWindow *window);
void init_buttonsettings(button_t *button, sfVector2f position, char *text);

/*display_game*/
void draw_scene(sfRenderWindow *window, struct scene_s scene, global_t *g);
void draw_scene2(sfRenderWindow *window, struct scene_s scene, global_t *g);
void draw_scene3(sfRenderWindow *window, struct scene_s scene, global_t *g);
void draw_scene4(sfRenderWindow *w, struct scene_s s, global_t *g, int i);

/*events.c*/
int game_events(scene_t *scene, global_t *g);
int help_events(scene_t *scene, global_t *g);
int sets_events(scene_t *scene, global_t *g);
int paus_events(scene_t *scene, global_t *g);
int first_zone_events(scene_t *scene, global_t *g);

/*events2.c*/
int get_game_scene(global_t *g);
int second_zone_events(scene_t *scene, global_t *g);
int third_zone_events(scene_t *scene, global_t *g);
int first_zone_event2(global_t *g, scene_t *scene);
int player_menu_events(scene_t *scene, global_t *g);

/*events3.c*/
int third_zone_events2(scene_t *scene, global_t *g);
void button_shop(scene_t *scene, global_t *g);
void pause_button(scene_t *scene, global_t *g);

/*game_events/events4.c*/
int condition_battle(global_t *g);
int first_zone_events3(global_t *g, scene_t *scene);
int credits_events(scene_t *scene, global_t *g);

/*game_objet.c*/
void init_obj(game_object_t *obj, sfVector2f pos, sfVector2f sz, char *file);

/*main.c*/
int preparation(void);
void openwindow(scene_t **scenes, global_t *g, int (*loops[3])());
void init_scenes(scene_t **scenes, global_t *g);
global_t *init_global(global_t *g);

/*menu.c*/
void init_menu(scene_t *scene);
void change_sel(scene_t *scene, global_t *g);
int key_pressed(scene_t *scene, global_t *g);
int menu_events(scene_t *scene, global_t *g);
void select_button(scene_t *scene, int n);

/*scene.c*/
void init_help(scene_t *scene);
void init_settings(scene_t *scene, global_t *g);
void init_pause(scene_t *scene);
void init_game(scene_t *scene, global_t *g);

/*scene2.c*/
void init_first_zone(scene_t *scene, global_t *g);
void init_second_zone(scene_t *scene, global_t *g);
void init_third_zone(scene_t *scene, global_t *g);
void init_credits(scene_t *scene, global_t *g);

/*sound.c*/
music_t *init_music(global_t *g);

/*text_game*/
void choice_text(global_t *g);
void choice_text_2(global_t *g);
void init_text_game(scene_t *scene, global_t *g);
void init_text_map_main(scene_t *scene, global_t *g);
int event_text(global_t *g, int i);

/*text.c*/
sfText *init_txt(sfVector2f pos, int size, char *text, char *font);
sfText *txt2(sfVector2f pos, int size, char *text, char *font);
char *choice_font(int i);
int font_size(int i);
sfVector2f font_pos(int i);

/*game/player_menu*/
void init_player_menu(scene_t *scene, global_t *g);
status_menu_t *init_status_menu(global_t *g);
void update_player_menu(scene_t *scene, global_t *g);

/*game/battle*/
void init_battle(scene_t *scene, global_t *g);
int key_pressed_battle(scene_t *scene, global_t *g);
int battle_events(scene_t *scene, global_t *g);

/*game/attack*/
int attack(scene_t *scene, global_t *g);
int attack_events(scene_t *scene, global_t *g);

/*game/attack2*/
int attack3_events(scene_t *scene, global_t *g);
void game_won(scene_t *scene, global_t *g);

/*game/magic*/
int magic(scene_t *scene, global_t *g);
int magic_events(scene_t *scene, global_t *g);

/*game/object*/
int object(scene_t *scene, global_t *g);
int object_events(scene_t *scene, global_t *g);

/*shop_menu*/
void interaction_npc(global_t *g);
void shop_mnu(global_t *g);
void shop_scene2(global_t *g, scene_t *scene);
void shop_scene(global_t *g, scene_t *scene);
void buy_menu(global_t *g);

/*game/quest*/
quest_t *quest_create(void);
void interaction_quest(global_t *g);
void quest_mnu(global_t *g);
void quest_scene(global_t *g, scene_t *scene);
void event_btn_quest(global_t *g, scene_t *s);

/*game/quest2*/
void end_quest2(global_t *g);

/*game/quest_interaction*/
void reminder_quest(global_t *g);
void reminder_mnu(global_t *g);
int end_quest(global_t *g);
void win_mnu(global_t *g);

/*game/text/text_game2.c*/
void choice_text_3(global_t *g);
void init_text_scene2(scene_t *scene, global_t *g);
void init_text_scene2_2(scene_t *scene, global_t *g);
void choice_text_3_2(global_t *g);
void choice_text_2_2(global_t *g);

/*game/text/text2.c*/
sfText *init_txt_gain(sfVector2f pos, sfVector2f size_gain, char *font,
int ty);
sfBool chest_text(sfVector2f choice_gain, sfBool a, global_t *g, int bonus);
sfBool double_text_exp(sfVector2f choice_gain, sfBool a, global_t *g, int bon);
sfBool double_text_coins(sfVector2f c_gain, sfBool a, global_t *g, int bon);
void simple_text(int text_choice, global_t *g);

/*game/item_description*/
void item_description(struct scene_s scene, global_t *g);
items_t *init_stats_item(global_t *g);

/*game/shop_menu2*/
void shop_scene3(global_t *g, scene_t *scene);

#endif
