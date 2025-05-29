/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    (void)args;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

static char *vertex_str(VertexClass *this)
{
    char *str = malloc(50);

    if (str) {
        snprintf(str, 50, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    }
    return str;
}

static VertexClass *vertex_add(const VertexClass *obj1, const VertexClass *obj2)
{
    return new(Vertex, (obj1->x + obj2->x), (obj1->y + obj2->y), (obj1->z + obj2->z));
}

static VertexClass *vertex_sub(const VertexClass *obj1, const VertexClass *obj2)
{
    return new(Vertex, (obj1->x - obj2->x), (obj1->y - obj2->y), (obj1->z - obj2->z));
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_str,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};
const Class *Vertex = (const Class *)&_description;
