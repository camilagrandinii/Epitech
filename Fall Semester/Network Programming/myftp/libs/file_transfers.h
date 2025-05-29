/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** File Transfers HeaderFile
*/
#ifndef FILE_TRANSFERS_H
    #define FILE_TRANSFERS_H
    #include "my_ftp.h"

int cmd_retr(int client_socket, char *cmdline);
int cmd_stor(int client_socket, char *cmdline);

#endif
