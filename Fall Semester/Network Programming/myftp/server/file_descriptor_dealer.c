/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** File Descriptor Dealer File
*/

#include "../libs/my_ftp.h"

void add_client_socket(int client_socket, int *client_sockets)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == 0) {
            client_sockets[i] = client_socket;
            break;
        }
    }
}

void accept_new_client(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int client_socket;
    struct sockaddr_in client;
    struct sockaddr *client_pointer;
    socklen_t *socklen_pointer;
    int addrlen = sizeof(client);

    socklen_pointer = (socklen_t *)&addrlen;
    client_pointer = (struct sockaddr *)&client;
    client_socket = accept(server_socket, client_pointer, socklen_pointer);
    if (client_socket < 0) {
        printf("accept error");
        exit(FAILURE);
    }
    add_client_socket(client_socket, client_sockets);
    send_resp(client_socket, 220);
}

void update_max_descriptor(int client_identifier, int *max_client_descriptor)
{
    if (client_identifier > *max_client_descriptor) {
        *max_client_descriptor = client_identifier;
    }
}

void prepare_file_descriptors(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int i;
    int max_client_descriptor = server_socket;
    int client_identifier = 0;

    FD_ZERO(current_sockets);
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_identifier = client_sockets[i];
        if (client_identifier >= 0) {
            FD_SET(client_identifier, current_sockets);
            update_max_descriptor(client_identifier, &max_client_descriptor);
        }
    }
}
