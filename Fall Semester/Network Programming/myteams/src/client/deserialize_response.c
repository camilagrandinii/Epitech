/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File to process the answers from the server
*/
#include "../../libs/client.h"
#include "../../libs/my_teams.h"
#include "../../libs/myteams/logging_client.h"

void deserialize_response(char *buffer, response_t *response)
{
    memcpy(&(response->code), buffer, sizeof(enum code));
    buffer += sizeof(enum code);
    if (response->code == server_message)
        memcpy(&(response->args.server_message),
            buffer, sizeof(struct server_message_t));
    if (response->code == login || response->code == logout)
        memcpy(&(response->args.login_logout), buffer,
            sizeof(struct login_logout_t));
    if (response->code >= create_team &&
        response->code <= create_thread_event)
        memcpy(&(response->args.create_team_channel), buffer,
            sizeof(struct create_team_channel_t));
    if (response->code == receive_reply)
        memcpy(&(response->args.receive_reply), buffer,
            sizeof(struct receive_reply_t));
    deserialize_response_2(&buffer, &response);
}

void deserialize_response_2(char *buffer, response_t *response)
{
    if (response->code == receive_message)
        memcpy(&(response->args.receive_message), buffer,
            sizeof(struct receive_message_t));
    if (response->code >= print_users &&
        response->code <= print_private_messages)
        memcpy(&(response->args.print_user), buffer,
            sizeof(struct print_user_t));
    if (response->code == subscribed ||
        response->code == unsubscribed)
        memcpy(&(response->args.print_sub), buffer,
            sizeof(struct print_subscribed_unsubscribed_t));
    if (response->code >= error_unknown_team &&
        response->code <= error_already_exist)
        memcpy(&(response->args.error_unknown), buffer,
            sizeof(struct error_unknown_team_channel_thread_user_t));
}
