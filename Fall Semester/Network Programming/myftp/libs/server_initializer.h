/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Server Initilizer HeaderFile
*/
#include "my_ftp.h"

#ifndef INITIALIZER_H
    #define INITIALIZER_H

void initialize_client_sockets(int *client_sockets, int server_socket);
void close_connections(int *client_sockets, int port_num);
int create_socket(void);
void bind_socket(int server_socket, int server_port);
int create_server(int server_port);

#endif
