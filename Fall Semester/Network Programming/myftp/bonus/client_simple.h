/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Client HeaderFile
*/
#ifndef CLIENT_H
    #define CLIENT_H
    #define BUFFER_SIZE 1024
    #define MAX_CLIENTS 10
    #define NUMBER_OF_COMMANDS 13
    #define MAXLINE 4096
    #define FAILURE 84

    #include <arpa/inet.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/socket.h>
    #include <unistd.h>

struct commands_map {
    char *command;
    int (*cmd_handler)(int client_socket, char *cmd_line);
};

int connect_to_server(char *ip, int port_num);
void start_client_loop(int client_sc);
void print_exit(char *str);
void print_cli_help(void);

#endif
