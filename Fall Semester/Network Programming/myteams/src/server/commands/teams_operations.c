/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Teams Operations File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"

static int remove_user_from_team(int client_socket, int team_index)
{
    response_t response;

    teams[team_index].members[teams[team_index].num_members] = NULL;
    teams[team_index].num_members -= 1;
    server_event_user_unsubscribed(teams[team_index].id,
        cur_user[client_socket]->id);
    response.code = unsubscribed;
    strcpy(response.args.print_sub.user_uuid, cur_user[client_socket]->id);
    strcpy(response.args.print_sub.team_uuid, teams[team_index].id);
    return send_structured_response(client_socket, response);
}

static int leave_team(int client_socket, uuid_t team_uuid)
{
    int team_index = 0;
    int user_already_on_team = 0;

    team_index = find_team_index(team_uuid);
    if (team_index != -1) {
        user_already_on_team = is_user_already_on_team(client_socket,
            team_index);
        if (user_already_on_team == 1){
            remove_user_from_team(client_socket, team_index);
            return 0;
        } else {
            printf("O usuário não estava no time\n");
            return -1;
        }
    } else {
        printf("Time não encontrado.\n");
        return -1;
    }
}

static void add_user_team(int client_socket, int team_index)
{
    int position_to_add = 0;
    response_t response;

    teams[team_index].num_members += 1;
    position_to_add = get_position_to_add_user(team_index);
    teams[team_index].members[position_to_add] = cur_user[client_socket];
    server_event_user_subscribed(teams[team_index].id,
        cur_user[client_socket]->id);
    response.code = subscribed;
    strcpy(response.args.print_sub.user_uuid, cur_user[client_socket]->id);
    strcpy(response.args.print_sub.team_uuid, teams[team_index].id);
    send_structured_response(client_socket, response);
}

static int join_team(int client_socket, uuid_t team_uuid)
{
    int team_index = 0;
    int user_already_on_team = 0;

    team_index = find_team_index(team_uuid);
    if (team_index != -1) {
        user_already_on_team = is_user_already_on_team(client_socket,
            team_index);
        if (user_already_on_team == -1 &&
            teams[team_index].num_members < MAX_USERS - 1){
            add_user_team(client_socket, team_index);
            return 0;
        } else {
            printf("Limite de membros do time alcançado. \
                OU usuário já está no time\n");
            return -1;
        }
    } else {
        printf("Time não encontrado.\n");
        return -1;
    }
}

int cmd_subscribe(int client_socket, request_t request)
{
    int uuid_test = 0;

    uuid_test = check_uuid(request);
    if (uuid_test == -1){
        return -1;
    }
    if (join_team(client_socket, request.args.arg_uuid.uuid) == 0) {
        printf("Usuário adicionado ao time com sucesso.\n");
        return 0;
    } else {
        printf("Não foi possível adicionar o usuário ao time.\n");
        return -1;
    }
}

int cmd_leave_team(int client_socket, request_t request)
{
    int uuid_test = 0;

    uuid_test = check_uuid(request);
    if (uuid_test == -1){
        return -1;
    }
    if (leave_team(client_socket, request.args.arg_uuid.uuid) == 0) {
        printf("Usuário removido do time com sucesso.\n");
        return 0;
    } else {
        printf("Não foi possível remover o usuário do time.\n");
        return -1;
    }
}

int cmd_subscribed(int client_socket, request_t request)
{
    int uuid_test = 0;
    int team_index = 0;
    int user_index = 0;
    response_t response;

    uuid_test = check_uuid(request);
    if (uuid_test == -1){
        return -1;
    }
    team_index = find_team_index(request.args.arg_uuid.uuid);
    user_index = is_user_already_on_team(client_socket, team_index);
    if (user_index != -1){
        prepare_subscribed_resp(response, client_socket, team_index);
    } else {
        prepare_login_logout_error_resp(response, team_index);
    }
    return send_structured_response(client_socket, response);
}
