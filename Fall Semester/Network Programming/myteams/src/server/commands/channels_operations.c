/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Channels Operations File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"
#include "../../../libs/myteams/logging_server.h"

int get_position_to_add_channel(int team_index)
{
    int position_to_add = -1;
    int test_result = 0;

    for (position_to_add = 0;
        position_to_add < MAX_CHANNELS; position_to_add++) {
        test_result = strcmp(teams[team_index].
            channels[position_to_add].name, "");
        if (test_result == 0) {
            return position_to_add;
        }
    }
    return position_to_add;
}

int create_channel_database(int client_socket, int team_index,
    char *name, char *description)
{
    int channel_index = 0;
    response_t response;

    channel_index = get_position_to_add_channel(team_index);
    if (channel_index != -1){
        strcpy(teams[team_index].channels[channel_index].name,
            name);
        strcpy(teams[team_index].channels[channel_index].description,
            description);
        response.code = create_channel;
        strcpy(response.args.create_team_channel.name, name);
        strcpy(response.args.create_team_channel.description, description);
        server_event_channel_created(teams[team_index].id,
            teams[team_index].channels[channel_index].id, name);
    } else {
        response.code = error_unknown_channel;
        printf("ERROR: These team has already enough channels!!!");
    }
    return send_structured_response(client_socket, response);
}

static int create_channel_aux(int client_socket, char *channel_name,
    char *channel_description, uuid_t team_id)
{
    int team_index = 0;

    team_index = find_team_index(team_id);
    if (team_index != -1) {
        return create_channel_database(client_socket, team_index, channel_name,
            channel_description);
    } else {
        printf("Team ID not found!!!.\n");
        return -1;
    }
}

int cmd_create_channel(int client_socket, request_t request)
{
    int uuid_test = 0;

    initialize_channels();
    uuid_test = check_uuid(request);
    if (uuid_test == -1){
        return -1;
    }
    if (create_channel_aux(client_socket, request.args.
        create_team_channel.name, request.args.create_team_channel.description,
        request.args.create_team_channel.uuid) == 0) {
        printf("Team created with success.\n");
        return 0;
    } else {
        printf("I was not possible to create the team.\n");
        return -1;
    }
}
