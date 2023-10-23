/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** retr
*/

#include "../include/ftp_server.h"

void send_ftp_response(int fd, const char *message)
{
    write(fd, message, strlen(message));
}

int send_file(int data_fd, FILE *file, int client_fd)
{
    char data[1024];
    size_t bytes_read;
    while ((bytes_read = fread(data, 1, sizeof(data), file)) > 0) {
        if (write(data_fd, data, bytes_read) != bytes_read) {
            send_ftp_response(client_fd,
            "426 Connection closed; transfer aborted.\r\n");
            return 0;
        }
    }
    return 1;
}

int get_data_fd(server_t *serv, client_t *client)
{
    if (client->mode == 0) {
        send_ftp_response(client->fd, "425 Use PORT or PASV first.\r\n");
        return -1;
    }
    int data_fd; struct sockaddr_in data_addr;
    socklen_t data_addr_len = sizeof(data_addr);
    if (client->mode == PASSIVE) {
        data_fd = accept(serv->data_socket,
        (struct sockaddr *)&data_addr, &data_addr_len); serv->data_socket = -1;
    } else {
        data_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (connect(data_fd, (struct sockaddr *)&client->data_addr,
        sizeof(client->data_addr)) == -1) close(data_fd); data_fd = -1;
    }
    if (data_fd == -1) {
        send_ftp_response(client->fd,
        "425 Failed to establish connection.\r\n");
    }
    return data_fd;
}

void retr_function_ftp(server_t *serv, client_t *client, char *buffer)
{
    if (client->logged == 0) {
        send_ftp_response(client->fd,
        "530 Please login with USER and PASS.\r\n"); return;
    }
    int data_fd = get_data_fd(serv, client);
    if (data_fd == -1) return;
    FILE *file = fopen(buffer + 5, "r");
    if (!file) {
        send_ftp_response(client->fd, "550 File not found.\r\n");
        close(data_fd); return;
    }
    char response[256]; snprintf(response, sizeof(response),
    "150 Opening BINARY mode data connection for %s.\r\n", buffer + 5);
    send_ftp_response(client->fd, response);
    if (!send_file(data_fd, file, client->fd)) {
        close(data_fd); fclose(file); return;
    }
    close(data_fd); fclose(file);
    send_ftp_response(client->fd, "226 Transfer complete.\r\n");
}
