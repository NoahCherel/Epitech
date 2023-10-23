/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** int
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "object.h"
#include "int.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (!this)
        return;
}

static char *Int_str(IntClass *self)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<Int (%d)>", self->x);
    return (str);
}

static IntClass *Int_add(IntClass *self, IntClass *other)
{
    IntClass *new_int;
    new_int = new(Int, self->x + other->x);
    return (new_int);
}

static IntClass *Int_sub(IntClass *self, IntClass *other)
{
    IntClass *new_int;
    new_int = new(Int, self->x - other->x);
    return (new_int);
}

static IntClass *Int_mul(IntClass *self, IntClass *other)
{
    IntClass *new_int;
    new_int = new(Int, self->x * other->x);
    return (new_int);
}

static IntClass *Int_div(IntClass *self, IntClass *other)
{
    IntClass *new_int;
    if (other->x == 0)
        raise("Division by zero");
    new_int = new(Int, self->x / other->x);
    return (new_int);
}

static bool Int_eq(IntClass *self, IntClass *other)
{
    if (self->x == other->x)
        return (true);
    return (false);
}

static bool Int_gt(IntClass *self, IntClass *other)
{
    if (self->x > other->x)
        return (true);
    return (false);
}

static bool Int_lt(IntClass *self, IntClass *other)
{
    if (self->x < other->x)
        return (true);
    return (false);
}

static const IntClass _description = {
   {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = Int_str,
        .__add__ = Int_add,
        .__sub__ = Int_sub,
        .__mul__ = Int_mul,
        .__div__ = Int_div,
        .__eq__ = Int_eq,
        .__gt__ = Int_gt,
        .__lt__ = Int_lt
    },
    .x = 0,
};

const Class *Int = (const Class *)&_description;
