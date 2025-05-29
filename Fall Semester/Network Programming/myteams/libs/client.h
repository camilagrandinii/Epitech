/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Client HeaderFile
*/
#include <stdio.h>
#include "my_teams.h"
#pragma once

typedef struct key_value_pair_t {
    char key[20];
    char value[20];
} key_value_pair_t;

// client
void print_cli_help(void);
void start_client_loop(int client_sc);
int connect_to_server(char *ip, int port_num);

// map commands
enum commands map_command(char *str, int context);

// process message functions
request_t process_command(char *command_line, int context);
void serialize_request(request_t request, char *buffer);

// process server answers
int process_server_return(char *buffer, response_t response, int context);
void deserialize_response(char *buffer, response_t *response);
void response_error(response_t response);
void response_receive(response_t response);
void response_login_logout(response_t response);

// response code mappings
void response_subscription(response_t response);
void response_create(response_t response);
void response_print(response_t response);
