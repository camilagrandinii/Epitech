/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Processing File
*/
#include "../libs/my_ftp.h"

struct cmd_struct cmds[] = {
    {"USER", cmd_user},
    {"PASS", cmd_pass},
    {"CWD", cmd_cwd},
    {"CDUP", cmd_cdup},
    {"DELE", cmd_dele},
    {"PWD", cmd_pwd},
    {"PASV", cmd_pasv},
    {"PORT", cmd_port},
    {"HELP", cmd_help},
    {"NOOP", cmd_noop},
    {"RETR", cmd_retr},
    {"STOR", cmd_stor},
    {"LIST", cmd_list},
    {"QUIT", cmd_quit},
};

struct user_struct *cur_user[MAX_SOCKET_NUMBER];

static int find_cmd_command_handler(char *cmd)
{
    int comparision_result = 0;
    int i = 0;

    if (cmd == NULL || *cmd == '\0'){
        return -1;
    }
    for (i = 0; i <= NUMBER_OF_COMMANDS; i++) {
        comparision_result = strcmp(cmd, cmds[i].command);
        if (comparision_result == 0) {
            return i;
        }
    }
    return -1;
}

static char *trim_white_space_and_carriage_return(char *str)
{
    char *end;

    while (isspace((unsigned char)*str)) {
        str++;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    if (*end == '\r') {
        *end = '\0';
    } else {
        end[1] = '\0';
    }
    strcpy(str, replace_carriage_return(str));
    return str;
}

int process_invalid_command(char *cmd, int client_socket)
{
    printf("received an unsupported cmd: %s\n", cmd);
    return send_resp(client_socket, 500);
}

int authorize_command(int command_handler_num,
    int client_socket, char *content)
{
    if (command_handler_num == 0 || command_handler_num == 1
        || command_handler_num == 8 || command_handler_num == 9
        || command_handler_num == 13){
        return cmds[command_handler_num]
            .cmd_handler(client_socket, content);
    } else {
        if (cur_user[client_socket]->is_logged_in == 2){
            return cmds[command_handler_num]
                .cmd_handler(client_socket, content);
        } else {
            send_resp(client_socket, 530);
        }
    }
}

static void split_command_and_content(char *cmd,
    char *command, char *content)
{
    char *space = strchr(cmd, ' ');

    if (space) {
        strncpy(command, cmd, space - cmd);
        command[space - cmd] = '\0';
        strcpy(content, space + 1);
    } else {
        strcpy(command, cmd);
        content[0] = '\0';
    }
}

int process_command(int client_socket, char *cmd)
{
    char command[256];
    char content[256];
    int command_handler_num = 0;

    cmd = trim_white_space_and_carriage_return(cmd);
    split_command_and_content(cmd, command, content);
    command_handler_num = find_cmd_command_handler(command);
    if (command_handler_num != -1) {
        return authorize_command(command_handler_num, client_socket, content);
    } else {
        printf("received an invalid cmd\n");
        process_invalid_command(command, client_socket);
    }
}

static int found_end(char *str)
{
    size_t i;

    for (i = 0; i < strlen(str) - 1; i++) {
        if (str[i] == '\r' && (i + 1) <= strlen(str)
            && str[i + 1] == '\n'){
            return 1;
        }
    }
    return -1;
}

int cmd_request(int client_socket, char buf[])
{
    char *end = &buf[strlen(buf) - 1];
    int err;

    if (found_end(buf) == 1) {
        strcat(cur_user[client_socket]->command_request, buf);
        err = process_command(client_socket,
            cur_user[client_socket]->command_request);
        strcpy(cur_user[client_socket]->command_request, "");
        return err;
    } else if (buf[0] != '\0'){
        strcat(cur_user[client_socket]->command_request, buf);
        err = 0;
        return err;
    } else {
        send_resp(client_socket, 140);
    }
}
