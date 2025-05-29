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

size_t uniq_int_array_unique_loop(int *array, size_t nmemb, size_t i)
{
    size_t j;
    size_t uniqueIndex = 1;

    for (j = 0; j < uniqueIndex; ++j){
            if (array[i] == array[j]){
                break;
            }
        if (j == uniqueIndex){
            array[uniqueIndex] = array[i];
            uniqueIndex++;
        }
    }
    return uniqueIndex;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t uniqueIndex = 0;

    if (nmemb <= 1){
        return nmemb;
    }
    for (size_t i = 1; i < nmemb; ++i){
        uniqueIndex = (array, nmemb, i);
    }
    return uniqueIndex;
}

size_t uniq_array_loop(void *array, size_t nmemb, size_t size,
    int i, size_t uniqueIndex)
{
    size_t j;

    for (j = 0; j < uniqueIndex; ++j){
        if (compar(array + i * size, array + j * size) == 0){
            break;
        }
    }
    if (j == uniqueIndex){
            memmove(array + uniqueIndex * size, array + i * size, size);
    }
}

size_t uniq_array(void *array, size_t nmemb,
    size_t size, int (*compar)(const void *, const void *), size_t uniqueIndex)
{
    size_t uniqueIndex = 1;

    if (nmemb <= 1){
        return nmemb;
    }
    for (size_t i = 1; i < nmemb; ++i){
        uniq_array_loop(array, nmemb, size, i, uniqueIndex);
    }
    return uniqueIndex;
}

int compare_int(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}
