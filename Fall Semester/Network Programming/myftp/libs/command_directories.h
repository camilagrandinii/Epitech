/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Directories HeaderFile
*/
#ifndef COMMAND_DIRECTORIES_H
    #define COMMAND_DIRECTORIES_H

int cmd_cwd(int client_socket, char *cmdline);
int cmd_cdup(int client_socket, char *cmdline);
int send_list(int client_socket, const char *pathname);
int cmd_list(int client_socket, char *cmdline);

#endif
