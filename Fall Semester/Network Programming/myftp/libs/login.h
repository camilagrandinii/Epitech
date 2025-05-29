/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Login HeaderFile
*/

#ifndef LOGIN_H
    #define LOGIN_H
    #include "my_ftp.h"

int test_user(char *cp, int i, int list_size, int client_socket);
int cmd_user(int client_socket, char *cmdline);
int cmd_pass(int client_socket, char *cmdline);
void set_cur_user(char *username, char *password, int is_logged_in,
    char *home_dir);
char *replace_carriage_return(char *str);

#endif
