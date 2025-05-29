/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Commands Functionalities File
*/

#include "../libs/my_ftp.h"

char help_answer[][2048] = {
    "\n\nUSER <SP> <username> <CRLF>   : Specify user for authentication"
    "\nPASS <SP> <password> <CRLF>   : Specify password for authentication"
    "\nCWD  <SP> <pathname> <CRLF>   : Change working directory"
    "\nCDUP <CRLF>"
    ": Change working directory to parent directory"
    "\nQUIT <CRLF>                   : Disconnection"
    "\nDELE <SP> <pathname> <CRLF>"
    ": Delete file on the server"
    "\nPWD  <CRLF>"
    ": Print working directory"
    "\nPASV <CRLF>"
    ": Enable \"passive\" mode for data transfer"
    "\nPORT <SP> <host-port> <CRLF>"
    ": Enable \"active\" mode for data transfer"
    "\nHELP [<SP> <string>] <CRLF>"
    ": List available commands"
    "\nNOOP <CRLF>                   : Do nothing"
    "\n\n(the following are commands using data transfer )\n"
    "\nRETR <SP> <pathname> <CRLF>   : Download file from server to client"
    "\nSTOR <SP> <pathname> <CRLF>   : Upload file from client to server"
    "\nLIST [<SP> <pathname>] <CRLF>"
    ": List files in the current working directory\n"
};

int cmd_pwd(int client_socket, char *cmdline)
{
    char curdir[PATH_MAX];
    char *cp;
    int send_resp_result = 0;
    char buf[1024];

    if (getcwd(curdir, sizeof(curdir)) == NULL)
        return send_resp(client_socket, 550);
    cp = &curdir[strlen(cur_user[client_socket]->cur_dir)];
    if (*cp == '\0') {
        *cp = '/';
    }
    curdir[sizeof(curdir) - 1] = '\0';
    snprintf(buf, sizeof(buf), "257 %s created.\r\n", curdir);
    return send_resp_variable(client_socket, buf);
}

int cmd_quit(int client_socket, char *cmdline)
{
    send_resp(client_socket, 221);
    return 1;
}

int cmd_noop(int client_socket, char *cmdline)
{
    return send_resp(client_socket, 200);
}

int cmd_help(int client_socket, char *cmdline)
{
    return send_resp(client_socket, 214);
}

int cmd_dele(int client_socket, char *cmdline)
{
    int result = 0;

    result = remove(cmdline);
    if (result == 0) {
        return send_resp(client_socket, 250);
    } else {
        fprintf(stderr, "Erro ao deletar o arquivo: %s\n", strerror(errno));
        return send_resp(client_socket, 550);
    }
}
