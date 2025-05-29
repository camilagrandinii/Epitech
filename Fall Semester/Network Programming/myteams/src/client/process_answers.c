/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File to process the answers from the server
*/
#include "../../libs/client.h"
#include "../../libs/my_teams.h"
#include "../../libs/myteams/logging_client.h"

int process_server_return(char *buffer, response_t response, int context)
{
    deserialize_response(buffer, &response);
    if (response.code == server_message)
        printf("%s\n", response.args.server_message.message);
    if (response.code == login || response.code == logout)
        response_login_logout(response);
    if (response.code >= create_team &&
        response.code <= create_thread_event)
        response_create(response);
    if (response.code == receive_reply || response.code == receive_message)
        response_receive(response);
    if (response.code >= print_users &&
        response.code <= print_private_messages)
        response_print(response);
    if (response.code == subscribed || response.code == unsubscribed)
        response_subscription(response);
    if (response.code >= error_unknown_team &&
        response.code <= error_already_exist)
        response_error(response);
    return check_context(response, context);
}

void response_error(response_t response)
{
    switch (response.code) {
    case error_unknown_team:
        client_error_unknown_team(response.args.error_unknown.uuid);
        break;
    case error_unknown_channel:
        client_error_unknown_channel(response.args.error_unknown.uuid);
        break;
    case error_unknown_thread:
        client_error_unknown_thread(response.args.error_unknown.uuid);
        break;
    case error_unknown_user:
        client_error_unknown_user(response.args.error_unknown.uuid);
        break;
    case error_unauthorized:
        client_error_unauthorized();
        break;
    case error_already_exist:
        client_error_already_exist();
        break;
    }
}

void response_receive(response_t response)
{
    if (response.code == receive_message) {
        client_event_private_message_received(
            response.args.receive_message.user_uuid,
            response.args.receive_message.message_body);
    } else {
        client_event_thread_reply_received(
            response.args.receive_reply.team_uuid,
            response.args.receive_reply.thread_uuid,
            response.args.receive_reply.user_uuid,
            response.args.receive_reply.reply_body);
    }
}

void response_login_logout(response_t response)
{
    if (response.code == login) {
        client_event_logged_in(
            response.args.login_logout.user_uuid,
            response.args.login_logout.user_name);
    } else {
        client_event_logged_out(
            response.args.login_logout.user_uuid,
            response.args.login_logout.user_name);
    }
}

int check_context(response_t response, int context)
{
    if (response.code == change_context) {
        return response.args.use_response.new_context;
    } else {
        return context;
    }
}
