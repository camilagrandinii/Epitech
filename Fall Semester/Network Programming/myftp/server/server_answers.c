/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Processing File
*/
#include "../libs/my_ftp.h"

int recv_msg(int fd, char buf[], int len)
{
    int n;

    while (1){
        n = read(fd, buf, len);
        if (n < 0) {
            continue;
            return n;
        }
        return n;
    }
}

void close_client_connection(int *client_sockets, int count)
{
    close(client_sockets[count]);
    client_sockets[count] = 0;
    printf("Close the control connection OK\n");
}

int handle_command_request(int client_socket, char *buf)
{
    int quit_flag = 0;

    quit_flag = cmd_request(client_socket, buf);
    return quit_flag;
}

int handle_client_connection(int *client_sockets, int count)
{
    char buf[BUFFER_SIZE];
    int buffer_length = 0;
    int client_socket = client_sockets[count];

    buffer_length = recv_msg(client_socket, buf, sizeof(buf));
    if (buffer_length < 0) {
        return -1;
    }
    if (buffer_length == 0)
        return -1;
    buf[buffer_length] = '\0';
    if (handle_command_request(client_socket, buf)){
        close_client_connection(client_sockets, count);
        return 0;
    }
    return 0;
}
