/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ai_commands
*/

#include "../inc/server.h"


/*
orientation == 2 == DOWN
orientation == 3 == LEFT
orientation == 0 == UP
orientation == 1 == RIGHT
*/

void handle_look_function(int sockfd, game_t *game, int id)
{
    Player *player = get_player_by_id(game, id);
    int visionRange = player->level + 1;
    char response[1024];
    sprintf(response, "[");
    int posY = player->pos.y;
    int posX = player->pos.x;
    int orientation = player->orientation;
    int rows = 4;
    int current_row = 1;
    int x, y;
    if (orientation == 0) {
        for (int i = 0; i < rows; i++) {
            x = posX - i;
            y = posY - i;     
            for (int j = 0; j < current_row; j++) {
                if (x < 0) x = game->width + x;
                if (y < 0) y = game->height + y;
                if (x >= game->width) x = x - game->width;
                if (y >= game->height) y = y - game->height;
                if (y >= 0 && y <= game->height && x >= 0 && x <= game->width) {
                    if (game->map[y][x].players > 0) {
                        for (int k = 0; k < game->map[y][x].players; k++) {
                            sprintf(response + strlen(response), " player");
                        }
                    }
                    if (game->map[y][x].food > 0) {
                        for (int k = 0; k < game->map[y][x].food; k++) {
                            sprintf(response + strlen(response), " food");
                        }
                    }
                    if (game->map[y][x].linemate > 0) {
                        for (int k = 0; k < game->map[y][x].linemate; k++) {
                            sprintf(response + strlen(response), " linemate");
                        }
                    }
                    if (game->map[y][x].deraumere > 0) {
                        for (int k = 0; k < game->map[y][x].deraumere; k++) {
                            sprintf(response + strlen(response), " deraumere");
                        }
                    }
                    if (game->map[y][x].sibur > 0) {
                        for (int k = 0; k < game->map[y][x].sibur; k++) {
                            sprintf(response + strlen(response), " sibur");
                        }
                    }
                    if (game->map[y][x].mendiane > 0) {
                        for (int k = 0; k < game->map[y][x].mendiane; k++) {
                            sprintf(response + strlen(response), " mendiane");
                        }
                    }
                    if (game->map[y][x].phiras > 0) {
                        for (int k = 0; k < game->map[y][x].phiras; k++) {
                            sprintf(response + strlen(response), " phiras");
                        }
                    }
                    if (game->map[y][x].thystame > 0) {
                        for (int k = 0; k < game->map[y][x].thystame; k++) {
                            sprintf(response + strlen(response), " thystame");
                        }
                    }
                    if (game->map[y][x].players == 0 && game->map[y][x].food == 0 && game->map[y][x].linemate == 0 && game->map[y][x].deraumere == 0 && game->map[y][x].sibur == 0 && game->map[y][x].mendiane == 0 && game->map[y][x].phiras == 0 && game->map[y][x].thystame == 0) {
                        sprintf(response + strlen(response), ",");
                    }
                    sprintf(response + strlen(response), ",");
                }
                x++;
            }
            current_row += 2;
        }
    }
    if (orientation == 2) {
        for (int i = 0; i < rows; i++) {
            x = posX + i;
            y = posY + i;     
            for (int j = 0; j < current_row; j++) {
                if (x < 0) x = game->width + x;
                if (y < 0) y = game->height + y;
                if (x >= game->width) x = x - game->width;
                if (y >= game->height) y = y - game->height;
                if (y >= 0 && y < game->height && x >= 0 && x < game->width) {
                    if (game->map[y][x].players > 0) {
                        for (int k = 0; k < game->map[y][x].players; k++) {
                            sprintf(response + strlen(response), " player");
                        }
                    }
                    if (game->map[y][x].food > 0) {
                        for (int k = 0; k < game->map[y][x].food; k++) {
                            sprintf(response + strlen(response), " food");
                        }
                    }
                    if (game->map[y][x].linemate > 0) {
                        for (int k = 0; k < game->map[y][x].linemate; k++) {
                            sprintf(response + strlen(response), " linemate");
                        }
                    }
                    if (game->map[y][x].deraumere > 0) {
                        for (int k = 0; k < game->map[y][x].deraumere; k++) {
                            sprintf(response + strlen(response), " deraumere");
                        }
                    }
                    if (game->map[y][x].sibur > 0) {
                        for (int k = 0; k < game->map[y][x].sibur; k++) {
                            sprintf(response + strlen(response), " sibur");
                        }
                    }
                    if (game->map[y][x].mendiane > 0) {
                        for (int k = 0; k < game->map[y][x].mendiane; k++) {
                            sprintf(response + strlen(response), " mendiane");
                        }
                    }
                    if (game->map[y][x].phiras > 0) {
                        for (int k = 0; k < game->map[y][x].phiras; k++) {
                            sprintf(response + strlen(response), " phiras");
                        }
                    }
                    if (game->map[y][x].thystame > 0) {
                        for (int k = 0 ; k < game->map[y][x].thystame; k++) {
                            sprintf(response + strlen(response), " thystame");
                        }
                    }
                    if (game->map[y][x].players == 0 && game->map[y][x].food == 0 && game->map[y][x].linemate == 0 && game->map[y][x].deraumere == 0 && game->map[y][x].sibur == 0 && game->map[y][x].mendiane == 0 && game->map[y][x].phiras == 0 && game->map[y][x].thystame == 0) {
                        sprintf(response + strlen(response), ",");
                    }
                    sprintf(response + strlen(response), ",");
                }
                x--;
            }
            current_row += 2;
        }
    }
    if (orientation == 1) {
        for (int i = 0; i < rows; i++) {
            x = posX + i;
            y = posY - i;
            for (int j = 0; j < current_row; j++) {
                if (x < 0) x = game->width + x;
                if (y < 0) y = game->height + y;
                if (x >= game->width) x = x - game->width;
                if (y >= game->height) y = y - game->height;
                if (y >= 0 && y < game->height && x >= 0 && x < game->width) {
                    if (game->map[y][x].players > 0) {
                        for (int k = 0; k < game->map[y][x].players; k++) {
                            sprintf(response + strlen(response), " player");
                        }
                    }
                    if (game->map[y][x].food > 0) {
                        for (int k = 0; k < game->map[y][x].food; k++) {
                            sprintf(response + strlen(response), " food");
                        }
                    }
                    if (game->map[y][x].linemate > 0) {
                        for (int k = 0; k < game->map[y][x].linemate; k++) {
                            sprintf(response + strlen(response), " linemate");
                        }
                    }
                    if (game->map[y][x].deraumere > 0) {
                        for (int k = 0; k < game->map[y][x].deraumere; k++) {
                            sprintf(response + strlen(response), " deraumere");
                        }
                    }
                    if (game->map[y][x].sibur > 0) {
                        for (int k = 0; k < game->map[y][x].sibur; k++) {
                            sprintf(response + strlen(response), " sibur");
                        }
                    }
                    if (game->map[y][x].mendiane > 0) {
                        for (int k = 0; k < game->map[y][x].mendiane; k++) {
                            sprintf(response + strlen(response), " mendiane");
                        }
                    }
                    if (game->map[y][x].phiras > 0) {
                        for (int k = 0; k < game->map[y][x].phiras; k++) {
                            sprintf(response + strlen(response), " phiras");
                        }
                    }
                    if (game->map[y][x].thystame > 0) {
                        for (int k = 0 ; k < game->map[y][x].thystame; k++) {
                            sprintf(response + strlen(response), " thystame");
                        }
                    }
                    if (game->map[y][x].players == 0 && game->map[y][x].food == 0 && game->map[y][x].linemate == 0 && game->map[y][x].deraumere == 0 && game->map[y][x].sibur == 0 && game->map[y][x].mendiane == 0 && game->map[y][x].phiras == 0 && game->map[y][x].thystame == 0) {
                        sprintf(response + strlen(response), ",");
                    }
                    sprintf(response + strlen(response), ",");
                }
                y++;
            }
            x++;
            y--;
            current_row += 2;
        }
    }
    if (orientation == 3) {
        for (int i = 0; i < rows; i++) {
            x = posX - i;
            y = posY + i;        
            for (int j = 0; j < current_row; j++) {
                //printf("x: %d, y: %d\n", x, y);
                if (x < 0) x = game->width + x;
                if (y < 0) y = game->height + y;
                if (x >= game->width) x = x - game->width;
                if (y >= game->height) y = y - game->height;
                if (y >= 0 && y < game->height && x >= 0 && x < game->width) {
                    if (game->map[y][x].players > 0) {
                        for (int k = 0; k < game->map[y][x].players; k++) {
                            sprintf(response + strlen(response), " player");
                        }
                    }
                    if (game->map[y][x].food > 0) {
                        for (int k = 0; k < game->map[y][x].food; k++) {
                            sprintf(response + strlen(response), " food");
                        }
                    }
                    if (game->map[y][x].linemate > 0) {
                        for (int k = 0; k < game->map[y][x].linemate; k++) {
                            sprintf(response + strlen(response), " linemate");
                        }
                    }
                    if (game->map[y][x].deraumere > 0) {
                        for (int k = 0; k < game->map[y][x].deraumere; k++) {
                            sprintf(response + strlen(response), " deraumere");
                        }
                    }
                    if (game->map[y][x].sibur > 0) {
                        for (int k = 0; k < game->map[y][x].sibur; k++) {
                            sprintf(response + strlen(response), " sibur");
                        }
                    }
                    if (game->map[y][x].mendiane > 0) {
                        for (int k = 0; k < game->map[y][x].mendiane; k++) {
                            sprintf(response + strlen(response), " mendiane");
                        }
                    }
                    if (game->map[y][x].phiras > 0) {
                        for (int k = 0; k < game->map[y][x].phiras; k++) {
                            sprintf(response + strlen(response), " phiras");
                        }
                    }
                    if (game->map[y][x].thystame > 0) {
                        for (int k = 0 ; k < game->map[y][x].thystame; k++) {
                            sprintf(response + strlen(response), " thystame");
                        }
                    }
                    if (game->map[y][x].players == 0 && game->map[y][x].food == 0 && game->map[y][x].linemate == 0 && game->map[y][x].deraumere == 0 && game->map[y][x].sibur == 0 && game->map[y][x].mendiane == 0 && game->map[y][x].phiras == 0 && game->map[y][x].thystame == 0) {
                        sprintf(response + strlen(response), ",");
                    }
                    sprintf(response + strlen(response), ",");
                }
                y--;
            }
            x--;
            y++;
            current_row += 2;
        }
    }
    int commas = 0;
    int i = 0;
    while (commas < visionRange) {
        if (response[i] == ',') commas++;
        i++;
    }
    response[i] = '\0';
    sprintf(response + strlen(response), " ]\n");



    printf("%s", response);
    send(sockfd, response, strlen(response), 0);
}

