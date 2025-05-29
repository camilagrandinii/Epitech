/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Commands for writing in files
*/
#include "../../libs/database.h"

void write_user_struct_in_file(char *file_path, user_t user)
{
    FILE *file = open_write(file_path);

    fwrite(&user, sizeof(struct user_t), 1, file);
    fclose(file);
}
