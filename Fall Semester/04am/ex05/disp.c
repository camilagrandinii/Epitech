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

void disp_int_array(const int *array, size_t nmemb)
{
    size_t arraySize = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < arraySize; i++){
        printf("%i\n", array[i]);
    }
}

void disp_array(const void *array, size_t nmemb,
    size_t size, void (*print)(const void *))
{
    for (size_t i = 0; i < nmemb; ++i){
        print(array + i * size);
    }
}

void print_int(const void *element)
{
    printf("%d ", *(const int *)element);
}

static int test_comp(const void *a, const void *b)
{
    return (strcmp(*(char **)a, *(char **)b));
}

static void test_disp(const void *str)
{
    printf(" %s", *(char **)str);
}
