/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Commands Processing File
*/
#include "../../libs/server.h"
#include "../../libs/database.h"
#include "../../libs/my_teams.h"

struct cmd_struct cmds[] = {
    {"/help", cmd_help},
    {"/login", cmd_login},
    {"/logout", cmd_logout},
    {"/users", cmd_user},
    {"/user", cmd_user},
    {"/send", cmd_user},
    {"/subscribe", cmd_subscribe},
    {"/subscribed", cmd_subscribed},
    {"/unsubscribe", cmd_leave_team},
    {"/use", cmd_user},
    {"/create_team", cmd_create_team},
    {"/create_channel", cmd_create_channel},
    {"/create_thread", cmd_create_thread},
};

struct user_t *cur_user[MAX_SOCKET_NUMBER];

int do_command(request_t request, int client_socket)
{
    int command_handler_num = request.command;

    if (command_handler_num != -1) {
        return authorize_command(command_handler_num,
            client_socket, request);
    }
    return process_invalid_command(request.command);
}

int process_invalid_command(int client_socket)
{
    printf("received an unsupported cmd\n");
    return send_resp(client_socket, 500);
}

int authorize_command(int command_handler_num, int client_socket,
    request_t request)
{
    if (command_needs_login(command_handler_num) == 0){
        return cmds[command_handler_num]
            .cmd_handler(client_socket, request);
    } else {
        if (cur_user[client_socket]->is_logged_in == 2){
            return cmds[command_handler_num]
                .cmd_handler(client_socket, request);
        } else {
            send_resp(client_socket, 550);
            return -1;
        }
    }
}

int command_needs_login(int command_num)
{
    if (command_num >= 0 && command_num <= 4) {
        return 0;
    } else {
        return 1;
    }
}
