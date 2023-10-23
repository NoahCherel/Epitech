/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex1b
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (NULL);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t tmp = list;

    if (list == NULL)
        return (NULL);
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    list_t tmp = list;
    unsigned int i = 0;

    if (list == NULL)
        return (NULL);
    while (tmp != NULL) {
        if (i == position)
            return (tmp->value);
        tmp = tmp->next;
        i++;
    }
    return (NULL);
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (*front_ptr == NULL)
        return (false);
    *front_ptr = tmp->next;
    free(tmp);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t tmp2 = *front_ptr;

    if (*front_ptr == NULL)
        return (false);
    if (tmp->next == NULL) {
        *front_ptr = NULL;
        free(tmp);
        return (true);
    }
    while (tmp->next != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    free(tmp);
    return (true);
}
