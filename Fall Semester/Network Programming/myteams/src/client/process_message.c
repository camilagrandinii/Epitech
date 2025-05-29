/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File
*/
#include "../../libs/client.h"
#include "../../libs/my_teams.h"
#include <stdio.h>
#include <string.h>

char *clean_arg_string(char *str)
{
    char *end;

    while (isspace((unsigned char)*str)) {
        str++;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    if (*end == '\r') {
        *end = '\0';
    } else {
        end[1] = '\0';
    }
    return str;
}

int check_format(char *str)
{
    char *end;
    int error = 1;

    if (*str == '\0')
        error = 0;
    if (*str != '"')
        error = 0;
    end = str;
    while (*end != '\0')
        end++;
    if (*(end - 1) != '"')
        error = 0;
    error = 1;
    if (error == 0) {
        printf("ERROR in arguments\n");
        return -1;
    }
    return 0;
}

void serialize_request(request_t request, char *buffer)
{
    uint32_t command = (uint32_t)request.command;

    memcpy(buffer, &command, COMMAND_SIZE);
    buffer += COMMAND_SIZE;
    if (request.command == login_cmd) {
        memcpy(buffer, &request.args.arg_user_name,
            sizeof(struct arg_user_name_t));
    } else if (request.command == use_cmd) {
        memcpy(buffer, &request.args.arg_use,
            sizeof(struct arg_use_t));
    } else {
        memcpy(buffer, &request.args.arg_uuid, sizeof(struct arg_uuid_t));
    }
}

void get_command_args(char *args[], int num_of_args,
    request_t *request, int context)
{
    if (request->command == login_cmd && num_of_args == 1)
        strcpy(request->args.arg_user_name.user_name, args[0]);
    if ((request->command == user_cmd || request->command == send_cmd
        || request->command == messages_cmd
        || request->command == subscribe_cmd
        || request->command == subscribed_cmd
        || request->command == unsubscribe_cmd) && num_of_args == 1) {
        strcpy(request->args.arg_uuid.uuid, args[0]);
    }
    if (request->command == use_cmd && num_of_args >= 1 && num_of_args <= 3) {
        strcpy(request->args.arg_use.team_id, args[0]);
        if (num_of_args >= 2)
            strcpy(request->args.arg_use.channel_id, args[1]);
        if (num_of_args == 3)
            strcpy(request->args.arg_use.thread_id, args[2]);
        request->args.arg_use.context = context;
        request->args.arg_use.num_of_args = num_of_args;
    }
}

request_t process_command(char *command_line, int context)
{
    request_t request;
    int count = 0;
    char *token = strtok(command_line, " ");
    char *args[3];

    token = clean_arg_string(token);
    request.command = map_command(token, context);
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            args[count] = token;
            check_format(args[count]);
            args[count] = clean_arg_string(args[count]);
            count++;
        }
    }
    get_command_args(args, count, &request, context);
    return request;
}
