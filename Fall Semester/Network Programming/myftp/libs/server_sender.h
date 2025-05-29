/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** server Sender HeaderFile
*/
#ifndef SERVER_SENDER_H
    #define SERVER_SENDER_H

char *resps_num_map(int num);
int send_partial(int fd, char *msg, int *offset, int *remaining);
int send_msg(int fd, char *msg, int len);
int send_resp(int fd, int num, ...);
int send_resp_variable(int client_socket, char *message);

#endif
