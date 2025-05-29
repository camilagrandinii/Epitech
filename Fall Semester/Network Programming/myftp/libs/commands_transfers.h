/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Transfers HeaderFile
*/
#ifndef COMMANDS_TRANSFERS_H
    #define COMMANDS_TRANSFERS_H

int cmd_pasv(int client_socket, char *cmdline);
int cmd_port(int client_socket, char *cmdline);

#endif
