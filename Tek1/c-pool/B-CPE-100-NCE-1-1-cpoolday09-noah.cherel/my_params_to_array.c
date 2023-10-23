/*
** EPITECH PROJECT, 2021
** my_params
** File description:
** to_array
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *my_params;
    my_params = malloc(sizeof(struct info_param));
    int i = 0;
    while (ac > i) {
        my_params[i]->length = my_strlen(ac);
        my_params[i]->str = av[i];
        my_params[i]->copy = strdup(av[i]);
        my_params[i]->word_array = my_str_to_word_array(concat_params(str));
        i++;
    }
    return (my_params);
}
