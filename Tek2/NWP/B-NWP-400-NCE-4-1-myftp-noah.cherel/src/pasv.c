/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** pasv
*/

#include "../include/ftp_server.h"

int create_data_socket(void)
{
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) {
        printf("Error creating data socket\n"); return -1;
    }
    struct sockaddr_in data_addr; memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET; data_addr.sin_addr.s_addr = INADDR_ANY;
    data_addr.sin_port = 0;
    if (bind(data_socket, (struct sockaddr *)&data_addr, sizeof(data_addr))
    == -1) {
        printf("Error binding data socket\n"); close(data_socket);
        return -1;
    }
    if (listen(data_socket, 1) == -1) {
        printf("Error listening on data socket\n"); close(data_socket);
        return -1;
    }
    return data_socket;
}

int get_socket_name(int socket, struct sockaddr_in *addr)
{
    socklen_t addr_len = sizeof(*addr);
    if (getsockname(socket, (struct sockaddr *)addr, &addr_len) == -1) {
        printf("Error getting data socket name\n");
        return -1;
    }
    return ntohs(addr->sin_port);
}

void send_passive_response(client_t *client, int port)
{
    char response[256];
    snprintf(response, sizeof(response),
    "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\r\n",
    127, 0, 0, 1, port / 256, port % 256);
    write(client->fd, response, strlen(response));
}

void pasv_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        write(client->fd, "530 Please login with USER and PASS.\r\n",
        strlen("530 Please login with USER and PASS.\r\n")); return;
    } else if (client->mode == PASSIVE) {
        write(client->fd, "500 Illegal PASV.\r\n",
        strlen("500 Illegal PASV.\r\n")); return;
    } else {
        int data_socket = create_data_socket();
        if (data_socket == -1) return;
        struct sockaddr_in data_addr_out;
        int data_port = get_socket_name(data_socket, &data_addr_out);
        if (data_port == -1) {
            close(data_socket); return;
        }
        send_passive_response(client, data_port);
        serv->data_socket = data_socket; client->mode = PASSIVE;
        return;
    }
}
