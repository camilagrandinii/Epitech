/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File
*/
#include "../../libs/server.h"
#include "../../libs/client.h"
#include "../../libs/my_teams.h"

enum commands map_context_create(enum commands base_cmd, int context)
{
    switch (context) {
    case 0:
        return create_team_cmd;
        break;
    case 1:
        return create_channel_cmd;
        break;
    case 2:
        return create_thread_cmd;
        break;
    case 3:
        return create_reply_cmd;
        break;
    default:
        break;
    }
}

enum commands map_context_list(enum commands base_cmd, int context)
{
    switch (context) {
    case 0:
        return list_teams_cmd;
        break;
    case 1:
        return list_channels_cmd;
        break;
    case 2:
        return list_threads_cmd;
        break;
    case 3:
        return list_replies_cmd;
        break;
    default:
        break;
    }
}

enum commands map_context_info(enum commands base_cmd, int context)
{
    switch (context) {
    case 0:
        return info_user_cmd;
        break;
    case 1:
        return info_team_cmd;
        break;
    case 2:
        return info_channel_cmd;
        break;
    case 3:
        return info_thread_cmd;
        break;
    default:
        break;
    }
}

enum commands map_other_commands(const char *str, int context)
{
    if (strcmp(str, "/unsubscribe") == 0)
        return unsubscribe_cmd;
    if (strcmp(str, "/use") == 0)
        return use_cmd;
    if (strcmp(str, "/create") == 0)
        return map_context_create(create_cmd, context);
    if (strcmp(str, "/list") == 0)
        return map_context_list(list_cmd, context);
    if (strcmp(str, "/info") == 0)
        return map_context_info(info_cmd, context);
    else
        return -1;
}

enum commands map_command(char *str, int context)
{
    if (strcmp(str, "/help") == 0)
        return help_cmd;
    if (strcmp(str, "/login") == 0)
        return login_cmd;
    if (strcmp(str, "/logout") == 0)
        return logout_cmd;
    if (strcmp(str, "/users") == 0)
        return users_cmd;
    if (strcmp(str, "/user") == 0)
        return user_cmd;
    if (strcmp(str, "/send") == 0)
        return send_cmd;
    if (strcmp(str, "/messages") == 0)
        return messages_cmd;
    if (strcmp(str, "/subscribe") == 0)
        return subscribe_cmd;
    if (strcmp(str, "/subscribed") == 0)
        return subscribed_cmd;
    else
        return map_other_commands(str, context);
}
