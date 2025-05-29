/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Threads Operations File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"
#include "../../../libs/my_teams.h"
#include "../../../libs/myteams/logging_server.h"

int create_thread_database(int client_socket, int team_index,
    int channel_index,
    create_thread_t create_thread_info)
{
    int position_to_add = 0;
    response_t response;

    position_to_add = find_empty_thread(team_index, channel_index);
    if (position_to_add != -1){
        response.code = create_thread;
        server_event_thread_created(teams[team_index]
            .channels[channel_index].id,
            teams[team_index].channels[channel_index].
            threads[position_to_add]->id,
            create_thread_info.user_uuid,
            create_thread_info.thread_title, create_thread_info.thread_body);
        strcpy(create_thread_info.thread_uuid, teams[team_index].
            channels[channel_index].threads[position_to_add]->id);
        response.args.create_thread = create_thread_info;
    } else {
        response.code = error_unknown_thread;
    }
    return send_structured_response(client_socket, response);
}

static int create_thread_aux(int client_socket, char *title,
    char *message, uuid_t team_id)
{
    int team_index = 0;
    int channel_index = 0;
    create_thread_t create_thread_info;

    team_index = find_team_index(team_id);
    if (team_index != -1) {
            channel_index = find_channel_index(team_index, team_id);
            initialize_threads(team_index, channel_index);
            strcpy(create_thread_info.user_uuid, cur_user[client_socket]);
            strcpy(create_thread_info.thread_title, title);
            strcpy(create_thread_info.thread_body, message);
            strcpy(create_thread_info.description, message);
            return create_thread_database(client_socket,
                team_index, channel_index, create_thread_info);
    } else {
        printf("Team ID not found!!!.\n");
        return -1;
    }
}

int cmd_create_thread(int client_socket, request_t request)
{
    int uuid_test = 0;
    uuid_t id;

    uuid_test = check_uuid(request);
    if (uuid_test == -1){
        return -1;
    }
    if (create_thread_aux(client_socket,
        request.args.create_team_channel.name,
        request.args.create_team_channel.description,
        request.args.create_team_channel.uuid) == 0) {
        printf("Team created with success.\n");
        return 0;
    } else {
        printf("I was not possible to create the team.\n");
        return -1;
    }
    return -1;
}
