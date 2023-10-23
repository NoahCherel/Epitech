/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex1c
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t tmp2 = *front_ptr;
    unsigned int i = 0;
    if (*front_ptr == NULL)
        return (false);
    if (position == 0) {
        *front_ptr = tmp->next;
        free(tmp); return (true);
    }
    while (tmp != NULL) {
        if (i == position) {
            tmp2->next = tmp->next;
            free(tmp);
            return (true);
        }
        tmp2 = tmp;
        tmp = tmp->next;
        i++;
    }
    return (false);
}

void list_clear(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t tmp2 = *front_ptr;

    while (tmp != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
    *front_ptr = NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t tmp = list;

    while (tmp != NULL) {
        val_disp(tmp->value);
        tmp = tmp->next;
    }
}
