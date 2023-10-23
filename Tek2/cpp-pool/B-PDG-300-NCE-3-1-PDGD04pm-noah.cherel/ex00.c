/*
** EPITECH PROJECT, 2023
** piscine
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"
#include <stdbool.h>

unsigned int int_list_get_size(int_list_t list)
{
    int_list_t tmp = list;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void int_list_dump(int_list_t list)
{
    int_list_t tmp = list;

    while (tmp != NULL) {
        printf("%d", tmp->value);
        tmp = tmp->next;
        printf("\n");
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new = malloc(sizeof(*new));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *new_node = (int_node_t *)malloc(sizeof(int_node_t));
    int_node_t *tmp = *front_ptr;

    if (new_node == NULL) {
        return false;
    }

    new_node->value = elem;
    new_node->next = NULL;

    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return true;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return true;
}
