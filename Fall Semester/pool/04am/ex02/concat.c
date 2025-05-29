/*
** EPITECH PROJECT, 2024
** C, Life, the Universe and everything else
** File description:
** Strings and Pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    str->res = (char *)malloc(strlen(str->str1) + strlen(str->str2) + 1);
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}
