/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ftp_server
*/

#ifndef FTP_SERVER_H_
    #define FTP_SERVER_H_

    #define MAX 1024
    #define SO_REUSEPORT 15
    #define SA struct sockaddr
    #define PASSIVE 1
    #define ACTIVE 2

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/select.h>

typedef struct client_s {
    int fd;
    char *ip;
    int logged;
    char *username;
    char *password;
    int mode;
    int data_socket;
    int data_port;
    char *data_ip;
    struct sockaddr_in data_addr;
} client_t;

typedef struct server_s {
    int socket;
    int connfd;
    int fd_server;
    int fd_client;
    struct sockaddr_in servaddr;
    struct sockaddr_in cli;
    int len;
    char *path;
    char *ip;
    int port;
    socklen_t clilen;
    int data_socket;
} server_t;

void help(void);
void quit_function_ftp(server_t *serv, client_t *client, char *buffer);
void pwd_function_ftp(server_t *serv, client_t *client, char *buffer);
void cwd_function_ftp(server_t *serv, client_t *client, char *buffer);
void cdup_function_ftp(server_t *serv, client_t *client, char *buffer);
void dele_function_ftp(server_t *serv, client_t *client, char *buffer);
void pasv_function_ftp(server_t *serv, client_t *client, char *buffer);
void list_function_ftp(server_t *serv, client_t *client, char *buffer);
void retr_function_ftp(server_t *serv, client_t *client, char *buffer);
void stor_function_ftp(server_t *serv, client_t *client, char *buffer);
void noop_function_ftp(server_t *serv, client_t *client, char *buffer);
void port_function_ftp(server_t *serv, client_t *client, char *buffer);
void help_function_ftp(server_t *serv, client_t *client, char *buffer);
void user_function_ftp(server_t *serv, client_t *client, char *buffer);
void pass_function_ftp(server_t *serv, client_t *client, char *buffer);
void handle_all_command(server_t *serv, char *buffer, client_t *client);
int new_client(server_t *server, struct sockaddr_in client);
server_t *init_server(int port, char *path);
client_t *create_client(server_t *server, char *ip);


#endif /* !FTP_SERVER_H_ */
