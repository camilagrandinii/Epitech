/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Processing HeaderFile
*/
#ifndef COMMANDS_FUNCTIONALITIES_H
    #define COMMANDS_FUNCTIONALITIES_H

int cmd_pwd(int client_socket, char *cmdline);
int cmd_help(int client_socket, char *cmdline);
int cmd_noop(int client_socket, char *cmdline);
int cmd_dele(int client_socket, char *cmdline);

#endif
