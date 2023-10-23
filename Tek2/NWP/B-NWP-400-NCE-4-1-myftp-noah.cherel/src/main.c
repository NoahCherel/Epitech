/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/ftp_server.h"

void handle_all_command(server_t *serv, char *buffer, client_t *client)
{
    char *command = strtok(buffer, " \r\n");
    char *buff_tab = strtok(NULL, " \r\n");
    if (buff_tab == NULL) {
        buff_tab = " ";
    }
    void (*function[])(server_t *, client_t *,char *) = { quit_function_ftp,
    pwd_function_ftp, user_function_ftp, pass_function_ftp, cwd_function_ftp,
    list_function_ftp, retr_function_ftp, stor_function_ftp, dele_function_ftp,
    pasv_function_ftp, port_function_ftp, noop_function_ftp, help_function_ftp,
    cdup_function_ftp};
    char *command_list[] = {"QUIT", "PWD", "USER", "PASS", "CWD",
            "LIST", "RETR", "STOR", "DELE", "PASV", "PORT", "NOOP", "HELP",
            "CDUP"};
    int num_commands = 14;
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command_list[i], command) == 0) {
            function[i](serv, client, buff_tab);
            return;
        }
    }
}

server_t* init(int argc, char *argv[])
{
    if (argc != 3) {
        help();
        exit(0);
    }
    server_t *serv = malloc(sizeof(server_t));
    serv = init_server(atoi(argv[1]), argv[2]);
    return serv;
}

void setup_select(server_t *serv, fd_set *readfds, struct timeval *timeout)
{
    FD_ZERO(readfds);
    FD_SET(serv->socket, readfds);
    timeout->tv_sec = 1;
    timeout->tv_usec = 0;
}

void handle_client(server_t *serv)
{
    struct sockaddr_in client;
    serv->fd_client = accept(serv->socket, (SA*)&client, &serv->clilen);
    if (fork() == 0) {
        new_client(serv, client);
        close(serv->socket);
        close(serv->fd_client);
        exit(0);
    } else {
        close(serv->fd_client);
    }
}

int main(int argc, char *argv[])
{
    server_t *serv = init(argc, argv);
    fd_set readfds;
    struct timeval timeout;
    while (1) {
        setup_select(serv, &readfds, &timeout);
        int max_fd = serv->socket + 1;
        int ready = select(max_fd, &readfds, NULL, NULL, &timeout);
        if (ready < 0) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(serv->socket, &readfds)) {
            handle_client(serv);
        }
    }
    close(serv->socket);
    free(serv);
    return 0;
}
