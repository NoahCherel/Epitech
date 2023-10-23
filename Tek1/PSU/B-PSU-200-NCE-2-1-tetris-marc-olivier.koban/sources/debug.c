/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** debug
*/

#include "../include/my.h"

debug_t *set_debug(debug_t *debug)
{
    debug = malloc(sizeof(debug_t));
    debug->debug_mode = false;
    debug->left = KEY_LEFT;
    debug->right = KEY_RIGHT;
    debug->turn = KEY_UP;
    debug->drop = KEY_DOWN;
    debug->quit = 'q';
    debug->pause = ' ';
    debug->next = true;
    debug->level = 1;
    debug->row = 20;
    debug->col = 10;
    debug->nb_tetriminos = count_files("./tetriminos");
    return (debug);
}

static void putstr_bis2(int key)
{
    if (key == KEY_UP) {
        my_putstr_1("KEY_UP");
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
    if (key == KEY_DOWN) {
        my_putstr_1("KEY_DOWN");
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
    if (key == KEY_RIGHT) {
        my_putstr_1("KEY_RIGHT");
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
    if (key == KEY_LEFT) {
        my_putstr_1("KEY_LEFT");
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
}

static void putstr_bis(int key)
{
    if (key == 33) {
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
    if (key >= 258 && key <= 261) {
        putstr_bis2(key);
    } else {
        my_putchar(key);
        my_putchar(' '); my_putchar('('); my_put_nbr(key); my_putchar(')');
    }
}

int print_debug_bis(debug_t *debug)
{
    if (debug->next == true)
        my_putstr_1("Next: Yes\n");
    else
        my_putstr_1("Next: No\n");
    my_putstr_1("Level: ");
    my_put_nbr(debug->level);
    my_putchar('\n');
    my_putstr_1("Size: ");
    my_put_nbr(debug->row);
    my_putchar('*');
    my_put_nbr(debug->col);
    my_putchar('\n');
    my_putchar('\n');
    return (1);
}

int print_debug(debug_t *debug)
{
    my_putstr_1("Key left: ");
    putstr_bis(debug->left);
    my_putstr_1("\nKey right: ");
    putstr_bis(debug->right);
    my_putstr_1("\nKey turn: ");
    putstr_bis(debug->turn);
    my_putstr_1("\nKey drop: ");
    putstr_bis(debug->drop);
    my_putstr_1("\nKey quit: ");
    putstr_bis(debug->quit);
    my_putstr_1("\nKey pause: ");
    putstr_bis(debug->pause);
    my_putchar('\n');
    print_debug_bis(debug);
    return (1);
}