void move_forward(int sockfd, game_t *game, int id)
{
    Player *player = get_player_by_id(game, id);
    int x = player->pos.x;
    int y = player->pos.y;
    int direction = player->orientation;
    if (direction == 0) y = y - 1;
    if (direction == 1) x = x + 1;
    if (direction == 2) y = y + 1;
    if (direction == 3) x = x - 1;
    if (x < 0) x = game->width + x;
    if (y < 0) y = game->height + y;
    if (x >= game->width) x = x - game->width;
    if (y >= game->height) y = y - game->height;
    game->map[y][x].players = game->map[y][x].players + 1;
    game->map[player->pos.y][player->pos.x].players = game->map[player->pos.y][player->pos.x].players - 1;
    player->pos.x = x;
    player->pos.y = y;
    send(sockfd, "ok\n", 3, 0);
}

void turn_right(int sockfd, game_t *game, int id)
{
    Player *player = get_player_by_id(game, id);
    player->orientation = player->orientation + 1;
    if (player->orientation > 3)
        player->orientation = 0;
    
    if (player->orientation == 0)
        player->orientation = 1;
    if (player->orientation == 1)
        player->orientation = 2;
    if (player->orientation == 2)
        player->orientation = 3;
    if (player->orientation == 3)
        player->orientation = 0;
    send(sockfd, "ok\n", 3, 0);
}

void turn_left(int sockfd, game_t *game, int id)
{
    Player *player = get_player_by_id(game, id);
    player->orientation = player->orientation - 1;
    if (player->orientation < 0)
        player->orientation = 3;

    if (player->orientation == 0)
        player->orientation = 3;
    if (player->orientation == 1)
        player->orientation = 0;
    if (player->orientation == 2)
        player->orientation = 1;
    if (player->orientation == 3)
        player->orientation = 2;
        
    send(sockfd, "ok\n", 3, 0);
}

void player_death(game_t *game, int id)
{
    if (game->teams->players[id].timeleft <= 0) {
        game->teams->players[id].isdead = true;
        send(game->teams->players[id].sockfd, "dead\n", 5, 0);
    }
}