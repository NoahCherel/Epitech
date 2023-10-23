/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex040
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "list.h"

void map_clear(map_t *map_ptr)
{
    list_t current = *map_ptr;
    while (current != NULL) {
        list_t next = current->next;
        free((pair_t *)current->value);
        free(current);
        current = next;
    }
    *map_ptr = NULL;
}
