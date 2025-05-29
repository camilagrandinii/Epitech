/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Commands for reading in files
*/
#include "../../libs/database.h"

user_t read_user_struct_from_file(char *file_path)
{
    struct user_t user;
    FILE *file = open_read(file_path);

    fread(&user, sizeof(struct user_t), 1, file);
    fclose(file);
    return user;
}
