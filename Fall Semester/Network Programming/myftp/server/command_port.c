/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Command Port
*/

#include "../libs/my_ftp.h"
#include <unistd.h>

int connect_to_server(int client_socket,
    int data_socket, struct sockaddr_in *address)
{
    if (connect(data_socket, (struct sockaddr *)address,
        sizeof(*address)) < 0) {
        printf("\nConnection failed");
        return -1;
    }
    cur_user[client_socket]->fd_mod = data_socket;
    return 0;
}

void configure_socket(struct sockaddr_in *data_socket_address,
    const char *ip, unsigned int port)
{
    data_socket_address->sin_family = AF_INET;
    data_socket_address->sin_addr.s_addr = inet_addr(ip);
    data_socket_address->sin_port = htons(port);
}

int port(int client_socket, char *cmdline)
{
    int data_socket = 0;
    int ip[4];
    int port[2];
    char pip[BUFFER_SIZE];
    unsigned int pport;
    struct sockaddr_in data_socket_address;

    sscanf(cmdline,
        "%d,%d,%d,%d,%d,%d",
        &ip[0], &ip[1], &ip[2], &ip[3], &port[0], &port[1]);
    memset(pip, 0, sizeof(pip));
    sprintf(pip, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    pport = port[0] << 8 | port[1];
    configure_socket(&data_socket_address, pip, pport);
    data_socket = create_socket();
    if (connect_to_server(client_socket, data_socket,
        &data_socket_address) == -1)
        return -1;
    else
        return 0;
}

int cmd_port(int client_socket, char *cmdline)
{
    if (cmdline == NULL || cmdline[0] == '\0') {
        return send_resp(client_socket, 502);
    }
    if (port(client_socket, cmdline) == 0){
        cur_user[client_socket]->is_passive = 0;
        return send_resp(client_socket, 200);
    } else {
        return send_resp(client_socket, 501);
    }
}
