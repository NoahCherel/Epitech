/*
* with linked list* EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** linked
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *head;
    if (ac == 0)
        return (0);
    head = malloc(sizeof(head));
    head->data = (void *) av[ac - 1];
    if (ac > 0) {
        head->next = my_params_to_list((ac - 1), av);
    }
    return (head);
}
