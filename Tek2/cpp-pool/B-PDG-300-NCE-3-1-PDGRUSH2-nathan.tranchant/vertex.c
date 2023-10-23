/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** vertex
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "object.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
    /* Fill this function for exercice 02 */
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this)
        return;
    /* Fill this function for exercice 02 */
}

static char *Vertex_str(VertexClass *self)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<Vertex (%d, %d, %d)>", self->x, self->y, self->z);
    return (str);
}

static VertexClass *Vertex_add(VertexClass *self, VertexClass *other)
{
    VertexClass *new_vertex;
    new_vertex = new(Vertex, self->x + other->x, self->y + other->y, self->z + other->z);
    return (new_vertex);
}

static VertexClass *Vertex_sub(VertexClass *self, VertexClass *other)
{
    VertexClass *new_vertex;
    new_vertex = new(Vertex, self->x - other->x, self->y - other->y, self->z - other->z);
    return (new_vertex);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = Vertex_str,
        .__add__ = Vertex_add,
        .__sub__ = Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
