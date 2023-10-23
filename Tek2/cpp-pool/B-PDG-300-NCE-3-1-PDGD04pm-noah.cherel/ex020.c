/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ex020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "list.h"

void *stack_top(stack_t stack)
{
    if (stack == NULL)
        return (NULL);
    return (stack->value);
}
