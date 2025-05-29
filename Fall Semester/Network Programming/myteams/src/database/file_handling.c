/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Commands for writing in files
*/

#include "../../libs/database.h"

FILE *open_write(const char *file_path)
{
    FILE *file = fopen(file_path, "wb");

    if (file == NULL) {
        printf("Couldn't open file: bad path.\n");
        return NULL;
    }
    return file;
}

FILE *open_read(const char *file_path)
{
    FILE *file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Couldn't open file: bad path.\n");
        return NULL;
    }
    return file;
}
