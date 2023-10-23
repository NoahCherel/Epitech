/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** scene2.c
*/

#include "rpg.h"

void init_first_zone(scene_t *scene, global_t *g)
{
    scene->name = ZONE_1; scene->nb_player = 1;
    scene->nb_map = 1; scene->inventory = 0;
    scene->nb_texts = 7;
    g->enter_village.x = 900, g->enter_village.y = 480;
    g->exit_bii.x = 900, g->exit_bii.y = 480;
    g->exit_shop.x = 900, g->exit_shop.y = 480;
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    scene->player = malloc(sizeof(player_t) * scene->nb_player + 1);
    scene->map = malloc(sizeof(map_t) * scene->nb_player + 1);
    scene->map->image = sfImage_createFromFile("img/collisions_z1.png");
    init_player(&scene->player[0], g, 1);
    init_map(&scene->map[0], "img/first_zone.png", (sfIntRect){145, 250, 1920,
    1080});
    init_text_map_main(scene, g);
    openinv(scene, g);
}

void init_second_zone(scene_t *scene, global_t *g)
{
    scene->name = INN;
    scene->nb_player = 1;
    scene->nb_map = 1;
    scene->inventory = 0;
    scene->player = malloc(sizeof(player_t) * scene->nb_player + 1);
    scene->map = malloc(sizeof(map_t) * scene->nb_player + 1);
    scene->map->image = sfImage_createFromFile("img/collisions_z2.png");
    init_player(&scene->player[0], g, 0);
    init_map(&scene->map[0], "img/inn.png", (sfIntRect){100, 320, 1920,
    1080});
    openinv(scene, g);
    quest_scene(g, scene);
}

void init_third_zone(scene_t *scene, global_t *g)
{
    scene->name = SHOP; scene->nb_player = 1; scene->nb_map = 1;
    scene->inventory = 0; scene->nb_talk = 1;
    scene->player = malloc(sizeof(player_t) * scene->nb_player + 1);
    scene->map = malloc(sizeof(map_t) * scene->nb_player + 1);
    scene->map->image = sfImage_createFromFile("img/collisions_z3.png");
    init_player(&scene->player[0], g, 0);
    init_map(&scene->map[0], "img/shop.png", (sfIntRect){0, 220, 1920,
    1080});
    scene->texts = malloc(sizeof(sfText *) * scene->nb_texts + 1);
    openinv(scene, g);
    shop_scene(g, scene);
}

void init_credits(scene_t *scene, global_t *g)
{
    scene->name = CREDITS;
    scene->nb_objs = 1;
    scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs + 1);
    init_obj(&scene->objs[0], vect{0, 0}, vect{1.0, 1.0}, "img/credits.png");
}
