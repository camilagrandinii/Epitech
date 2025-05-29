/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Login File
*/
#include "../../../libs/server.h"
#include "../../../libs/database.h"
#include "../../../libs/myteams/logging_server.h"

static void load_users(void)
{
    users[0] = (user_t *)malloc(sizeof(user_t));
    uuid_clear(users[0]->id);
    strcpy(users[0]->user, "Anonymous");
    strcpy(users[0]->pass, "");
    users[0]->is_logged_in = 0;
    strcpy(users[0]->context.team_id, "");
    strcpy(users[0]->context.channel_id, "");
    strcpy(users[0]->context.thread_id, "");
    users[1] = (user_t *)malloc(sizeof(user_t));
    uuid_clear(users[1]->id);
    strcpy(users[1]->user, "Camila");
    strcpy(users[1]->pass, "1234");
    users[1]->is_logged_in = 0;
    strcpy(users[1]->context.team_id, "");
    strcpy(users[1]->context.channel_id, "");
    strcpy(users[1]->context.thread_id, "");
}

int test_user(int client_socket, char *cmdline, int list_size)
{
    int i = 0;

    for (i = 0; i < list_size; i++){
        printf("comparando user[%i]: %s com %s", i, users[i]->user, cmdline);
        if (strcmp(cmdline, users[i]->user) == 0) {
            printf("user(%s) is found\n", cmdline);
            cur_user[client_socket] = &users[i];
            return i;
        }
    }
    return -1;
}

int cmd_login(int client_socket, request_t request)
{
    int test_result = 0;
    int list_size = MAX_USERS;
    response_t response;

    if (request.args.arg_user_name.user_name) {
        test_result = test_user(client_socket,
            request.args.arg_user_name.user_name, list_size);
        if (test_result == -1){
            prepare_login_logout_error_resp(response, test_result);
            printf("user (%s) not found\n",
                request.args.arg_user_name.user_name);
        } else {
            prepare_login_logout_resp(&response, test_result);
        }
    }
    return send_structured_response(client_socket, response);
}

void initialize_users_array(void)
{
    int i = 0;

    for (i = 0; i < MAX_SOCKET_NUMBER; i++) {
        cur_user[i] = (user_t *)malloc(sizeof(user_t));
        if (cur_user[i] == NULL) {
            printf("Erro ao alocar memória para o usuário %d.\n", i);
        }
        uuid_generate(cur_user[i]->id);
        strncpy(cur_user[i]->user, "", MAX_NAME_LENGTH);
        strncpy(cur_user[i]->pass, "", MAX_NAME_LENGTH);
        cur_user[i]->is_logged_in = 0;
        strcpy(cur_user[i]->context.team_id, "");
        strcpy(cur_user[i]->context.channel_id, "");
        strcpy(cur_user[i]->context.thread_id, "");
    }
}

void initialize_users_teams_array(void)
{
    int i = 0;

    for (i = 0; i < MAX_USERS; i++) {
        users[i] = (user_t *)malloc(sizeof(user_t));
        if (users[i] == NULL) {
            printf("Erro ao alocar memória para o usuário %d.\n", i);
        }
        uuid_generate(users[i]->id);
        strncpy(users[i]->user, "", MAX_NAME_LENGTH);
        strncpy(users[i]->pass, "", MAX_NAME_LENGTH);
        users[i]->is_logged_in = 0;
        strcpy(users[i]->context.team_id, "");
        strcpy(users[i]->context.channel_id, "");
        strcpy(users[i]->context.thread_id, "");
    }
    load_users();
}

int cmd_logout(int client_socket, request_t request)
{
    response_t response;

    response.code = logout;
    strcpy(response.args.login_logout.user_uuid,
    cur_user[client_socket]->id);
    strcpy(response.args.login_logout.user_name,
    cur_user[client_socket]->user);
    server_event_user_logged_out(cur_user[client_socket]->id);
    send_structured_response(client_socket, response);
    return 1;
}
