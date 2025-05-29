/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"

typedef struct {
    Class base;
    int x, y;
} PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    this->x = 0;
    this->y = 0;
}

static char *point_str(PointClass *this)
{
    char *str = malloc(50);

    if (str) {
        snprintf(str, 50, "<Point (%d, %d)>", this->x, this->y);
    }
    return str;
}

static PointClass *point_add(const PointClass *obj1, const PointClass *obj2)
{
    return new(Point, (obj1->x + obj2->x), (obj1->y + obj2->y));
}

static PointClass *point_sub(const PointClass *obj1, const PointClass *obj2)
{
    return new(Point, (obj1->x - obj2->x), (obj1->y - obj2->y));
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_str,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};
const Class *Point = (const Class *)&_description;
