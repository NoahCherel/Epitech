/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myteams-noah.cherel
** File description:
** serv_client
*/

#include "../include/server.h"

int send_data_team(struct Client *client)
{
    char message[1024];
    snprintf(message, sizeof(message), "Team:%s UUID:%s DESC:%s",
    client->team->name, client->team->uuid, client->team->description);
    send(client->sockfd, message, strlen(message), 0);
    return 0;
}

void save_team_data(Team *team)
{
    FILE *fp = fopen("save1.txt", "a");
    if (fp == NULL) {
        printf("Failed to open file.\n"); return;
    }
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) != 0) fprintf(fp, "\n");
    fprintf(fp, "TEAM:%s DESC:%s UUID:%s\n", team->name,
    team->description, team->uuid);
    fclose(fp);
}

int handle_command(Client *clients[], int index, char *command, int i)
{
    Command1 commands[] = {
        {"/login", handle_login1},
        {"/logout", handle_logout1},
        {"/users", handle_send_users_data1},
        {"/create", handle_create_team1}
    };
    bool command_found = false;
    for (int j = 0; j < sizeof(commands) / sizeof(commands[0]); j++) {
        if (strcmp(command, commands[j].command) == 0) {
            index = commands[j].action(clients, index, i);
            command_found = true;
            break;
        }
    }
    if (!command_found) {
        printf("Unknown command.\n");
    }
    return index;
}

int handle_client_data(Client *clients[], int index, fd_set *readfds)
{
    for (int i = 0; i < index; i++) {
        if (!FD_ISSET(clients[i]->sockfd, readfds)) continue;
        int bytes_received = recv(clients[i]->sockfd, clients[i]->buffer,
        BUF_SIZE, 0);
        if (bytes_received == 0) {
            save_clients_data(clients, index);
            remove_client(clients, i); index--; continue;
        }
        char buffer_copy[BUF_SIZE]; strcpy(buffer_copy, clients[i]->buffer);
        char *command = strtok(buffer_copy, " ");
        if (command == NULL) continue;
        index = handle_command(clients, index, command, i);
    }
    return index;
}
