/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** My FTP HeaderFile
*/
#ifndef MY_FTP_H
    #define MY_FTP_H
    #define PATH_MAX 1024
    #define MAX_CLIENTS 10
    #define MAX_SOCKET_NUMBER 13
    #define FD_SETSIZE_MAX 11
    #define MAXLINE 4096
    #define BUFFER_SIZE 1024
    #define FAILURE 84
    #define ERROR -1
    #define NUMBER_OF_COMMANDS 13
    #define MIN_PORT 1
    #define MAX_PORT 65534

    #include <netinet/in.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <ctype.h>
    #include <signal.h>
    #include "command_directories.h"
    #include "command_port.h"
    #include "commands_functionalities.h"
    #include "commands_processing.h"
    #include "commands_transfers.h"
    #include "file_descriptor_dealer.h"
    #include "file_transfers.h"
    #include "login.h"
    #include "server_answers.h"
    #include "server_initializer.h"
    #include "server_sender.h"

extern struct user_struct *cur_user[MAX_SOCKET_NUMBER];
extern struct server_struct *server;
struct user_struct {
    char user[20];
    char pass[20];
    char cur_dir[20];
    char ip[20];
    char command_request[BUFFER_SIZE];
    int fd_mod;
    int passv_port;
    int is_passive;
    int is_logged_in;
};

struct server_struct {
    int server_socket;
    int port;
    DIR *dir_ptr;
    char home_dir[20];
};

#endif
