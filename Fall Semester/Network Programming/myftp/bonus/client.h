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
    #include <stdbool.h>
    #include <ctype.h>

typedef struct commands_map {
    char *command;
    int (*cmd_handler)(int client_socket, char *cmd_line);
} commands_map;

int configure_passive_socket(int client_socket,
    struct sockaddr_in *ip_addr);
int bind_and_listen(int passive_socket, struct sockaddr_in *ip_addr);
int connect_to_server(int data_socket,
    struct sockaddr_in *address);
int create_socket(void);
void set_socket_parameters(struct sockaddr_in *server_addr, int port, char ip[]);
void error_management(int argc, char *argv[], int *port);
void prepare_message(char *buffer);
char *replace_carriage_return(char *str);
void receive_message(int client_socket, char *buffer);
void extract_command_info(char *extra_info, char *buffer);
void accept_client(void);

/* CLIENT FUNCTIONALITIES */
int client_pasv(int client_socket, char *buffer);
int client_port(int client_socket, char *buffer);
int client_list(int client_socket, char *buffer);
int client_retr(int client_socket, char *buffer);
int client_stor(int client_socket, char *buffer);
int client_generic(int client_socket, char *buffer);

#endif
