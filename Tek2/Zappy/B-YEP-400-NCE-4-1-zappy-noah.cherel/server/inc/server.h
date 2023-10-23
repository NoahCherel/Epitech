/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <pthread.h>
    #include <stdbool.h>
    #include <time.h>
    #include <sys/time.h>
    #include <poll.h>

    #define MAX_MSG_LEN 4096
    #define MAX_CLIENTS 1000
    #define UPDATE_INTERVAL 1

        typedef struct {
        char *command;
        int sockfd;
        int timer;
    } command_queue_item_t;

    typedef struct {
        command_queue_item_t queue[10000];
        int front;
        int rear;
        int size;
    } command_queue_t;
    typedef struct {
        int x;
        int y;
    } position_t;

    typedef struct {
        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
    } inventory_t;
    typedef struct {
        int id;
        position_t pos;
        int level;
        inventory_t inventory;
        int orientation;
        int sockfd;
        char *team;
        struct sockaddr_in addr;
        int timeleft;
        bool isdead;
        bool connected;
    } Player;

    typedef struct {
        char *name;
        int nb_players;
        int nb_slots;
        Player *players;
        bool is_full;
    } team_t;

    typedef struct {
        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
        int players;
    } cell_t;

    typedef struct {
        int width;
        int height;
        cell_t **map;
        team_t *teams;
        int num_players;
        Player *players;
        int playerId;
        int freq;
        int time;
        char **teamNames;
        int teamsNb;
        int handler;
        int graphicSockfd;
        command_queue_t *queue;
        int materials_timer;
        int players_timer;
    } game_t;

    typedef struct {
        int port;
        int width;
        int height;
        team_t *teams;
        int clientsNb;
        int teamsNb;
        char **teamNames;
        int freq;
        int sockfd;
        game_t *game;
        struct sockaddr_in addr;
    } server_t;

    typedef struct {
        char *command;
        void (*function)(int sockfd, game_t *game);
    } command_function_t;

    typedef struct {
        char *command;
        void (*function)(int sockfd, game_t *game, int id);
    } command_function_ai_t;

    typedef struct {
        char *command;
        void (*function)(int sockfd, game_t *game, int id, char *arg);
    } command_function_ai_arg_t;

void help(void);
void send_message(int sockfd, char *msg);
void send_error(int sockfd, const char *msg);
void send_ok(int sockfd);
void send_map(int sockfd, game_t *game);
void send_player_info(int sockfd, Player *player);
void send_player_inventory(int sockfd, game_t *game, int id);
void send_player_position(int sockfd, Player *player);
void send_player_victory(int sockfd, Player *player);
void send_player_death(int sockfd, Player *player);
void send_player_expulsion(int sockfd, Player *player);
void send_broadcast(int sockfd, Player *player, const char *msg);
void send_player_incantation_start(int sockfd, Player *player);
void send_player_incantation_end(int sockfd, Player *player, int success);
void send_player_fork(int sockfd, Player *player);
void send_player_pos(int sockfd, game_t *game, int id);
void send_player_pos_all(int sockfd, game_t *game);
void send_map_size(int sockfd, game_t *game);
void send_tile_content(int sockfd, game_t *game, int x, int y);
void send_tile_content_all(int sockfd, game_t *game);
void send_map_content(int sockfd, game_t *game);
void send_welcome(int sockfd);
void send_team_names(int sockfd, game_t *game);
void send_connection_new_player(int sockfd, Player *player);
void player_death(game_t *game, int id);
void handle_fork_function(int sockfd, game_t *game, int id);

// Handle GUI commands
void handle_msz(int sockfd, game_t *game);
void handle_bct(int sockfd, game_t *game);
void handle_mct(int sockfd, game_t *game);
void handle_tna(int sockfd, game_t *game);
void handle_pnw(int sockfd, game_t *game, int id);
void handle_plv(int sockfd, game_t *game);
void handle_ppo(int sockfd, game_t *game);
void handle_pin(int sockfd, game_t *game);
void handle_sgt(int sockfd, game_t *game);
void handle_graphic(int sockfd, game_t *game);
void handle_all_commands(int sockfd, game_t* game, char* msg, command_queue_t* ai_command_queue);

// Server functions
server_t *parsing_args(int ac, char** av);
server_t *create_server(int *size, char** t, int c);
void rem_serv(server_t *server);
void map_content_coding(int sockfd, game_t *game, int x);
int create_socket(server_t *server);
int accept_connection(int sockfd);
void* h_cli(void *arg);
void handle_new_connection(int sockfd, int* clients);

void h_client_requests(int* clients, fd_set* readfds, server_t *server);
void init_map(game_t *game);
game_t *init_game(server_t *server);
void init_players(game_t *game);
void display_map(int fd, game_t *game);
char *get_team_name(char *msg, game_t *game);
void handle_look_function(int sockfd, game_t *game, int id);

// Handle ressources
void place_food(game_t *game, float food_quantity);
void place_linemate(game_t *game, float linemate_quantity);
void place_deraumere(game_t *game, float deraumere_quantity);
void place_sibur(game_t *game, float sibur_quantity);
void place_mendiane(game_t *game, float mendiane_quantity);
void place_phiras(game_t *game, float phiras_quantity);
void place_thystame(game_t *game, float thystame_quantity);
void place_materials(game_t *game);
//void* update_resources(game_t *game);
void update_resources(game_t *game);

// Handle AI commands
void move_forward(int sockfd, game_t *game, int id);
void turn_right(int sockfd, game_t *game, int id);
void turn_left(int sockfd, game_t *game, int id);
void take_object(int sockfd, game_t *game, int id, char *object);
void handle_forward_function(int sockfd, game_t *game, int id);
void handle_right_function(int sockfd, game_t *game, int id);
void handle_left_function(int sockfd, game_t *game, int id);
void handle_inventory_function(int sockfd, game_t *game, int id);
void handle_takeObject_function(int sockfd, game_t *game, int id, char *object);
void handle_setObject_function(int sockfd, game_t *game, int id, char *object);
void map_content_coding(int sockfd, game_t *game, int x);
int add_player_to_team(game_t *game, char *team_name, int sockfd);
void send_map_size_player(int sockfd, game_t *game);
void team_players_left_slot(int sockfd, game_t *game, char *team_name);
void handle_mct(int sockfd, game_t *game);
void handle_incantation_function(int sockfd, game_t *game, int id);
void execute_ai_command(command_queue_t* ai_command_queue, game_t* game);
void send_player_level(int sockfd, game_t *game, int id);
int find_player_by_sockfd(game_t *game, int sockfd);

// Handle Command Queue
void initialize_queue(command_queue_t* queue);
bool is_queue_empty(const command_queue_t* queue);
bool is_queue_full(const command_queue_t* queue);
void enqueue(command_queue_t* queue, char* command, int sockfd, game_t* game);
void requeue(command_queue_t* queue, command_queue_item_t command);
command_queue_item_t dequeue(command_queue_t* queue);
long get_current_time(void);
void update_gui(game_t *game, char *command, int playerId);
void handle_broadcast_message(int sockfd, char *message, game_t *game);
void send_ko(int sockfd);
Player *get_player_by_id(game_t *game, int playerId);
void update_players(game_t *game);

#endif /* !SERVER_H_ */
