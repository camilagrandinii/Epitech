/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Command Pasv
*/

#include "../libs/my_ftp.h"

int configure_passive_socket(int client_socket,
    struct sockaddr_in *ip_addr)
{
    cur_user[client_socket]->passv_port = 0;
    configure_socket(ip_addr, "127.0.0.1",
        cur_user[client_socket]->passv_port);
    return create_socket();
}

int bind_and_listen(int passive_socket, struct sockaddr_in *ip_addr)
{
    socklen_t addr_len = sizeof(struct sockaddr_in);

    if (bind(passive_socket, (struct sockaddr *)ip_addr,
        sizeof(struct sockaddr_in)) == -1) {
        perror("Bind failed");
        return -1;
    }
    if (getsockname(passive_socket, (struct sockaddr *)ip_addr,
        &addr_len) == -1) {
        printf("Getsockname failed");
        return -1;
    }
    printf("Listening on port: %d\n", ntohs(ip_addr->sin_port));
    if (listen(passive_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        return -1;
    }
    return passive_socket;
}

int pasv(int client_socket, struct sockaddr_in *ip_addr)
{
    int passive_socket = configure_passive_socket(client_socket,
        ip_addr);

    if (passive_socket == -1)
        return -1;
    passive_socket = bind_and_listen(passive_socket, ip_addr);
    if (passive_socket == -1)
        return -1;
    cur_user[client_socket]->passv_port = ntohs(ip_addr->sin_port);
    cur_user[client_socket]->fd_mod = passive_socket;
    return passive_socket;
}

int cmd_pasv(int client_socket, char *cmdline)
{
    char msg[BUFFER_SIZE];
    struct sockaddr_in ip_addr;
    char message[1024];
    int port_high_byte = 0;
    int port_low_byte = 0;

    if (pasv(client_socket, &ip_addr) != -1){
        cur_user[client_socket]->is_passive = 1;
        port_low_byte = cur_user[client_socket]->passv_port & 0xFF;
        port_high_byte = cur_user[client_socket]->passv_port >> 8;
        snprintf(message, sizeof(message),
            "227 Entering Passive Mode (127,0,0,1,%d,%d).\r\n",
            port_high_byte, port_low_byte);
        return send_resp_variable(client_socket, message);
    } else {
        return send_resp(client_socket, 550);
    }
}
