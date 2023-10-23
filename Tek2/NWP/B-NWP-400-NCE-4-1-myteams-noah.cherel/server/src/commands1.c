/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myteams-noah.cherel
** File description:
** commands1
*/

#include "../include/server.h"

void create_team(Client *client)
{
    char *name = strtok(NULL, " ");
    char *description = strtok(NULL, "\0");
    if (name == NULL || description == NULL) {
        printf("Invalid command.\n");
        return;
    }
    Team *team = malloc(sizeof(Team));
    team->name = name;
    team->description = description;
    uuid_t uuid; uuid_generate(uuid);
    char uuid_str[37]; uuid_unparse(uuid, uuid_str); team->uuid = uuid_str;
    server_event_team_created(team->uuid, team->name, client->uuid);
    save_team_data(team);
    client->team = team;
    send_data_team(client);
}

int handle_login1(Client *clients[], int index, int i)
{
    clients[i] = login_client(clients, i);
    save_clients_data(clients, index);
    send_data(clients[i]);
    return index;
}

int handle_logout1(Client *clients[], int index, int i)
{
    clients[i]->status = 0;
    save_clients_data(clients, index);
    server_event_user_logged_out(clients[i]->uuid);
    remove_client(clients, i);
    return index - 1;
}

int handle_send_users_data1(Client *clients[], int index, int i)
{
    send_data(clients[i]);
    return index;
}

int handle_create_team1(Client *clients[], int index, int i)
{
    create_team(clients[i]);
    return index;
}
