/*
** EPITECH PROJECT, 2022
** KOBAN
** File description:
** tetris main
*/

#include "../include/my.h"

void free_all(global_t *a)
{
    for (int x = 0; x < 2; x++) {
        free(a->tetrimino[x]);
    }
    free(a->tetrimino);
    free(a->tetris);
    free(a->debug);
}

int game(int ac, char **av, global_t *a)
{
    a->y_tetris = 0; a->descente = 1; a->timer = 0; a->score = 0;
    a->y_arr_tetr = 0; a->x_tetris = 21 + a->debug->row / 2 - 1;
    a->x_arr_tetr = a->debug->row / 2; a->bo = 0; a->tetris = NULL;
    a->tetrimino = NULL;
    array_tetris(a);
    malloc_tetrimino(a);
    print_set(a);
    clock_score(a);
    free_all(a);
    return (0);
}

int error_handling(int ax, char *av[], global_t *a)
{
    DIR *d = opendir("./tetriminos");
    struct dirent *dir_content;
    if (d == NULL) {
        return (84);
    }
    if (a->debug->level == 84) return (84);
    return (0);
}

int main(int ac, char *av[])
{
    int i = 0;
    while (av[i] != NULL) {
        if (my_strcmp(av[i], "--help") == 0) {
            my_help(ac, av); return (0);
        } else if (my_strcmp(av[i], "-h") == 0) {
            my_help(ac, av); return (0);
        }
        i++;
    }
    if (count_files("./tetriminos") == 84) return (84);
    global_t *a = malloc(sizeof(global_t));
    a->ac = ac; a->av = av; a->debug = set_debug(a->debug);
    if (getoptions(ac, av, a) == 1) return (0);
    if (error_handling(ac, av, a) == 84) return (84);
    if (a->debug->debug_mode == true) {
        print_debug(a->debug); open_tetriminos(a);
    } else
        menu_tetris(av, ac, a);
    endwin(); return 0;
}
