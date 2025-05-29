/*
** EPITECH PROJECT, 2024
** C, Life, the Universe and everything else
** File description:
** Strings and Pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    (*mul) = a * b;
    (*div) = a / b;
}

void mul_div_short(int *a, int *b)
{
    *a = (*a) * (*b);
    if (*b != 0){
        *b = (*a) / (*b);
    }
}
