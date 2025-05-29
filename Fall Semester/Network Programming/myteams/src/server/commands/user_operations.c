/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** User Operations File
*/
#include "../../../libs/database.h"
#include "../../../libs/server.h"
#include "../../../libs/myteams/logging_server.h"

int add_user_database(int position_to_add, char *username)
{
    strcpy(users[position_to_add]->user, username);
    users[position_to_add]->is_logged_in = 2;
    server_event_user_created("teste", username);
    return 1;
}

int add_user(char *username)
{
    int position_to_add = 0;

    position_to_add = get_available_position();
    if (position_to_add != -1){
        add_user_database(position_to_add, username);
        return 1;
    } else {
        printf("Não foi possível criar o usuário.\n");
        return -1;
    }
}

int cmd_user(int client_socket, request_t request)
{
    int user_index = 0;
    response_t response;

    user_index = find_user_index(request.args.arg_uuid.uuid);
    if (user_index != -1){
        response.code = print_user;
        strcpy(response.args.print_user.user_uuid,
            cur_user[client_socket]->id);
        strcpy(response.args.print_user.user_name,
            cur_user[client_socket]->user);
        response.args.print_user.user_status = 2;
    } else {
        response.code = error_unknown_user;
        printf("Usuário não encontrado.\n");
    }
    return send_structured_response(client_socket, response);
}

int cmd_users(int client_socket)
{
    char *all_users_info;
    char *user_info;

    all_users_info = malloc(MAX_ALL_USERS_STRING_LENGTH *
        MAX_USERS * sizeof(char));
    if (all_users_info == NULL) {
        return -1;
    }
    all_users_info[0] = '\0';
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i] != NULL) {
            user_info = user_to_string(users[i]);
            strcat(all_users_info, user_info);
            strcat(all_users_info, "\n");
            free(user_info);
        }
    }
    send_resp(client_socket, 200);
    free(all_users_info);
    return 1;
}
