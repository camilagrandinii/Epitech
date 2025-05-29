/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Teams Operations Initial File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"

int create_new_team(int client_socket, int new_team_index, char *team_name,
    char *team_description)
{
    response_t response;

    strcpy(teams[new_team_index].name, team_name);
    strcpy(teams[new_team_index].description, team_description);
    response.code = create_team;
    strcpy(response.args.create_team_channel.name, team_name);
    strcpy(response.args.create_team_channel.description, team_description);
    return send_structured_response(client_socket, response);
}

int process_new_team(int client_socket, char *team_name,
    char *team_description)
{
    int empty_team = 0;

    empty_team = find_empty_team();
    if (empty_team == -1) {
    printf("NÃO há espaço para a criação de novos times\n");
    } else {
        create_new_team(client_socket, empty_team,
            team_name, team_description);
    }
    printf("Time criado com sucesso!\n");
    return 0;
}

int cmd_create_team(int client_socket, request_t request)
{
    int comparison_result = 0;

    initialize_teams();
    for (int i = 0; i < MAX_TEAMS; i++) {
        comparison_result = strcmp(teams[i].name, "");
        if (comparison_result == 0) {
            process_new_team(client_socket,
                request.args.create_team_channel.name,
                request.args.create_team_channel.description);
        }
    }
    printf("Limite de times alcançado. \
        Não é possível criar um novo time.\n");
    return -1;
}
