/*
** EPITECH PROJECT, 2024
** My FTP
** File description:
** Server Sender File
*/
#include "../libs/my_ftp.h"

char server_resps[][1200] = {
    "120 Service ready in 2 minutes.\r\n",
    "140 Message received and stored, waiting for the rest"
    "of the content!\r\n",
    "125 Data connection already open; transfer starting.\r\n",
    "150 File status okay; about to open data connection.\r\n",
    "200 Command okay.\r\n",
    "214 Help message. On how to use the server or the meaning of a"
    "particular non-standard command. USER [username] | PASS [pass] | "
    "CWD [dir] | CDUP | DELE [filename] | PWD [dir] | PASV | PORT [IP]"
    "| HELP | NOOP | RETR | STOR | LIST | QUIT\r\n",
    "This reply is useful only to the human user.\n\r",
    "220 Service ready for new user.\r\n",
    "221 Service closing control connection.\nLogged out if appropriate.\r\n",
    "226 Closing data connection. Requested "
    "file action successful (for example, file transfer or file abort).\r\n",
    "227 Entering Passive Mode (127,0,0,1,0,0).\r\n",
    "230 User logged in, proceed.\n",
    "250 Requested file action okay, completed.\r\n",
    "257 PATHNAME created.\r\n",
    "331 User name okay, need password.\r\n",
    "332 Need account for login.\r\n",
    "425 Use PORT or PASV first\r\n",
    "426 Problem with connection\r\n",
    "450 Unable to list files\r\n",
    "500 Unsupport command\r\n",
    "501 Wasn't able to connect to client's data connection\r\n",
    "502 Incorret usage of PORT!!! Correct usage: PORT [IP]\r\n",
    "530 Login failed\r\n",
    "550 Error\r\n",
    "551 Failed to open file.\r\n",
    "552 Unable to perform socket.\r\n"
};

char *resps_num_map(int num)
{
    int i;
    char buf[8];

    snprintf(buf, sizeof(buf), "%d", num);
    if (strlen(buf) != 3)
        return NULL;
    for (i = 0; i < (sizeof(server_resps) / sizeof(server_resps[0])); i++){
        if (strncmp(buf, server_resps[i], 3) == 0)
            return server_resps[i];
    }
    return NULL;
}

int send_partial(int fd, char *msg, int *offset, int *remaining)
{
    int n = 0;

    n = write(fd, msg + *offset, *remaining);
    if (n < 0) {
        if (errno == EINTR)
            return 0;
        return n;
    }
    *offset += n;
    *remaining -= n;
    return 1;
}

int send_msg(int fd, char *msg, int len)
{
    int offset = 0;
    int remaining = len;
    int result = 0;

    while (remaining > 0) {
        result = send_partial(fd, msg, &offset, &remaining);
        if (result < 0)
            return result;
    }
    return len;
}

int send_resp(int fd, int num, ...)
{
    char *cp = resps_num_map(num);
    va_list ap;
    char buf[BUFFER_SIZE];

    if (!cp) {
        printf("resps_num_map(%d) failed\n", num);
        return -1;
    }
    va_start(ap, num);
    vsnprintf(buf, sizeof(buf), cp, ap);
    va_end(ap);
    printf("Server response code: %s\n", buf);
    if (send_msg(fd, buf, strlen(buf)) != strlen(buf)) {
        printf("send_msg() failed: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

int send_resp_variable(int client_socket, char *message)
{
    int result = 0;

    printf("Server response code: %s\n", message);
    result = send_msg(client_socket, message, strlen(message));
    if (result != strlen(message)) {
        printf("send_msg() failed: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}
