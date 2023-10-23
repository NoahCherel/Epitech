/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myteams-noah.cherel
** File description:
** login
*/

#include "../include/server.h"

char *get_rest_of_string(char *input)
{
    char *space = strchr(input, ' ');
    if (space != NULL) {
        return space + 1;
    } else {
        return NULL;
    }
}

bool search_username_in_file(const char* username, Client* client)
{
    bool usr_fo = false;
    FILE* fp = fopen(SAVE_FILE_PATH, "r");
    if (fp == NULL) return false;
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        const char* pos = strstr(line, "User:");
        const char* end_pos = NULL; int len = 0; char uuid_str[37];
        if (pos != NULL) {
            pos += 5; end_pos = strstr(pos, " UUID:");
        }
        if (end_pos != NULL) len = end_pos - pos;
        if (end_pos != NULL &&
            len == strlen(username) && strncmp(pos, username, len) == 0) {
            end_pos += 6; strncpy(uuid_str, end_pos, 36);
            uuid_str[36] = '\0'; client->uuid = strdup(uuid_str);
            usr_fo = true; break;
        }
    } fclose(fp); return usr_fo;
}

void create_new_user(const char *username, Client *client)
{
    uuid_t uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);
    client->uuid = strdup(uuid_str);
    client->status = 1;
    FILE *fp = fopen(SAVE_FILE_PATH, "ab");
    if (fp != NULL) {
        fprintf(fp, "User:%s UUID:%s STATUS:%i\n", username, client->uuid,
        client->status);
        fclose(fp);
    } else {
        printf("Failed to open save file.\n");
    }
}

Client* login_client(Client *clients[], int index)
{
    char *username = get_rest_of_string(clients[index]->buffer);
    bool usr_fo = search_username_in_file(username, clients[index]);
    if (!usr_fo) {
        create_new_user(username, clients[index]);
        server_event_user_created(clients[index]->uuid, username);
    } else {
        server_event_user_logged_in(clients[index]->uuid);
    }
    clients[index]->status = 1;
    clients[index]->user_name = strdup(username);
    memset(clients[index]->buffer, 0, BUF_SIZE);
    return clients[index];
}
