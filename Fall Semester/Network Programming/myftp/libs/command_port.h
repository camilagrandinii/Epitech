/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Port HeaderFile
*/
#ifndef COMMAND_PORT_H
    #define COMMAND_PORT_H

int connect_to_server(int client_socket,
    int data_socket, struct sockaddr_in *address);
void configure_socket(struct sockaddr_in *data_socket_address,
    const char *ip, unsigned int port);
int port(int client_socket, char *cmdline);
int cmd_port(int client_socket, char *cmdline);

#endif
