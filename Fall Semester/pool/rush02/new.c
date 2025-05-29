/*
** EPITECH PROJECT, 2024
** Rush 2
** File description:
** Exercise 01
*/
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "player.h"
#include "point.h"

Object *new(const Class *class, ...)
{
    const Class *class_ptr = class;
    Object *object = malloc(class_ptr->__size__);
    va_list ap;

    if (object) {
        memcpy(object, class_ptr, class_ptr->__size__);
        if (class_ptr->__ctor__) {
            va_start(ap, class);
            class_ptr->__ctor__(object, &ap);
            va_end(ap);
        }
    }
    return object;
}

Object *va_new(const Class *class, va_list *ap)
{
    const Class *class_ptr = class;
    Object *object = malloc(class_ptr->__size__);

    if (object) {
        memcpy(object, class_ptr, class_ptr->__size__);
        if (class_ptr->__ctor__) {
            class_ptr->__ctor__(object, ap);
        }
    }
    return object;
}

void delete(Object *object) {
    const Class *class_ptr = object;

    if (class_ptr->__dtor__) {
        class_ptr->__dtor__(object);
    }

    free(object);
}
