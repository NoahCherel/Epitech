/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** answersCommands
*/

#include "../inc/server.h"

command_function_t commands[] = {
    {"GRAPHIC", handle_graphic},
    {"msz", handle_msz},
    {"bct", handle_bct},
    {"mct", handle_mct},
    {"tna", handle_tna},
    {"plv", handle_plv},
    {"ppo", handle_ppo},
    {"pin", handle_pin},
    {"sgt", handle_sgt}
};

command_function_ai_t ai_commands[] =
{
    {"Look", handle_look_function},
    {"Forward", handle_forward_function},
    {"Right", handle_right_function},
    {"Left", handle_left_function},
    {"Inventory", handle_inventory_function},
    {"Incantation", handle_incantation_function},
    {"Fork", handle_fork_function},
    /*{"Connect_nbr", handle_connect_nbr_function},
    {"Eject", handle_eject_function},*/
};

command_function_ai_arg_t ai_args[] =
{
    {"Take", handle_takeObject_function},
    {"Set", handle_setObject_function},
};

char *get_team_name(char *msg, game_t *game)
{
    for (int i = 0; i < game->teamsNb; i++) {
        if (strcmp(game->teamNames[i], msg) == 0) {
            return (game->teamNames[i]);
        }
    }
    return NULL;
}

Player *get_player_by_id(game_t *game, int playerId)
{
    for (int i = 0; i < game->teamsNb; i++) {
        for (int j = 0; j < game->num_players; j++) {
            if (game->teams[i].players[j].id == playerId) {
                return (&game->teams[i].players[j]);
            }
        }
    }
    return NULL;
}

void update_gui(game_t *game, char *command, int playerId)
{
    if (command == NULL) {
        printf("Error: command is NULL\n");
        return;
    }
    if (strcmp(command, "Forward") == 0) {
        send_player_pos(game->graphicSockfd, game, playerId);
    }
    else if (strcmp(command, "Right") == 0)
        send_player_pos(game->graphicSockfd, game, playerId);
    else if (strcmp(command, "Left") == 0)
        send_player_pos(game->graphicSockfd, game, playerId);
    else if (strcmp(command, "Inventory") == 0)
        send_player_inventory(game->graphicSockfd, game, playerId);
    else if (strcmp(command, "Incantation") == 0)
        send_player_level(game->graphicSockfd, game, playerId);
}

int find_player_by_sockfd(game_t *game, int sockfd)
{
    for (int i = 0; i < game->teamsNb; i++) {
        for (int j = 0; j < game->num_players; j++) {
            if (game->teams[i].players[j].sockfd == sockfd) {
                return (game->teams[i].players[j].id);
            }
        }
    }
    return -1;
}

void execute_ai_command(command_queue_t* ai_command_queue, game_t* game)
{
    if (is_queue_empty(ai_command_queue))
        return;
    command_queue_item_t command = dequeue(ai_command_queue);
    int current_time = get_current_time();
    printf("AI command timer: %d\n", command.timer);
    printf("Current time: %d\n", current_time);
    if (command.timer > current_time) {
        printf("AI command timer not reached\n");
        requeue(ai_command_queue, command);
        return;
    } else {
        printf("AI command timer reached\n");
    }
    int player_id = find_player_by_sockfd(game, command.sockfd);
    for (size_t i = 0; i < sizeof(ai_commands) / sizeof(ai_commands[0]); i++) {
        if (strcmp(command.command, ai_commands[i].command) == 0) {
            ai_commands[i].function(command.sockfd, game, player_id);
            update_gui(game, ai_commands[i].command, player_id); break;
        }
    }
}

void handle_all_commands(int sockfd, game_t* game, char* msg,
command_queue_t* ai_command_queue)
{
    if (strlen(msg) > 3) game->playerId = atoi(&msg[4]);
    bool command_found = false;
    msg[strlen(msg) - 1] = '\0';
    for (size_t i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        if (strcmp(msg, commands[i].command) == 0) {
            commands[i].function(sockfd, game);
            command_found = true;
            break;
        }
    }
    if (!command_found) {
        for (size_t i = 0; i < sizeof(ai_commands) / sizeof(ai_commands[0]); i++) {
            if (strcmp(msg, ai_commands[i].command) == 0) {
                if (is_queue_full(ai_command_queue)) {
                    printf("AI command queue is full\n");
                    return;
                }
                enqueue(ai_command_queue, msg, sockfd, game);
                command_found = true;
                break;
            }
        }
    }
    if (!command_found) {
        for (size_t i = 0; i < sizeof(ai_args) / sizeof(ai_args[0]); i++) {
            printf("Command '%s' received\n", msg);
            char *msg_copy = strdup(msg);
            char* token = strtok(msg_copy, " ");
            if (strcmp(token, ai_args[i].command) == 0) {
                char *after_space = strchr(msg, ' ');
                after_space++;
                printf("Command AI with params '%s' received\n", msg);
                int player_id = find_player_by_sockfd(game, sockfd);

                ai_args[i].function(sockfd, game, player_id, after_space);
                command_found = true;
                break;
            }
        }
    }
    if (!command_found) {
        for (int i = 0; i < game->teamsNb; i++) {
            if (strcmp(msg, game->teamNames[i]) == 0) {
                int id = add_player_to_team(game, msg, sockfd);
                team_players_left_slot(sockfd, game, msg);
                send_map_size_player(sockfd, game);
                handle_pnw(game->graphicSockfd, game, id);
                command_found = true;
                break;
            }
        }
    }
    if (!command_found) {
        char *msg_copy = strdup(msg);
        char* token = strtok(msg_copy, " ");
        if (strcmp(token, "Broadcast") == 0) {
            char *after_space = strchr(msg, ' ');
            after_space++;
            handle_broadcast_message(sockfd, after_space, game);
            command_found = true;
        }
    }

    if (!command_found) {
        printf("Command '%s' not found\n", msg);
        send_ko(sockfd);
        return;
    }
}