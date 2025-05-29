/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** User Operations Utils File
*/
#include "../../../libs/database.h"
#include "../../../libs/server.h"

int get_available_position()
{
    int j = 0;

    for (j = 0; j < MAX_USERS; j++) {
        if (strcmp(users[j]->user, "") == 0) {
            return j;
        }
    }
    return -1;
}

int find_user_index(uuid_t user_uui)
{
    for (int i = 0; i < MAX_USERS; i++) {
        if (uuid_compare(users[i]->id, user_uui) == 0) {
            return i;
        }
    }
    return -1;
}

char *uuid_to_string(uuid_t uuid)
{
    char *uuid_str;

    uuid_str = (char *)malloc(37);
    if (uuid_str == NULL) {
        printf("Memory allocation failed\n");
    }
    uuid_unparse(uuid, uuid_str);
    return uuid_str;
}

char *user_to_string(user_t *user)
{
    char *result;

    result = malloc(MAX_ALL_USERS_STRING_LENGTH * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        return NULL;
    }
    sprintf(result, "ID: %s\nUsername: %s\nPassword: %s\nLogged in: %s\n",
        uuid_to_string(user->id), user->user, user->pass,
            user->is_logged_in ? "true" : "false");
    return result;
}
