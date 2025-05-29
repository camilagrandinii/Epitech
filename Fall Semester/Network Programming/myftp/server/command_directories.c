/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Command Directories
*/

#include "../libs/my_ftp.h"

int cmd_cwd(int client_socket, char *cmdline)
{
    int result = 0;

    printf("NEW PATH: %s", cmdline);
    if (chdir(cmdline) == 0) {
        strcpy(cur_user[client_socket]->cur_dir, cmdline);
        return send_resp(client_socket, 250);
    } else {
        fprintf(stderr, "Error changing directory: %s\n",
            strerror(errno));
        return send_resp(client_socket, 550);
    }
}

int cmd_cdup(int client_socket, char *cmdline)
{
    if (chdir("..") == 0) {
        return send_resp(client_socket, 200);
    } else {
        fprintf(stderr, "Error changing directory to parent directory: %s\n",
            strerror(errno));
        return send_resp(client_socket, 550);
    }
}

int list_files(int client_socket, FILE *file)
{
    char buffer[MAXLINE];
    struct sockaddr_in s_in;
    socklen_t size = sizeof(s_in);
    int fd_new = 0;

    fd_new = cur_user[client_socket]->fd_mod;
    if (cur_user[client_socket]->is_passive == 1){
    fd_new = accept(fd_new, (struct sockaddr *)&s_in, &size);
        if (fd_new < 0)
            send_resp(client_socket, 552);
    }
    while (!feof(file) &&
        fgets(buffer, 4096, file)){
        dprintf(fd_new, "%s", buffer);
        memset(buffer, 0, MAXLINE);
    }
    fclose(file);
    close(fd_new);
    return 0;
}

int cmd_list(int client_socket, char *cmdline)
{
    int list_result = 0;
    FILE *file = popen("ls -la", "r");

    if (cur_user[client_socket]->is_passive != -1) {
        if (!file){
            return send_resp(client_socket, 450);
        }
        send_resp(client_socket, 150);
        list_result = list_files(client_socket, file);
        if (list_result == 0){
            return send_resp(client_socket, 226);
        } else {
            return send_resp(client_socket, 426);
        }
    } else {
        return send_resp(client_socket, 425);
    }
}
