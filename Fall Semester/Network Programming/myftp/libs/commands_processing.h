/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Processing HeaderFile
*/
#ifndef COMMANDS_PROCESS_H
    #define COMMANDS_PROCESS_H
    #define GETCURRENTDIR getcwd

    #include "my_ftp.h"

int cmd_quit(int client_socket, char *cmdline);
int cmd_user(int client_socket, char *cmdline);
int cmd_pass(int client_socket, char *cmdline);
int cmd_request(int client_socket, char buf[]);
void handle_sigint(int client_socket, int sig);

struct cmd_struct {
    char *command;
    int (*cmd_handler)(int client_socket, char *cmd_line);
};

#endif
