/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Server File
*/
#include "../../libs/server.h"

void handle_client_activity(int *client_sockets, int count)
{
    if (handle_client_connection(client_sockets, count) != 0) {
        send_resp(client_sockets[count], 550);
        exit(EXIT_FAILURE);
    }
}

int wait_for_activity(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int activity = 0;

    printf("Server ready, wait client's connection...\n");
    activity = select(FD_SETSIZE_MAX, current_sockets, NULL, NULL, NULL);
    if (activity < 0) {
        perror("select error");
    }
    return activity;
}

void handle_activity(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int i = 0;

    if (FD_ISSET(server_socket, current_sockets)) {
        accept_new_client(server_socket, client_sockets);
    }
    for (i = 1; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] > 0
            && FD_ISSET(client_sockets[i], current_sockets)){
            handle_client_activity(client_sockets, i);
        }
    }
}

void wait_clients(int server_socket, int port_num)
{
    fd_set current_sockets;
    int client_sockets[MAX_CLIENTS];
    int select_result = 0;

    initialize_client_sockets(client_sockets, server_socket);
    while (1) {
        prepare_file_descriptors(server_socket, client_sockets,
            &current_sockets);
        select_result = wait_for_activity(server_socket, client_sockets,
            &current_sockets);
        if (select_result >= 0){
            handle_activity(server_socket, client_sockets,
            &current_sockets);
        }
    }
    close_connections(client_sockets, port_num);
}

int main(int argc, char *argv[])
{
    int server_port = 8080;
    int server_socket = 0;

    if (argc == 2) {
        server_port = atoi(argv[1]);
        server_socket = create_server(server_port);
        wait_clients(server_socket, server_port);
    }
    return 0;
}
