/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** File Descriptor Dealer HeaderFile
*/
#ifndef FILE_DESCRIPTOR_DEALER_H
    #define FILE_DESCRIPTOR_DEALER_H
    #include "my_ftp.h"
    #include "server_initializer.h"

void add_client_socket(int client_socket, int *client_sockets);
void accept_new_client(int server_socket, int *client_sockets,
    fd_set *current_sockets);
void update_max_descriptor(int client_identifier, int *max_client_descriptor);
void prepare_file_descriptors(int server_socket, int *client_sockets,
    fd_set *current_sockets);
#endif
