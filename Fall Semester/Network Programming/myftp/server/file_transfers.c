/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Command Directories
*/

#include "../libs/my_ftp.h"

int put_file(int client_socket, FILE *file)
{
    int data_socket;
    int rd = 0;
    char *buffer = {0};
    struct sockaddr_in pas;
    socklen_t size = sizeof(pas);

    data_socket = cur_user[client_socket]->fd_mod;
    if (cur_user[client_socket]->is_passive == 1){
        data_socket = accept(data_socket, (struct sockaddr *)&pas, &size);
        if (data_socket < 0)
            send_resp(client_socket, 552);
    }
    rd = recv(data_socket, buffer, BUFFER_SIZE, 0);
    while (rd > 0){
        fwrite(buffer, sizeof(char), strlen(buffer), file);
        rd = recv(data_socket, buffer, BUFFER_SIZE, 0);
    }
    fclose(file);
    close(data_socket);
    return 0;
}

int send_file(int client_socket, FILE *file)
{
    int data_socket;
    int rd;
    char buffer[MAXLINE];
    struct sockaddr_in pas;
    socklen_t size = sizeof(pas);

    data_socket = cur_user[client_socket]->fd_mod;
    if (cur_user[client_socket]->is_passive == 1){
        data_socket = accept(data_socket, (struct sockaddr *)&pas, &size);
        if (data_socket < 0)
            send_resp(client_socket, 552);
    }
    rd = MAXLINE;
    while (rd == MAXLINE){
        rd = fread(buffer, sizeof(char), MAXLINE - 1, file);
        dprintf(data_socket, "%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    close(data_socket);
    return 0;
}

int cmd_retr(int client_socket, char *cmdline)
{
    int retr_result = 0;
    FILE *file = fopen(cmdline, "rb");

    if (cur_user[client_socket]->is_passive != -1) {
        if (!file){
            send_resp(client_socket, 551);
        }
        send_resp(client_socket, 150);
        retr_result = send_file(client_socket, file);
        if (retr_result == 0){
            return send_resp(client_socket, 226);
        } else {
            return send_resp(client_socket, 426);
        }
        fclose(file);
    } else {
        return send_resp(client_socket, 425);
    }
}

int cmd_stor(int client_socket, char *cmdline)
{
    int stor_result = 0;
    FILE *file = fopen(cmdline, "wb");

    if (cur_user[client_socket]->is_passive != -1) {
        send_resp(client_socket, 150);
        stor_result = put_file(client_socket, file);
        if (stor_result == 0){
            return send_resp(client_socket, 226);
        } else {
            return send_resp(client_socket, 426);
        }
    } else {
        return send_resp(client_socket, 425);
    }
}
