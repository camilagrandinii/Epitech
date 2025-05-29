/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    this->x = 0;
}

static char *int_str(IntClass *this)
{
    char *str = malloc(50);

    if (str) {
        snprintf(str, 50, "<Int (%d)>", this->x);
    }
    return str;
}

static IntClass *int_add(const IntClass *obj1, const IntClass *obj2)
{
    return new(Int, (obj1->x + obj2->x));
}

static IntClass *int_sub(const IntClass *obj1, const IntClass *obj2)
{
    return new(Int, (obj1->x - obj2->x));
}

static IntClass *int_mult(const IntClass *obj1, const IntClass *obj2)
{
    return new(Int, (obj1->x * obj2->x));
}

static IntClass *int_div(const IntClass *obj1, const IntClass *obj2)
{
    return new(Int, (obj1->x / obj2->x));
}

static bool int_eq(const IntClass *obj1, const IntClass *obj2)
{
    return obj1->x == obj2->x;
}

static bool int_lt(const IntClass *obj1, const IntClass *obj2)
{
    return obj1->x < obj2->x;
}

static bool int_gt(const IntClass *obj1, const IntClass *obj2)
{
    return obj1->x > obj2->x;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_str,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mult,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};
const Class *Int = (const Class *)&_description;
