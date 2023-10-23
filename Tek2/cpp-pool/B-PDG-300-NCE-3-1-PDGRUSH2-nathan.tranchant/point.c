/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    /* Fill this function for exercice 02 */
}

static void Point_dtor(PointClass *this)
{
    if (!this)
        return;
    /* Fill this function for exercice 02 */
}

static char *Point_str(PointClass *self)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<Point (%d, %d)>", self->x, self->y);
    return (str);
}

static PointClass *Point_add(PointClass *self, PointClass *other)
{
    PointClass *new_point;
    new_point = new(Point, self->x + other->x, self->y + other->y);
    return (new_point);
}

static PointClass *Point_sub(PointClass *self, PointClass *other)
{
    PointClass *new_point;
    new_point = new(Point, self->x - other->x, self->y - other->y);
    return (new_point);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = Point_str,
        .__add__ = Point_add,
        .__sub__ = Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
