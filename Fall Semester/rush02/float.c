/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct {
    Class base;
    float x;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    this->x = (float)va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    this->x = 0;
}

static char *float_str(FloatClass *this)
{
    char *str = malloc(50);

    if (str) {
        snprintf(str, 50, "<Float (%f)>", this->x);
    }
    return str;
}

static FloatClass *float_add(const FloatClass *obj1, const FloatClass *obj2)
{
    return new(Float, (obj1->x + obj2->x));
}

static FloatClass *float_sub(const FloatClass *obj1, const FloatClass *obj2)
{
    return new(Float, (obj1->x - obj2->x));
}

static FloatClass *float_mult(const FloatClass *obj1, const FloatClass *obj2)
{
    return new(Float, (obj1->x * obj2->x));
}

static FloatClass *float_div(const FloatClass *obj1, const FloatClass *obj2)
{
    return new(Float, (obj1->x / obj2->x));
}

static bool float_eq(const FloatClass *obj1, const FloatClass *obj2)
{
    return obj1->x == obj2->x;
}

static bool float_lt(const FloatClass *obj1, const FloatClass *obj2)
{
    return obj1->x < obj2->x;
}

static bool float_gt(const FloatClass *obj1, const FloatClass *obj2)
{
    return obj1->x > obj2->x;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mult,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0
};
const Class *Float = (const Class *)&_description;
