/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex1
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    list_t tmp = list;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(*new));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(*new));
    list_t tmp = *front_ptr;

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new;
        return (true);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t new = malloc(sizeof(*new));
    list_t tmp = *front_ptr;
    unsigned int i = 0;

    if (new == NULL)
        return (false);
    new->value = elem;
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    while (i < position - 1) {
        tmp = tmp->next;
        i++;
    }
    new->next = tmp->next;
    tmp->next = new;
    return (true);
}
