/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-noah.cherel
** File description:
** ftp_commands1
*/

#include "../include/ftp_server.h"

void list_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n")); return;
    } else {
        char* dir_path = getcwd(NULL, 0); DIR* dir = opendir(dir_path);
        struct dirent* entry;
        if (dir == NULL) {
            write(client->fd, "550 Failed to open directory.\r\n",
            strlen("550 Failed to open directory.\r\n")); return;
        }
        write(client->fd, "150 Here comes the directory listing.\r\n",
        strlen("150 Here comes the directory listing.\r\n"));
        while ((entry = readdir(dir)) != NULL) {
            write(client->fd, entry->d_name, strlen(entry->d_name));
            write(client->fd, "\r\n", strlen("\r\n"));
        }
        closedir(dir);
        write(client->fd, "226 Directory listing complete.\r\n",
        strlen("226 Directory listing complete.\r\n"));
    }
}

void stor_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n")); return;
    }
    char *filename = strtok(buffer, " "); char filepath[256];
    write(client->fd, "150 Starting upload.\r\n",
    strlen("150 Starting upload.\r\n")); printf("Filename: %s 1\n", filename);
    snprintf(filepath, sizeof(filepath), "%s/%s", serv->path, filename);
    FILE *file = fopen(filepath, "wb");
    if (file == NULL) {
        printf("Error opening file for writing\n"); return;
    }
    char data[1024]; int nbytes;
    while ((nbytes = read(client->fd, data, sizeof(data))) > 0) {
        fwrite(data, sizeof(char), nbytes, file);
    }
    fclose(file); return; write(client->fd, "226 Upload complete.\r\n",
    strlen("226 Upload complete.\r\n"));
}

void port_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
            strlen("530 Please login with USER and PASS.\r\n")); return;
    } else if (client->mode == ACTIVE) {
        write(client->fd, "500 Illegal PORT.\r\n",
            strlen("500 Illegal PORT.\r\n")); return;
    } else {
        int ip1, ip2, ip3, ip4, port1, port2;
        if (sscanf(buffer, "PORT %d,%d,%d,%d,%d,%d", &ip1, &ip2, &ip3,
        &ip4, &port1, &port2) != 6) {
            write(client->fd, "500 Invalid PORT command\r\n",
                strlen("500 Invalid PORT command\r\n")); return;
        }
        client->data_addr.sin_family = AF_INET;
        client->data_addr.sin_port = htons(port1 * 256 + port2);
        client->data_addr.sin_addr.s_addr = htonl((ip1 << 24) | (ip2 << 16) |
        (ip3 << 8) | ip4);
        client->mode = ACTIVE; return;
    }
}
