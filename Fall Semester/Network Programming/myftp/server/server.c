/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Server File
*/

#include "../libs/my_ftp.h"

struct server_struct *server;

void handle_client_activity(int *client_sockets, int count)
{
    if (handle_client_connection(client_sockets, count) != 0) {
        send_resp(client_sockets[count], 550);
        exit(FAILURE);
    }
}

int wait_for_activity(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int activity = 0;

    activity = select(FD_SETSIZE_MAX, current_sockets, NULL, NULL, NULL);
    if (activity < 0) {
        printf("select error");
    }
    return activity;
}

void handle_activity(int server_socket, int *client_sockets,
    fd_set *current_sockets)
{
    int i = 0;

    if (FD_ISSET(server_socket, current_sockets)) {
        accept_new_client(server_socket, client_sockets, current_sockets);
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

void static initialize_server_params(void)
{
    server = malloc(sizeof(struct server_struct));
    server->server_socket = 0;
    server->port = 8080;
    server->dir_ptr = NULL;
    strcpy(server->home_dir, "");
}

static void port_handling(int port)
{
    if (port > MAX_PORT || port < MIN_PORT) {
        exit(FAILURE);
    }
    server->port = port;
}

static void dir_handling(char *path)
{
    server->dir_ptr = opendir(path);
    if (server->dir_ptr == NULL) {
        printf("opendir error");
        exit(FAILURE);
    }
    if (chdir(path) == ERROR) {
        printf("chdir error");
        exit(FAILURE);
    }
    strcpy(server->home_dir, path);
}

static void error_treatment(int argc, char *argv[])
{
    int port = 0;

    if (argc != 3){
        printf("\nUsage: %s [port number] [path]\n", argv[0]);
        exit(FAILURE);
    }
    port = atoi(argv[1]);
    port_handling(port);
    dir_handling(argv[2]);
}

int main(int argc, char *argv[])
{
    int server_socket = 0;

    initialize_server_params();
    error_treatment(argc, argv);
    server->port = atoi(argv[1]);
    printf("The server port is %d\n",
        server->port);
    server_socket = create_server(server->port);
    wait_clients(server_socket,
        server->port);
    return 0;
}
