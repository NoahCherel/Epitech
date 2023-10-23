/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** getopt
*/

#include "../include/my.h"

static int get_key(char *arg, int key)
{
    int n_key = 0;
    n_key = my_strtoint(arg);
    return (n_key);
}

int getopt2(int opt, struct option *l_options, global_t *a)
{
    while ((opt = getopt_long(a->ac, a->av, "L:l:r:t:d:q:p:wd:Dm:", l_options,
    NULL)) != -1) {
        switch (opt) {
        case 'L': a->debug->level = nb_level(optarg); break;
        case 'l': a->debug->left = get_key(optarg, a->debug->left); break;
        case 'r': a->debug->right = get_key(optarg, a->debug->right); break;
        case 't': a->debug->turn = get_key(optarg, a->debug->turn); break;
        case 'd': a->debug->drop = get_key(optarg, a->debug->drop); break;
        case 'q': a->debug->quit = get_key(optarg, a->debug->quit); break;
        case 'p': a->debug->pause = get_key(optarg, a->debug->pause); break;
        case 'w': a->debug->next = true; break;
        case 'D': a->debug->debug_mode = true; break;
        case 'm':
            a->debug->col = my_strtoint(get_next(optarg));
            a->debug->row = my_strtoint(get_size(optarg)); break;
        }
    }
    return (0);
}

int getoptions(int ac, char **av, global_t *a)
{
    int opt;
    static struct option l_options[] = {
        {"level=", required_argument, 0, 'L'},
        {"key-left=", required_argument, 0, 'l'},
        {"key-right=", required_argument, 0, 'r'},
        {"key-turn=", required_argument, 0, 't'},
        {"key-drop=", required_argument, 0, 'd'},
        {"key-quit=", required_argument, 0, 'q'},
        {"key-pause=", required_argument, 0, 'p'},
        {"map-size=", required_argument, 0, 'm'},
        {"without-next", required_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}};
    return (getopt2(opt, l_options, a));
}
