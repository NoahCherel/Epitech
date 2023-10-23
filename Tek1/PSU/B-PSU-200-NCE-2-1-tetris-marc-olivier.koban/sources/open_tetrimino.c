/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** open_tetrimino
*/

#include "../include/my.h"

void sort_list(t_list *list)
{
    t_list *tmp = list, *tmp2 = list; int color2, col, col2, color;
    char *tmp_n, *tmp_n2, *data, *data2; int valid, valid2, row, row2;
    while (tmp != NULL) {
        tmp2 = tmp; while (tmp2->next != NULL) {
            tmpv1; tmpv2;
            valid2 = tmp2->next->valid; row2 = tmp2->next->row;
            col = tmp->col; col2 = tmp2->next->col;
            color = tmp->color; color2 = tmp2->next->color;
            if (my_strcmp(tmp_n, tmp_n2) > 0) {
                tmp->name = tmp2->next->name; tmp2->next->name = tmp_n;
                tmp->data = tmp2->next->data; tmp2->next->data = data;
                tmp->valid = tmp2->next->valid; tmp2->next->valid = valid;
                tmp->row = tmp2->next->row; tmp2->next->row = row;
                tmp->col = tmp2->next->col; tmp2->next->col = col;
                tmp->color = tmp2->next->color; tmp2->next->color = color;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

t_list *add_list(t_list *list, char *filepath)
{
    t_list *new = malloc(sizeof(t_list));
    if (check_tetrimino(filepath) == 84) {
        return (list);
    }
    if (check_content_tetrimino(txttoint(filepath)) == 84) {
        new->full_name = filepath;  new->data = txttoint(filepath);
        new->name = print_until_dot(filepath);
        new->valid = 0; new->col = 0; new->color = 0;
        new->row = 0; new->next = list;
        return (new);
    }
    new->full_name = filepath;
    new->data = txttoint(filepath);
    new->name = print_until_dot(filepath);
    new->row = get_first_number(new->name);
    new->valid = 0; new->col = 0; new->color = 0;
    new->next = list;
    return (new);
}

void free_list(t_list *list)
{
    t_list *tmp = list;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->name);
        free(tmp->data);
        free(tmp);
    }
}

t_list *open_tetriminosk(global_t *a)
{
    DIR *d = opendir("./tetriminos");
    struct dirent *dir_content;
    t_list *list = NULL;
    if (d == NULL) {
        return (NULL);
    }
    while ((dir_content = readdir(d)) != NULL) {
        if (dir_content->d_name[0] != '.') {
            list = add_list(list, dir_content->d_name);
        }
    }
    closedir(d);
    return (list);
}

void print_list(t_list *list)
{
    t_list *tmp = list; my_putstr_1("Number of tetriminos: ");
    my_put_nbr(count_valid(list)); my_putchar('\n');
    while (list != NULL) {
        if (check_content_tetrimino(list->data) == 84) {
            my_putstr_1("Tetriminos '");
            char *a = print_until_dot(list->full_name);
            my_putstr_1(list->name); my_putstr_1("': error\n");
            list = list->next;
        } else {
            char *b = print_first_line(list->data);
            char *tetrimino = remove_first_line(list->data);
            int a = get_first_number(b); int c = get_second_number(b);
            int d = get_third_number(b);
            my_putstr_1("Tetriminos '"); my_putstr_1(list->name);
            my_putstr_1("':"); my_putstr_1(" size "); my_put_nbr(a);
            my_putstr_1("*"); my_put_nbr(c); my_putstr_1(", color ");
            my_put_nbr(d); my_putchar('\n'); my_putstr_1(tetrimino);
            list = list->next;
        }
    }
}
