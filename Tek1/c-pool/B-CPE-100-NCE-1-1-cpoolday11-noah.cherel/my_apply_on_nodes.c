/*
** EPITECH PROJECT, 2021
** my_apply_on_nodes
** File description:
** linked
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t * current = begin;    
    while (current->next != NULL) {
        (*f)(current->data);
        current = current->next;
    }
    return (0);
}
