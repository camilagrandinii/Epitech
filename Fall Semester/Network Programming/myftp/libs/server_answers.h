/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Server Answers HeaderFile
*/
#ifndef SERVER_ANSWERS_H
    #define SERVER_ANSWERS_H
    #include "my_ftp.h"

int recv_msg(int fd, char buf[], int len);
void close_client_connection(int *client_sockets, int count);
int handle_command_request(int client_sockets, char *buf);
int handle_client_connection(int *client_sockets, int count);

#endif
