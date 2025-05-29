/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Commands Processing File
*/
#include "../../libs/server.h"
#include "../../libs/my_teams.h"

int recv_msg(int fd, char buf[], int len, request_t *request)
{
    int n;

    while (1) {
        n = read(fd, buf, len);
        if (n < 0) {
            continue;
        }
        deserialize_request(buf, request);
        return n;
    }
}

void close_client_connection(int *client_sockets, int count)
{
    close(client_sockets[count]);
    client_sockets[count] = 0;
    printf("Close the control connection OK\n");
}

int handle_client_connection(int *client_sockets, int count)
{
    char buf[BUFFER_SIZE];
    int buffer_length = 0;
    int client_socket = client_sockets[count];
    request_t request;

    buffer_length = recv_msg(client_socket, buf, sizeof(buf), &request);
    if (buffer_length < 0) {
        return -1;
    }
    if (buffer_length == 0)
        return -1;
    buf[buffer_length] = '\0';
    if (do_command(request, client_socket) == 1){
        close_client_connection(client_sockets, count);
        return 0;
    }
    return 0;
}

void deserialize_request(char *buffer, request_t *request)
{
    uint32_t command;

    memcpy(&command, buffer, COMMAND_SIZE);
    buffer += COMMAND_SIZE;
    request->command = (enum commands)command;
    if (request->command == login_cmd)
        memcpy(&request->args.arg_user_name, buffer,
            sizeof(struct arg_user_name_t));
    if (request->command == user_cmd ||
        request->command == send_cmd ||
        request->command == messages_cmd ||
        request->command == subscribe_cmd ||
        request->command == subscribed_cmd ||
        request->command == unsubscribe_cmd) {
        memcpy(&request->args.arg_uuid, buffer, sizeof(struct arg_uuid_t));
    }
    if (request->command == use_cmd)
        memcpy(&request->args.arg_use,
            buffer, sizeof(struct arg_use_t));
}
