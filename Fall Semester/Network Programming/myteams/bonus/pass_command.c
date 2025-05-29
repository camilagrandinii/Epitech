/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Login File
*/
#include "../libs/server.h"
#include "../libs/database.h"
#include "../libs/myteams/logging_server.h"

int cmd_pass(int client_socket, request_t request)
{
    if (cur_user[client_socket]) {
        if (strlen(cur_user[client_socket]->pass) == 0
            || strcmp(request.args.arg_user_name.user_name, cur_user[client_socket]->pass) == 0) {
            printf("Password for user %s is correct.\n",
                cur_user[client_socket]->user);
            cur_user[client_socket]->is_logged_in = 2;
            return send_resp(client_socket, 230,
                cur_user[client_socket]->user);
        }
        printf("Password for user %s is wrong.\n",
            cur_user[client_socket]->user);
    }
    cur_user[client_socket] = NULL;
    return send_resp(client_socket, 530, "");
}