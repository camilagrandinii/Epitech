/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Server Sender File
*/
#include "../../libs/server.h"
#include "../../libs/my_teams.h"

void serialize_response(response_t response, char *buffer)
{
    memcpy(buffer, &(response.code), sizeof(enum code));
    buffer += sizeof(enum code);
    if (response.code == server_message)
        memcpy(buffer, &(response.args.server_message),
            sizeof(struct server_message_t));
    if (response.code == login || response.code == logout)
        memcpy(buffer, &(response.args.login_logout),
            sizeof(struct login_logout_t));
    if (response.code >= create_team &&
        response.code <= create_thread_event)
        memcpy(buffer, &(response.args.create_team_channel),
            sizeof(struct create_team_channel_t));
    if (response.code == receive_reply)
        memcpy(buffer, &(response.args.receive_reply),
            sizeof(struct receive_reply_t));
    serialize_response_2(response, &buffer);
}

void serialize_response_2(response_t response, char *buffer)
{
    if (response.code == receive_message)
        memcpy(buffer, &(response.args.receive_message),
            sizeof(struct receive_message_t));
    if (response.code >= print_users &&
        response.code <= print_private_messages)
        memcpy(buffer, &(response.args.print_user),
            sizeof(struct print_user_t));
    if (response.code == subscribed || response.code == unsubscribed)
        memcpy(buffer, &(response.args.print_sub),
            sizeof(struct print_subscribed_unsubscribed_t));
    if (response.code >= error_unknown_team &&
        response.code <= error_already_exist)
        memcpy(buffer, &(response.args.error_unknown),
            sizeof(struct error_unknown_team_channel_thread_user_t));
}
