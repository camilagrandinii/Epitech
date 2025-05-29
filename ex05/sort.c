/*
** EPITECH PROJECT, 2024
** C, Life, the Universe and everything else
** File description:
** Strings and Pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int compare_strings(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_integers(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort_int_array(int *array, size_t nmemb)
{
    size_t numIntegers = sizeof(array) / sizeof(array[0]);

    qsort(array, numIntegers, sizeof(array[0]), compare_strings);
}

void sort_array(void *array, size_t nmemb,
    size_t size, int (*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
