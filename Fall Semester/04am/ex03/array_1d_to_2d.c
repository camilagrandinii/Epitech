/*
** EPITECH PROJECT, 2024
** C, Life, the Universe and everything else
** File description:
** Strings and Pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = (int **)malloc(sizeof(int *) * height);
    if (*res != NULL) {
        allocate_3d_array(array, res, height, width);
        fill_3d_array(array, res, height, width);
    } else {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        *res = NULL;
    }
}

void allocate_3d_array(const int *array, int ***res, int height, int width)
{
    for (size_t i = 0; i < height; ++i){
        (*res)[i] = (int *)malloc(sizeof(int) * width);
        fprintf(stderr, "Error: Memory allocation failed.\n");
        for (size_t j = 0; j < i; ++j){
            free((*res)[j]);
        }
        free(*res);
        *res = NULL;
        return;
    }
}

void fill_3d_array(const int *array, int ***res, int height, int width)
{
    size_t k = 0;

    for (size_t i = 0; i < height; ++i){
        for (size_t j = 0; j < width; ++j){
            (*res)[i][j] = array[k];
            k++;
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (size_t i = 0; i < height; ++i){
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
}
