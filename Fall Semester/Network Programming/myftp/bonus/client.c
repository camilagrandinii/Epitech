#include "client.h"

int data_socket = 0;
bool active_mode_on = false;
bool already_connected = false;

commands_map cmds[] = {
    {"USER", client_generic},
    {"PASS", client_generic},
    {"CWD", client_generic},
    {"CDUP", client_generic},
    {"DELE", client_generic},
    {"PWD", client_generic},
    {"PASV", client_pasv},
    {"PORT", client_port},
    {"HELP", client_generic},
    {"NOOP", client_generic},
    {"RETR", client_retr},
    {"STOR", client_stor},
    {"LIST", client_list},
    {"QUIT", client_generic},
};

int configure_passive_socket(int client_socket,
    struct sockaddr_in *ip_addr)
{
    set_socket_parameters(ip_addr, 0, "127.0.0.1");
    return create_socket();
}

int bind_and_listen(int passive_socket, struct sockaddr_in *ip_addr)
{
    socklen_t addr_len = sizeof(struct sockaddr_in);

    if (bind(passive_socket, (struct sockaddr *)ip_addr,
        sizeof(struct sockaddr_in)) == -1) {
        perror("Bind failed");
        return -1;
    }
    if (getsockname(passive_socket, (struct sockaddr *)ip_addr,
        &addr_len) == -1) {
        printf("Getsockname failed");
        return -1;
    }
    printf("Listening on port: %d\n", ntohs(ip_addr->sin_port));
    if (listen(passive_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        return -1;
    }
    return passive_socket;
}

int client_pasv(int client_socket, char *buffer)
{
    int ip[4];
    int port[2];
    char pip[BUFFER_SIZE];
    unsigned int pport;
    struct sockaddr_in data_socket_address;

    sscanf(buffer,
        "%d,%d,%d,%d,%d,%d",
        &ip[0], &ip[1], &ip[2], &ip[3], &port[0], &port[1]);
    memset(pip, 0, sizeof(pip));
    sprintf(pip, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    pport = port[0] << 8 | port[1];
    set_socket_parameters(&data_socket_address, pport, pip);
    data_socket = create_socket();
    if (connect_to_server(data_socket,
        &data_socket_address) == -1)
        return -1;
    else
        return 0;
}

int client_port(int client_socket, char *buffer)
{
    struct sockaddr_in *ip_addr;
    memset(&ip_addr, '\0', sizeof(ip_addr));

    int passive_socket = configure_passive_socket(client_socket,
        ip_addr);

    if (passive_socket == -1)
        return -1;
    passive_socket = bind_and_listen(passive_socket, ip_addr);
    if (passive_socket == -1)
        return -1;
    data_socket = passive_socket;
    active_mode_on = true;
    return 0;
}

int client_list(int sock_data, char *buffer)
{
	size_t num_recvd;
	char buf[BUFFER_SIZE];
	int tmp = 0;

	memset(buf, 0, sizeof(buf));
	while ((num_recvd = recv(sock_data, buf, BUFFER_SIZE, 0)) > 0) {
        	printf("%s", buf);
		memset(buf, 0, sizeof(buf));
	}
	if (num_recvd < 0) {
	        perror("error");
	}
	return 0;
}

int client_retr(int data_socket, char *filename)
{
    char data[BUFFER_SIZE];
    int size;
    FILE* fd = fopen(filename, "w");

    if (fd == NULL) {
        perror("fopen");
        return -1;
    }
    while ((size = recv(data_socket, data, BUFFER_SIZE, 0)) > 0) {
        fwrite(data, 1, size, fd);
        printf("%s\n");
    }
    if (size < 0) {
        perror("error\n");
    }
    fclose(fd);
    return (0);
}

int client_stor(int client_socket, char *filename)
{
    int rd;
    char buffer[MAXLINE];
    FILE *fd = fopen(filename, "rb");
    if (fd == NULL) {
        perror("fopen");
        return -1;
    }
    rd = MAXLINE;
    while (rd == MAXLINE){
        rd = fread(buffer, sizeof(char), MAXLINE - 1, fd);
        dprintf(data_socket, "%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    close(data_socket);
    return (0);
}

int client_generic(int client_socket, char *buffer)
{
    return (0);
}

static int find_client_command_handler(char *cmd)
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

int connect_to_server(int data_socket,
    struct sockaddr_in *address)
{
    if (connect(data_socket, (struct sockaddr *)address,
        sizeof(*address)) < 0) {
        printf("Connection failed");
        exit(FAILURE);
    }
    printf("Connected to Server.\n");
    return 0;
}

int create_socket(void)
{
    int server_socket = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Socket() failed!\n");
        exit(FAILURE);
    }
    printf("Client Socket Created Sucessfully.\n");
    return server_socket;
}

void set_socket_parameters(struct sockaddr_in *server_addr,
    int port, char ip[])
{
    server_addr->sin_family = AF_INET;
	server_addr->sin_port = htons(port);
	server_addr->sin_addr.s_addr = inet_addr(ip);
}

void error_management(int argc, char *argv[], int *port)
{
    if (argc != 3){
        printf("\nUsage: %s [ip server] [port]\n", argv[0]);
        exit(FAILURE);
    }
    *port = atoi(argv[2]);
}

void prepare_message(char *buffer)
{
    bzero(buffer, BUFFER_SIZE);
    printf("[Client]: %s", buffer);
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\r\n");
}

void receive_message(int client_socket, char *buffer)
{
    bzero(buffer, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
	printf("[Server]: %s\n", buffer);
}

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

static void split_command_and_content(char *cmd,
    char *command, char *extra_info)
{
    char *space = strchr(cmd, ' ');

    if (space) {
        strncpy(command, cmd, space - cmd);
        command[space - cmd] = '\0';
        strcpy(extra_info, space + 1);
    } else {
        strcpy(command, cmd);
        extra_info[0] = '\0';
    }
}

void accept_client(void)
{
    struct sockaddr_in client;
    struct sockaddr *client_pointer;
    socklen_t *socklen_pointer;
    int addrlen = sizeof(client);

    socklen_pointer = (socklen_t *)&addrlen;
    client_pointer = (struct sockaddr *)&client;
    data_socket = accept(data_socket, client_pointer, socklen_pointer);
    if (data_socket < 0) {
        printf("accept error");
        exit(FAILURE);
    }
}

void main(int argc, char *argv[]){
	int client_socket = 0;
    int port = 0;
    int command_handler_num = 0;
    int command_handler_result = 0;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char extra_info[BUFFER_SIZE];

    error_management(argc, argv, &port);
	client_socket = create_socket();
	memset(&server_addr, '\0', sizeof(server_addr));
    bzero(&extra_info, BUFFER_SIZE);
    extra_info[strlen(extra_info)-1] = '\0';
    set_socket_parameters(&server_addr, port, argv[1]);
    connect_to_server(client_socket, &server_addr);
	recv(client_socket, buffer, BUFFER_SIZE, 0);
	printf("[Server]: %s", buffer);
    while(1){
        prepare_message(buffer);
        send(client_socket, buffer, strlen(buffer), 0);
        trim_white_space_and_carriage_return(buffer);
        split_command_and_content(buffer, command, extra_info);
        //printf("\ncommand: %s, info: %s\n", command, extra_info);
        command_handler_num = find_client_command_handler(command);
        if (command_handler_num == -1){
            printf("invalid command!!!");
            exit(FAILURE);
        }
        //printf("\ncommand num: %i", command_handler_num);
        //printf("\nactive mode: %i", active_mode_on);
        if (active_mode_on && !already_connected){
                if (command_handler_num == 10 || command_handler_num == 11
                || command_handler_num == 12){
                accept_client();
            }
        }
        command_handler_result = cmds[command_handler_num]
            .cmd_handler(client_socket, extra_info);
        receive_message(client_socket, buffer);
    }
    close(client_socket);
    printf("Disconnected from the server.\n");
}