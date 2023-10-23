/*
** EPITECH PROJECT, 2022
** MY RPG
** File description:
** RPG cool game
*/

#include "rpg.h"

global_t *init_global(global_t *g)
{
    g->window = malloc(sizeof(window_t) + 1);
    g->music = init_music(g);
    g->st = init_status_menu(g);
    g->zoom = 1;
    g->npc_shop = 0; g->shop_choice = 0; g->text_choice = 0;
    g->quest = quest_create();
    g->font = 0;
    g->talk_shop = 0;
    g->textbox = 0;
    g->boxok = 0;
    g->shopbox = 0;
    g->items = init_stats_item(g);
    g->beat_boss = sfFalse;
    return (g);
}

void openwindow(scene_t **scenes, global_t *g, int (*loops[4])())
{
    scene_t *scene = scenes[0]; sfClock *clock = sfClock_create();
    keyrepeat(WINDOW->window, sfFalse); sfTime time; float seconds = 0;
    while (sfRenderWindow_isOpen(g->window->window)) {
        while (poll(g->window->window, &g->window->event)) {
            zoom_fct(scenes, g); IS_EVT ? closewin(WINDOW->window) : 0;
            sname == MENU ? ns[menu_events(scene, g)] : 0;
            sname == GAME ? ns[game_events(scene, g)] : 0;
            sname == HELP ? ns[help_events(scene, g)] : 0;
            sname == SETTINGS ? ns[sets_events(scene, g)] : 0;
            sname == PAUSE ? ns[paus_events(scene, g)] : 0;
            sname == ZONE_1 ? ns[first_zone_events(scene, g)] : 0;
            sname == INN ? ns[second_zone_events(scene, g)] : 0;
            sname == SHOP ? ns[third_zone_events(scene, g)] : 0;
            sname == PLAYER ? ns[player_menu_events(scene, g)] : 0;
            sname == BATTLE ? ns[battle_events(scene, g)] : 0;
            sname == CREDITS ? ns[credits_events(scene, g)] : 0;
        } if ((sname == GAME || sname == ZONE_1 || sname == INN ||
        sname == SHOP || sname == CREDITS) && GET_MICROS > 50000)
            loop, rstart(clock); draw_scene(g->window->window, *scene, g);
    }
}

void init_scenes(scene_t **scenes, global_t *g)
{
    init_menu(scenes[0]); init_game(scenes[1], g); init_help(scenes[2]);
    init_settings(scenes[3], g); init_pause(scenes[4]);
    init_first_zone(scenes[5], g); init_second_zone(scenes[6], g);
    init_third_zone(scenes[7], g); init_player_menu(scenes[8], g);
    init_battle(scenes[9], g); init_credits(scenes[10], g);
}

int preparation(void)
{
    scene_t **scenes = malloc(sizeof(scene_t) * 10 + 1);
    global_t *g = malloc(sizeof(global_t) + 1);
    for (int i = 0; i < 11; i++) scenes[i] = malloc(sizeof(scene_t) + 1);
    g = init_global(g); sfVideoMode mode = {1920, 1080, 32};
    g->window->window = create(mode, "My RPG", WIN_SPEC, NULL);
    if (!g->window->window) return 84;
    setfps(g->window->window, 60);
    game_object_t *load = malloc(sizeof(game_object_t) + 1);
    init_obj(load, vect{0, 0}, vect{1.0, 1.0}, "img/loading.png");
    sfRenderWindow_drawSprite(g->window->window, load->sprite, NULL);
    sfRenderWindow_display(g->window->window);
    sfMusic_play(g->music->music_menu); init_scenes(scenes, g);
    int (*loops[4])(scene_t *, global_t *);
    loops[0] = game_loop; loops[1] = zone_1_loop; loops[2] = zone_2_loop;
    loops[3] = zone_3_loop; loops[4] = credits_loop;
    openwindow(scenes, g, loops); free_all(scenes, g);
    return (0);
}

int main(int ac, char **av)
{
    time_t t; srand((unsigned) time(&t));
    if (preparation() == 84) return 84;
    return EXIT_SUCCESS;
}
