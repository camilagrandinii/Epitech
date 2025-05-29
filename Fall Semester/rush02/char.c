/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "new.h"
#include "char.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->x = (char)va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
    this->x = 0;
}

static char *char_str(CharClass *this)
{
    char *str = malloc(50);

    if (str) {
        snprintf(str, 50, "<Char (%c)>", this->x);
    }
    return str;
}

static CharClass *char_add(const CharClass *obj1, const CharClass *obj2)
{
    return new(Char, (obj1->x + obj2->x));
}

static CharClass *char_sub(const CharClass *obj1, const CharClass *obj2)
{
    return new(Char, (obj1->x - obj2->x));
}

static CharClass *char_mult(const CharClass *obj1, const CharClass *obj2)
{
    return new(Char, (obj1->x * obj2->x));
}

static CharClass *char_div(const CharClass *obj1, const CharClass *obj2)
{
    return new(Char, (obj1->x / obj2->x));
}

static bool char_eq(const CharClass *obj1, const CharClass *obj2)
{
    return obj1->x == obj2->x;
}

static bool char_lt(const CharClass *obj1, const CharClass *obj2)
{
    return obj1->x < obj2->x;
}

static bool char_gt(const CharClass *obj1, const CharClass *obj2)
{
    return obj1->x > obj2->x;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_str,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mult,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .x = 0
};
const Class *Char = (const Class *)&_description;
