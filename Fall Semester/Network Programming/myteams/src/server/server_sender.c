/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Server Sender File
*/
#include "../../libs/server.h"

char server_resps[][1024] = {
    "120 Service ready in 2 minutes.\r\n",
    "125 Data connection already open; transfer starting.\r\n",
    "150 File status okay; about to open data connection.\r\n",
    "200 Command okay.\r\n",
    "214 Help message.\nOn how to use the server or the meaning of a"
    "particular non-standard command."
    "This reply is useful only to the human user.\n",
    "220 Service ready for new user.\n",
    "221 Service closing control connection.\nLogged out if appropriate.\n",
    "226 Closing data connection.\nRequested"
    "file action successful (for example, file transfer or file abort).\n",
    "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n",
    "230 User logged in, proceed.\n",
    "250 Requested file action okay, completed.\n",
    "257 PATHNAME created.\n",
    "331 User name okay, need password.\n",
    "332 Need account for login.\n",
    "500 Unsupport command\r\n",
    "530 Login failed\r\n",
    "550 Error\r\n"
};

char *resps_num_map(int num)
{
    int i;
    char buf[8];

    snprintf(buf, sizeof(buf), "%d", num);
    if (strlen(buf) != 3)
        return NULL;
    for (i = 0; i < 20; i++){
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

int send_structured_response(int client_socket,
    response_t response)
{
    char buffer[2048] = {0};
    size_t buffer_size;

    buffer_size = strlen(buffer) + 1;
    serialize_response(response, buffer);
    if (send(client_socket, buffer, sizeof(response), 0) < 0){
        printf("Error in sending data");
        return -1;
    }
    return 0;
}
