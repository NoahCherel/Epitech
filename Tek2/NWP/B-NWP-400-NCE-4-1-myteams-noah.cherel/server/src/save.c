/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myteams-noah.cherel
** File description:
** save
*/

#include "../include/server.h"

bool is_uuid_duplicate(char* uuid)
{
    FILE* fp = fopen(SAVE_FILE_PATH, "rb");
    if (fp == NULL) {
        printf("Failed to open save file.\n");
        return false;
    }
    char line[BUF_SIZE];
    while (fgets(line, BUF_SIZE, fp)) {
        char* saved_uuid = strstr(line, " UUID:");
        if (saved_uuid != NULL && strncmp(saved_uuid + 6, uuid,
        strlen(uuid)) == 0) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}

void write_client_data(FILE *fp, Client *client)
{
    fprintf(fp, "User:%s UUID:%s STATUS:%d\n", client->user_name,
    client->uuid, client->status);
}

void update_client_data(FILE *fp, Client *client)
{
    fseek(fp, 0, SEEK_SET);
    char line[BUF_SIZE];
    bool found = false;
    while (fgets(line, BUF_SIZE, fp)) {
        char* saved_uuid = strstr(line, " UUID:");
        if (saved_uuid != NULL && strncmp(saved_uuid + 6, client->uuid,
        strlen(client->uuid)) == 0) {
            fseek(fp, -(strlen(line)), SEEK_CUR);
            write_client_data(fp, client);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Error: Could not find line with UUID %s\n", client->uuid);
    }
}

void save_clients_data(Client *clients[], int index)
{
    FILE *fp = fopen(SAVE_FILE_PATH, "rb+");
    if (fp == NULL) {
        printf("Failed to open save file.\n");
        return;
    }
    for (int i = 0; i < index; i++) {
        if (!is_uuid_duplicate(clients[i]->uuid)) {
            write_client_data(fp, clients[i]);
        } else {
            update_client_data(fp, clients[i]);
        }
    }
    fclose(fp);
}
