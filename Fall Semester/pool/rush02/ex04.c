/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Rush 02
*/

#include <stdio.h>
#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"

void compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf("a > b\n");
    else if (lt(a, b))
        printf("a < b\n");
    else
        printf("a == b\n");
    printf("b / a = %s\n", str(division(b, a)));
}

void main(){
    Object  *p2 = new(Int, 12);
    Object  *p1 = new(Int, 2);

    compareAndDivide(p1, p2);
}