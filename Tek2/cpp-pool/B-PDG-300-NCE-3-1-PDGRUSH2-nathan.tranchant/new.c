/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** new
*/

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "raise.h"
#include "new.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "object.h"

Object  *new(const Class *class, ...) {
    Object *obj = malloc(class->__size__);
    va_list ap;

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__) {
        va_start(ap, class);
        class->__ctor__(obj, &ap);
        va_end(ap);
    }
    return (obj);
}

Object  *va_new(const Class *class, va_list* ap)
{
    Object *obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

void    delete(Object *ptr) {
    Class *class = ptr;

    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}
