/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Server Initilizer File
*/
#include "../../libs/server.h"

user_t *users[MAX_USERS];

void initialize_client_sockets(int *client_sockets, int server_socket)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }
    client_sockets[0] = server_socket;
    initialize_users_array();
    initialize_users_teams_array();
}

void close_connections(int *client_sockets, int port_num)
{
    printf("Connection closed \t | PORT: %i\n", port_num);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] > 0){
            close(client_sockets[i]);
        }
    }
    exit(EXIT_SUCCESS);
}

static int create_socket(void)
{
    int server_socket = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket() failed!\n");
        exit(FAILURE);
    }
    return server_socket;
}

void bind_socket(int server_socket, int server_port)
{
    struct sockaddr_in serv;

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(server_port);
    if (bind(server_socket, (struct sockaddr *) &serv,
        sizeof(struct sockaddr)) < 0) {
        perror("bind() failed!\n");
        close(server_socket);
        exit(FAILURE);
    }
}

void start_listening(int server_socket)
{
    if (listen(server_socket, 10) < 0) {
        perror("listen() failed!\n");
        close(server_socket);
        exit(FAILURE);
    }
    printf("Listening for connections...\n");
}

int create_server(int server_port)
{
    int server_socket = 0;
    struct sockaddr_in serv;
    socklen_t len;

    server_socket = create_socket();
    bind_socket(server_socket, server_port);
    start_listening(server_socket);
    len = sizeof(serv);
    if (getsockname(server_socket, (struct sockaddr *) &serv, &len) == -1) {
        perror("getsockname() failed!\n");
        close(server_socket);
        exit(FAILURE);
    }
    printf("Create server listen socket successfully: %s:%d\n",
        inet_ntoa(serv.sin_addr), ntohs(serv.sin_port));
    return server_socket;
}
