/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Server HeaderFile
*/

#define MAX_CLIENTS 10
#define MAX_SOCKET_NUMBER 13
#define MAX_USER_STRING_LENGTH 100
#define MAX_ALL_USERS_STRING_LENGTH 2000
#define FD_SETSIZE_MAX 11
#define BUFFER_SIZE 1024
#define FAILURE 84
#define NUMBER_OF_COMMANDS 4
#define GETCURRENTDIR getcwd

#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ctype.h>
#include "my_teams.h"
#include "database.h"

#pragma once

// server_sender
char *resps_num_map(int num);
int send_partial(int fd, char *msg, int *offset, int *remaining);
int send_msg(int fd, char *msg, int len);
int send_resp(int fd, int num, ...);

// my_ftp
int send_resp(int fd, int num, ...);
char *resps_num_map(int num);

// server_inicializer
void close_connections(int *client_sockets, int port_num);
void initialize_client_sockets(int *client_sockets, int server_socket);
void bind_socket(int server_socket, int server_port);
void start_listening(int server_socket);
int create_server(int server_port);

// server_answers
int recv_msg(int fd, char buf[], int len, request_t *request);
void close_client_connection(int *client_sockets, int count);
int command_needs_login(int command_num);
void deserialize_request(char *buffer, request_t *request);

// serialize_response
void serialize_response(response_t response, char *buffer);

// commands_processing
int do_command(request_t request, int client_socket);
int process_invalid_command(int client_socket);
int authorize_command(int command_handler_num, int client_socket,
    request_t request);
int handle_client_connection(int *client_sockets, int count);

// file_descryptor_dealer
void add_client_socket(int client_socket, int *client_sockets);
void accept_new_client(int server_socket, int *client_sockets);
void update_max_descriptor(int client_identifier, int *max_client_descriptor);
void prepare_file_descriptors(int server_socket, int *client_sockets,
    fd_set *current_sockets);

// login
int cmd_logout(int client_socket, request_t request);
int cmd_login(int client_socket, request_t request);
int test_user(int client_socket, char *cmdline, int list_size);
void initialize_users_array(void);
void initialize_users_teams_array(void);

// general commands
int cmd_help(int client_socket, request_t request);

// teams initial handler
team_t *initialize_team(void);
void initialize_teams(void);
int find_empty_team(void);

// teams operations initials
int create_new_team(int client_socket, int new_team_index, char *team_name,
    char *team_description);
int process_new_team(int client_socket, char *team_name,
    char *team_description);
int cmd_create_team(int client_socket, request_t request);

// teams operations
int check_uuid(request_t request);
int cmd_leave_team(int client_socket, request_t request);
int cmd_subscribe(int client_socket, request_t request);
int cmd_subscribed(int client_socket, request_t request);

// teams operations utils
int check_uuid(request_t request);
int get_position_to_add_user(int team_index);
int is_user_already_on_team(int client_socket, int team_index);
int find_team_index(uuid_t team_uuid);
int find_channel_index(int team_index, uuid_t channel_uuid);

// user operations utils
int get_available_position(void);
int find_user_index(uuid_t user_uui);
char *user_to_string(user_t *user);

// threads operations utils
int find_thread_index(int team_index, int channel_index, uuid_t thread);
int find_empty_thread(int team_index, int channel_index);

// user operations
int cmd_user(int client_socket, request_t request);

// channels operations initializer
void initialize_channels(void);

// channels operations
int cmd_create_channel(int client_socket, request_t request);

// thread operations
int cmd_create_thread(int client_socket, request_t request);

// thread operations initiallizer
thread_t *initialize_thread(void);

// server sender
int send_structured_response(int client_socket, response_t response);

// prepare_responses
void prepare_login_logout_resp(response_t *response, int test_result);
void prepare_login_logout_error_resp(response_t response, int test_result);
void prepare_subscribed_resp(response_t response, int client_socket,
    int team_index);
void prepare_subscribed_error_resp(response_t response, int client_socket,
    int team_index);

extern struct user_t *cur_user[MAX_SOCKET_NUMBER];

struct user_struct {
    char user[20];
    char pass[20];
    int is_logged_in;
};

struct cmd_struct {
    char *command;
    int (*cmd_handler)(int client_socket, request_t request);
};
