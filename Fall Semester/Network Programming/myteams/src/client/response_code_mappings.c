/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File to process the answers from the server
*/
#include "../../libs/client.h"
#include "../../libs/my_teams.h"
#include "../../libs/myteams/logging_client.h"

void response_subscription(response_t response)
{
    if (response.code == subscribed) {
        client_print_subscribed(response.args.print_sub.user_uuid,
        response.args.print_sub.team_uuid);
    } else {
        client_print_unsubscribed(response.args.print_sub.user_uuid,
        response.args.print_sub.team_uuid);
    }
}

void response_create(response_t response)
{
    if (response.code == create_team)
        client_print_team_created(response.args.print_team_channel.uuid,
            response.args.print_team_channel.name,
            response.args.print_team_channel.description);
    if (response.code == create_team_event)
        client_event_team_created(response.args.print_team_channel.uuid,
        response.args.print_team_channel.name,
        response.args.print_team_channel.description);
    if (response.code == create_channel)
        client_print_channel_created(response.args.print_team_channel.uuid,
        response.args.print_team_channel.name,
        response.args.print_team_channel.description);
    if (response.code == create_channel_event)
        client_event_channel_created(response.args.print_team_channel.uuid,
        response.args.print_team_channel.name,
        response.args.print_team_channel.description);
    if (response.code == create_thread || response.code == create_thread_event)
        response_create_rest(response);
}

void response_create_rest(response_t response)
{
    if (response.code == create_thread)
        client_print_thread_created(response.args.print_thread.thread_uuid,
        response.args.print_thread.user_uuid,
        response.args.print_thread.thread_timestamp,
        response.args.print_thread.thread_title,
        response.args.print_thread.thread_body);
    if (response.code == create_thread_event)
        client_event_thread_created(response.args.print_thread.thread_uuid,
        response.args.print_thread.user_uuid,
        response.args.print_thread.thread_timestamp,
        response.args.print_thread.thread_title,
        response.args.print_thread.thread_body);
}
