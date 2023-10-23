/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sokoban
*/

#include "../include/my.h"

void my_help(int ac, char **av)
{
    my_putstr("My Sokoban : Epitech Project where you must ");
    my_putstr("recreate the sokoban");
    my_putchar(' ');
    my_putstr("using the ncurses library.");
    my_putchar('\n');
    my_putstr("USAGE :");
    my_putchar('\n');
    my_putstr("Use ZQSD (up, left, etc...)");
    my_putchar('\n');
    my_putstr("The map represent the warehouse map, ");
    my_putstr(" containing '#' for walls, 'P' for the player,");
    my_putstr("'X' for boxes and 'O' for storage locations.");
    my_putchar('\n');
}

void print_tab(char **tab)
{
    int y = 0;
    for (int i = 0; tab[i] != NULL; i++, y++) {
        mvprintw(y, my_strlen(tab[i]), tab[i]);
    }
}

void sokoban(char **map, int *tab, int nb_o, mape_t *a)
{
    erase();
    print_tab(map);
    move1(getch(), map, a);
    pos_o(map, tab, nb_o);
}

int loadmap(char const *filepath)
{
    int fd = open(filepath, O_RDONLY); char *map; struct stat st;
    mape_t *a = malloc(sizeof(mape_t)); a->x = 0;
    if (fd <= -1)
        return (84);
    if (stat(filepath, &st) == -1) {
        close(fd);
        return (84);
    }
    map = malloc(st.st_size + sizeof(char));
    if (map == NULL)
        return (84);
    read(fd, map, st.st_size);
    if (invalid_map(map, a) == 84)
        return (84);
    close(fd); char **aled = my_str_to_word_array(map);
    int *tab = mem_pos_o(aled, a);
    initscr(); curs_set(0); clear();
    while (1)
        sokoban(aled, tab, a->o, a);
    endwin(); return (0);
}

int main (int ac, char **av)
{
    if (ac != 2) {
        return (84);
    }
    if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help(ac, av);
        return (0);
    }
    if (loadmap(av[1]) == 84) {
        return (84);
    }
    return (0);
}
