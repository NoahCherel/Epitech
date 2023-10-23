/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** float
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "object.h"
#include "float.h"

typedef struct {
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (!this)
        return;
}

static char *Float_str(FloatClass *self)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<Float (%f)>", self->x);
    return (str);
}

static FloatClass *Float_add(FloatClass *self, FloatClass *other)
{
    FloatClass *new_float;
    new_float = new(Float, self->x + other->x);
    return (new_float);
}

static FloatClass *Float_sub(FloatClass *self, FloatClass *other)
{
    FloatClass *new_float;
    new_float = new(Float, self->x - other->x);
    return (new_float);
}

static FloatClass *Float_mul(FloatClass *self, FloatClass *other)
{
    FloatClass *new_float;
    new_float = new(Float, self->x * other->x);
    return (new_float);
}

static FloatClass *Float_div(FloatClass *self, FloatClass *other)
{
    FloatClass *new_float;
    if (other->x == 0)
        raise("Division by zero");
    new_float = new(Float, self->x / other->x);
    return (new_float);
}

static bool Float_eq(FloatClass *self, FloatClass *other)
{
    if (self->x == other->x)
        return (true);
    return (false);
}

static bool Float_gt(FloatClass *self, FloatClass *other)
{
    if (self->x > other->x)
        return (true);
    return (false);
}

static bool Float_lt(FloatClass *self, FloatClass *other)
{
    if (self->x < other->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
   {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = Float_str,
        .__add__ = Float_add,
        .__sub__ = Float_sub,
        .__mul__ = Float_mul,
        .__div__ = Float_div,
        .__eq__ = Float_eq,
        .__gt__ = Float_gt,
        .__lt__ = Float_lt
    },
    .x = 0,
};

const Class *Float = (const Class *)&_description;
