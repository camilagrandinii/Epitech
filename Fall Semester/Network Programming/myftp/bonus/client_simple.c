/*
** EPITECH PROJECT, 2024
** My_teams
** File description:
** Client File
*/
#include "client_simple.h"

void print_cli_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\
    ip   is the server ip address on which the server socket listens.\n\
    port is the port number on which the server socket listens\n");
}

void print_exit(char *str)
{
    printf("%s\n", str);
    return;
}

int main(int argc, char *argv[])
{
    int port_num;
    char *p;

    if (argc != 3) {
        print_cli_help();
        exit(FAILURE);
    }
    port_num = strtol(argv[2], &p, 10);
    connect_to_server(argv[1], port_num);
    return 0;
}

void start_client_loop(int client_sc)
{
    char buffer[BUFFER_SIZE] = {0};
    int context = 0;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (read(client_sc, buffer, sizeof(buffer)) < 0)
            print_exit("Error in receiving data");
        printf("Server: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
        printf("Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);
        strcat(buffer, "\r\n");
        if (send(client_sc, buffer, sizeof(buffer), 0) < 0)
            print_exit("Error in sending data");
    }
    close(client_sc);
}

int connect_to_server(char *ip, int port_num)
{
    int status;
    int client_sc;
    struct sockaddr_in serv_addr;

    client_sc = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    status = connect(client_sc, (struct sockaddr *)&serv_addr,
        sizeof(serv_addr));
    if (client_sc < 0 || inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0
        || status < 0)
        return -1;
    printf("Connected to server.\n");
    start_client_loop(client_sc);
}