/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex001
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"
#include <stdbool.h>

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_list_t new = malloc(sizeof(*new));
    int_list_t tmp = *front_ptr;
    int i = 0;
    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = NULL;
    if (position == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    while (tmp != NULL) {
        if (i == position - 1) {
            new->next = tmp->next;
            tmp->next = new;
            return (true);
        }
        tmp = tmp->next;
        i++;
    }
    return (false);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_list_t tmp = list;
    int i = 0;

    while (tmp != NULL) {
        if (i == position)
            return (tmp->value);
        tmp = tmp->next;
        i++;
    }
    return (0);
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;

    if (tmp == NULL)
        return (false);
    *front_ptr = tmp->next;
    free(tmp);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;
    int_list_t tmp2 = *front_ptr;

    if (tmp == NULL)
        return (false);
    while (tmp->next != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    free(tmp);
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t tmp = *front_ptr;
    int_list_t tmp2 = *front_ptr;
    int i = 0;
    if (tmp == NULL)
        return (false);
    if (position == 0)
        return (int_list_del_elem_at_front(front_ptr));
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
