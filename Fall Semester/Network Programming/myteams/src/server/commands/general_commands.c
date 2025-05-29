/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** General Commands File
*/
#include "../../../libs/server.h"

char help_answer[][2048] = {
    "\n\n/help : show help and lists the available commands"
    "\n/login <SP> \"<username>\" <CRLF>   : Specify the"
    "user_name used by client"
    "\n/logout"
    "\n/users : get the list of all users that exist"
    "on the domain"
    "\n/user \"<user_uuid>\" : get details about"
    "the requested user"
    "\n/send \"<user_uuid>\" \"message_body\" : send a"
    "message to specified user"
    "\n/messages \"user_uuid\" : list all messages"
    "exchanged with the specified user"
    "\n/subscribe \"<team_uuid>\" : subscribe to the"
    "events of a team and its sub directories"
    "(enable reception of all events from a team)"
    "\n/subscribed ? <SP> \"<team_uuid>\" : list all subscribed"
    "teams or list all users subscribed to a team"
    "\n/unsubscribe \"<team_uuid>\" : unsubscribe from a team"
    "\n/use ? \"<team_uuid>\" ? \"<channel_uuid>\"  ? \"<thread_uuid>\""
    " : Sets the command context to a team/channel/thread"
    "\n/create : based on the context, create the sub"
    "resource (see below)"
    "\n/list : based on the context, list all the sub"
    "resources (see below)"
    "\n/info : based on the context, display details of the"
    "current resource (see below)\n"
};

int cmd_help(int client_socket, request_t request)
{
    response_t response;

    response.code = server_message;
    strcpy(response.args.server_message.message, help_answer[0]);
    return send_structured_response(client_socket, response);
}

int cmd_use(int client_socket, request_t request)
{
    response_t response;
    int index;
    int num_of_args = request.args.arg_use.num_of_args;

    response.code = change_context;
    response.args.use_response.new_context = request.args.arg_use.num_of_args;
    if (num_of_args >= 1 && request.args.arg_use.team_id) {
            strcmp(cur_user[client_socket]->context.team_id,
                request.args.arg_use.team_id);
    }
    if (num_of_args >= 2 && request.args.arg_use.channel_id) {
            strcmp(cur_user[client_socket]->context.channel_id,
                request.args.arg_use.channel_id);
    }
    if (num_of_args == 3 && request.args.arg_use.thread_id) {
        strcmp(cur_user[client_socket]->context.thread_id,
            request.args.arg_use.thread_id);
    }
    return send_structured_response(client_socket, response);
}
