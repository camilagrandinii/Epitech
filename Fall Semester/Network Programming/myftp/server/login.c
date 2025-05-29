/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Login File
*/
#include "../libs/my_ftp.h"

struct user_struct users[] = {
    {"Anonymous", ""},
    {"Camila", "1234"}
};

char *replace_carriage_return(char *str)
{
    char new_str[100];
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\r' && str[i] != '\n') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    strcpy(str, new_str);
    return str;
}

int test_pass(char *cmdline, int list_size, int client_socket)
{
    int i = 0;
    int test_result = 0;
    int user_to_test = 0;

    for (i = 0; i < list_size; i++){
        if (strcmp(cur_user[client_socket]->user, users[i].user) == 0){
            test_result = 1;
            user_to_test = i;
        }
    }
    if (test_result == 1){
        cmdline = replace_carriage_return(cmdline);
        if (strcmp(cmdline, users[user_to_test].pass) == 0) {
            strcpy(cur_user[client_socket]->pass, cmdline);
            cur_user[client_socket]->is_logged_in = 2;
            return 1;
        }
    }
    return 0;
}

int cmd_user(int client_socket, char *cmdline)
{
    if (cmdline) {
        strcpy(cur_user[client_socket]->user, cmdline);
        cur_user[client_socket]->is_logged_in = 1;
        return send_resp(client_socket, 331);
    }
    return send_resp(client_socket, 550);
}

int cmd_pass(int client_socket, char *cmdline)
{
    int i;
    int test_result = 0;
    int list_size = sizeof(users) / sizeof(users[0]);

    if (cur_user[client_socket]->user) {
        test_result = test_pass(cmdline, list_size, client_socket);
        if (test_result){
            return send_resp(client_socket, 230);
        } else {
            printf("Password for user %s is wrong.\n",
            cur_user[client_socket]->user);
            return send_resp(client_socket, 530);
        return 0;
        }
    } else {
        cur_user[client_socket] = NULL;
        return send_resp(client_socket, 530);
    }
}

static void set_properties_user(int user_index, int is_logged_in)
{
    cur_user[user_index]->fd_mod = -1;
    cur_user[user_index]->passv_port = -1;
    cur_user[user_index]->is_passive = -1;
    cur_user[user_index]->is_logged_in = is_logged_in;
    cur_user[user_index]->command_request[0] = '\0';
}

void set_cur_user(char *username, char *password, int is_logged_in,
    char *home_dir)
{
    int i = 0;

    for (i; i < MAX_SOCKET_NUMBER; i++){
        if (cur_user[i] == NULL) {
        cur_user[i] = malloc(sizeof(struct user_struct));
        }
        if (cur_user[i] != NULL) {
            cur_user[i]->user[0] = '\0';
            cur_user[i]->pass[0] = '\0';
            cur_user[i]->cur_dir[0] = '\0';
            cur_user[i]->ip[0] = '\0';
            set_properties_user(i, is_logged_in);
        } else {
            fprintf(stderr, "Erro ao alocar memória para cur_user\n");
            exit(FAILURE);
        }
    }
}
