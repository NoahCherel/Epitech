/*
** EPITECH PROJECT, 2021
** MY H
** File description:
** Contains all prototypes
*/

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#ifndef MY_H_
    #define MY_H_

#define tmpv1 tmp_n = tmp->name; tmp_n2 = tmp2->next->name; data = tmp->data;
#define tmpv2 data2 = tmp2->next->data; valid = tmp->valid; row = tmp->row;

typedef struct s_list {
    char *full_name;
    char *data;
    char *name;
    int valid;
    int row;
    int col;
    int color;
    struct s_list *next;
} t_list;

typedef struct debug_s {
    bool debug_mode;
    bool next;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int level;
    int row;
    int col;
    int nb_tetriminos;
} debug_t;

typedef struct global_s {
    debug_t *debug;
    int score;
    int timer;
    char **tetris;
    char **tetrimino;
    int y_tetris;
    int x_tetris;
    int descente;
    int x_arr_tetr;
    int y_arr_tetr;
    int ac;
    char **av;
    int bo;
} global_t;

/*my_lib*/
void my_putchar(char c);
void my_put_nbr(int nb);
size_t my_strlen(char const *str);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

/*my_lib2*/
int my_strtoint(char *str);
int my_chartoint(char str);
int my_compute_power_rec(int nb, int power);
void array_to_2d(char **final_list, char *new_list, int line);
char *my_inttostr(int num);

/*my_lib3*/
int count_line(char *list);
int word_longer(char *filepath);
char *txttochar(char *filepath);
char *my_revstr(char *str);
void my_putstr_1(char const *str);

/*lib4*/
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char *src);

/*open_tetrimino_utils*/
char *txttoint(char *filepath);
char *remove_first_line(char *str);
int check_tetrimino(char *filepath);
char *print_until_dot(char *str);
int check_content_tetrimino(char *filepath);

/*open_tetrimino_bis*/
int count_files(char *dir);
char *print_first_line(char *str);
int get_first_number(char *str);
int get_second_number(char *str);
int get_third_number(char *str);

/*open_tetrimino*/
t_list *add_list(t_list *list, char *filepath);
void free_list(t_list *list);
t_list *open_tetriminosk(global_t *a);
void print_list(t_list *list);
void open_tetriminos(global_t *a);
int check(char *str);

/*open_tetrimino_utils2*/
int check2(char *str);
int check_content_tetrimino(char *filepath);
char *print_until_dot(char *str);
void open_tetriminos(global_t *a);
int count_valid(t_list *list);

/*print_tetriminos*/
int verification(char *file, int x);
char *name_file(char *av);
int debug_mode(global_t *a);
void boucle_size(global_t *a);

/*tetris*/
int game(int ac, char **av, global_t *a);

/*getopt*/
static int get_key(char *arg, int key);
int getopt2(int opt, struct option *l_options, global_t *a);
int getoptions(int ac, char **av, global_t *a);

/*open_tetrimino*/
void open_tetriminos(global_t *a);
int count_files(char *dir);
void sort_list(t_list *list);

/*opt*/
int nb_level(char *buf);
char *get_next(char *buf);
char *get_size(char *buf);
int is_number(char *str);
int my_help(int ac, char **av);

/*menu*/
void options_menu(int ch, WINDOW *win, global_t *a);
void menu_tetris(char **av, int ac, global_t *a);

/*debug*/
debug_t *set_debug(debug_t *debug);
int print_debug(debug_t *debug);

/*utils1*/
void init_color_game(void);
void print_scoreboard(global_t *a);
void clock_score(global_t *a);
int getch_nostop(void);

/*print_default*/
void print_tetris(void);
void print_board(void);
void print_tetris_bord(global_t *a);
void print_set(global_t *a);
void print_next(global_t *a);

/*utils2*/
void deplacement_tetri(global_t *a);
void clear_tetris(global_t *a);
void malloc_tetrimino(global_t *a);
void end_list(global_t *a);
void deplacement(int ch, global_t *a);

/*deplacement*/
void deplacement_left(global_t *a);
void deplacement_right(global_t *a);

/*utils3*/
void condition_end(global_t *a);
void array_tetris(global_t *a);

#endif
