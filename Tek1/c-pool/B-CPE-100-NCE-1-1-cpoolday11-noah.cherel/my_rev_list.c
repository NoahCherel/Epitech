/*
** EPITECH PROJECT, 2021
** my_rev_list
** File description:
** reverse
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *next;
    linked_list_t *prev = NULL;
    linked_list_t *current = (*begin);
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*begin) = prev;
}
