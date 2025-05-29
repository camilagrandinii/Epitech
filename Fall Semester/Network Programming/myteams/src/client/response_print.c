/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File to process the answers from the server
*/
#include "../../libs/client.h"
#include "../../libs/my_teams.h"
#include "../../libs/myteams/logging_client.h"

void response_print(response_t response)
{
    if (response.code >= print_user && response.code <= print_thread)
        print_single(response);
    else
        print_list(response);
}

void print_single(response_t response)
{
    if (response.code == print_user)
        client_print_user(response.args.print_user.user_uuid,
            response.args.print_user.user_name,
            response.args.print_user.user_status);
    if (response.code == print_team)
        client_print_team(response.args.print_team_channel.uuid,
            response.args.print_team_channel.name,
            response.args.print_team_channel.description);
    if (response.code == print_channel)
        client_print_channel(response.args.print_team_channel.uuid,
            response.args.print_team_channel.name,
            response.args.print_team_channel.description);
    if (response.code == print_thread)
        client_print_thread(response.args.print_thread.thread_uuid,
            response.args.print_thread.user_uuid,
            response.args.print_thread.thread_timestamp,
            response.args.print_thread.thread_title,
            response.args.print_thread.thread_body);
}

void print_list(response_t response)
{
    int i = 0;

    if (response.code == print_users)
        for (i = 0; i < response.args.print_all_users.size_array; i++)
            client_print_users(response.args.print_all_users.users[i].
            user_uuid, response.args.print_all_users.users[i].user_name,
            response.args.print_all_users.users[i].user_status);
    if (response.code == print_teams)
        for (i = 0; i < response.args.print_all_teams_channels.size_array; i++)
            client_print_teams(response.args.print_all_teams_channels.
            list[i].uuid, response.args.print_all_teams_channels.list[i].name,
            response.args.print_all_teams_channels.list[i].description);
    if (response.code == print_team_channels)
        for (i = 0; i < response.args.print_all_teams_channels.size_array; i++)
            client_team_print_channels(response.args.print_all_teams_channels.
            list[i].uuid, response.args.print_all_teams_channels.list[i].name,
            response.args.print_all_teams_channels.list[i].description);
    if (response.code == print_channel_threads || response.code ==
    print_thread_replies || response.code == print_private_messages)
            print_list_2(response);
}

void print_list_2(response_t response)
{
    int i = 0;

    if (response.code == print_channel_threads)
        for (i = 0; i < response.args.print_all_threads.size_array; i++)
            client_channel_print_threads(response.args.print_all_threads.
                threads[i].thread_uuid,
                response.args.print_all_threads.threads[i].user_uuid,
                response.args.print_all_threads.threads[i].thread_timestamp,
                response.args.print_all_threads.threads[i].thread_title,
                response.args.print_all_threads.threads[i].thread_body);
    if (response.code == print_thread_replies)
        for (i = 0; i < response.args.print_all_replies.size_array; i++)
            client_thread_print_replies(response.args.print_all_replies.
                replies[i].thread_uuid,
                response.args.print_all_replies.replies[i].user_uuid,
                response.args.print_all_replies.replies[i].reply_timestamp,
                response.args.print_all_replies.replies[i].reply_body);
    if (response.code == print_private_messages)
        print_list_3(response);
}

void print_list_3(response_t response)
{
    int i = 0;

    for (i = 0; i < response.args.print_all_messages.size_array; i++)
            client_private_message_print_messages(
                response.args.print_all_messages.messages[i].sender_uuid,
                response.args.print_all_messages.messages[i].message_timestamp,
                response.args.print_all_messages.messages[i].message_body);
}
