/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex04
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "list.h"

unsigned int map_get_size(map_t map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t map)
{
    return list_is_empty(map);
}

bool map_add_elem(map_t *map_ptr, void *key, void *value,
key_comparator_t key_cmp)
{
    list_t current = *map_ptr;
    while (current != NULL) {
        pair_t *pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0) {
            pair->value = value;
            return true;
        }
        current = current->next;
    }
    pair_t *new_pair = malloc(sizeof(*new_pair));
    if (new_pair == NULL) {
        return false;
    }
    new_pair->key = key;
    new_pair->value = value;
    return list_add_elem_at_front(map_ptr, new_pair);
}

void * map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    list_t current = map;
    while (current != NULL) {
        pair_t *pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0) {
            return pair->value;
        }
        current = current->next;
    }
    return NULL;
}

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    list_t current = *map_ptr;
    list_t prev = NULL;
    while (current != NULL) {
        pair_t *pair = (pair_t *)current->value;
        if (key_cmp(pair->key, key) == 0) {
            if (prev == NULL) {
                *map_ptr = current->next;
            } else {
                prev->next = current->next;
            }
            free(pair);
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
