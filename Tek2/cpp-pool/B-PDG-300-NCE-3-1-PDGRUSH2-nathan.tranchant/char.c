/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** char
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "object.h"
#include "char.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        return;
}

static char *Char_str(CharClass *self)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<Char (%c)>", self->x);
    return (str);
}

static CharClass *Char_add(CharClass *self, CharClass *other)
{
    CharClass *new_char;
    new_char = new(Char, self->x + other->x);
    return (new_char);
}

static CharClass *Char_sub(CharClass *self, CharClass *other)
{
    CharClass *new_char;
    new_char = new(Char, self->x - other->x);
    return (new_char);
}

static CharClass *Char_mul(CharClass *self, CharClass *other)
{
    CharClass *new_char;
    new_char = new(Char, self->x * other->x);
    return (new_char);
}

static CharClass *Char_div(CharClass *self, CharClass *other)
{
    CharClass *new_char;
    new_char = new(Char, self->x / other->x);
    return (new_char);
}

static bool Char_eq(CharClass *self, CharClass *other)
{
    if (self->x == other->x)
        return (true);
    return (false);
}

static bool Char_gt(CharClass *self, CharClass *other)
{
    if (self->x > other->x)
        return (true);
    return (false);
}

static bool Char_lt(CharClass *self, CharClass *other)
{
    if (self->x < other->x)
        return (true);
    return (false);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = Char_str,
        .__add__ = Char_add,
        .__sub__ = Char_sub,
        .__mul__ = Char_mul,
        .__div__ = Char_div,
        .__eq__ = Char_eq,
        .__gt__ = Char_gt,
        .__lt__ = Char_lt
    },
    .x = 0,
};

const Class *Char = (const Class *)&_description;