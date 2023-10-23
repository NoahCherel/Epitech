/*
** EPITECH PROJECT, 2023
** Repos
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <uuid/uuid.h>
    #include <stdbool.h>
    #include <signal.h>
    #include <errno.h>
    #include "../../libs/myteams/logging_server.h"
    #include "../../libs/myteams/logging_client.h"

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    #define DEFAULT_PORT "5000"
    #define USAGE_MSG "Usage: ./myteams_server [port]\n"

    #define M_CLI 10
    #define BUF_SIZE 1024

    #define SAVE_FILE_PATH "save.txt"

    #define USR_LOAD server_event_user_loaded

typedef struct Server {
    int server_fd;
    struct sockaddr_in address;
    int clients[M_CLI];
    fd_set read_fds;
    int max_fd;
    char *team_uuid;
    char *team_name;
    struct Client *client;
} Server;

typedef struct team1_s {
    char *name;
    char *uuid;
    char *description;
} Team1;
typedef struct Client {
    int sockfd;
    struct sockaddr_in client_addr;
    char buffer[BUF_SIZE];
    _Bool logged_in;
    socklen_t addr_len;
    char *uuid;
    char *user_name;
    int status;
    Team1 *team;
} Client;

typedef struct team_s {
    char *name;
    char *uuid;
    char *description;
} Team;

typedef struct {
    const char *command;
    int (*action)(Client *clients[], int index, int i);
} Command1;

int handle_command(Client *clients[], int index, char *command, int i);
int loop_server(int sockfd, Client *clients[], int index);
Client* login_client(Client *clients[], int index);
void save_clients_data(Client *clients[], int index);
int add_client(Client *clients[], int client_sockfd, int index);
void remove_client(Client *clients[], int index);
int handle_client_data(Client *clients[], int index, fd_set *readfds);
void create_team(Client *client);
int handle_login1(Client *clients[], int index, int i);
int handle_logout1(Client *clients[], int index, int i);
int handle_send_users_data1(Client *clients[], int index, int i);
int handle_create_team1(Client *clients[], int index, int i);
void save_team_data(Team *team);
void signal_handler(int sig);
int send_data_team(struct Client *client);
int send_data(struct Client *client);
int setup_fd_set(int sockfd, Client *cli[], fd_set *readfds);

#endif /* !SERVER_H_ */
