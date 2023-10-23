/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex02
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "list.h"

unsigned int stack_get_size(stack_t stack)
{
    unsigned int i = 0;
    stack_t tmp = stack;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

bool stack_is_empty(stack_t stack)
{
    if (stack == NULL)
        return (true);
    return (false);
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    stack_t new = malloc(sizeof(*new));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = *stack_ptr;
    *stack_ptr = new;
    return (true);
}

bool stack_pop(stack_t *stack_ptr)
{
    stack_t tmp = *stack_ptr;

    if (stack_is_empty(*stack_ptr))
        return (false);
    *stack_ptr = tmp->next;
    free(tmp);
    return (true);
}

void stack_clear(stack_t *stack_ptr)
{
    stack_t tmp = *stack_ptr;

    while (tmp != NULL) {
        tmp = tmp->next;
        free(*stack_ptr);
        *stack_ptr = tmp;
    }
}
