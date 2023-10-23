/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex0001
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;
    int_list_t tmp2 = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    *front_ptr = NULL;
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t tmp = list;

    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->value);
}