/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Prepare Responses File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"
#include "../../../libs/myteams/logging_server.h"

void prepare_login_logout_resp(response_t *response, int test_result)
{
    response->code = login;
    strcpy(response->args.login_logout.user_uuid,
    cur_user[test_result]->id);
    strcpy(response->args.login_logout.user_name,
    cur_user[test_result]->user);
    server_event_user_loaded(cur_user[test_result]->id,
        response->args.login_logout.user_name);
}

void prepare_login_logout_error_resp(response_t response,
    int test_result)
{
    response.code = error_unknown_user;
}

void prepare_subscribed_resp(response_t response, int client_socket,
    int team_index)
{
    response.code = subscribed;
    strcpy(response.args.print_sub.user_uuid, cur_user[client_socket]->id);
    strcpy(response.args.print_sub.team_uuid, teams[team_index].id);
}

void prepare_subscribed_error_resp(response_t response, int client_socket,
    int team_index)
{
    response.code = error_unknown_user;
    strcpy(response.args.print_sub.user_uuid, cur_user[client_socket]->id);
    strcpy(response.args.print_sub.team_uuid, teams[team_index].id);
}
