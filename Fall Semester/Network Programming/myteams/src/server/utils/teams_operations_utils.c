/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Teams Operations Utils File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"

int find_team_index(uuid_t team_uuid)
{
    for (int i = 0; i < MAX_TEAMS; i++) {
        if (uuid_compare(teams[i].id, team_uuid) == 0) {
            return i;
        }
    }
    return -1;
}

int find_channel_index(int team_index, uuid_t channel_uuid)
{
    for (int i = 0; i < MAX_CHANNELS; i++) {
        if (uuid_compare(teams[team_index].channels[i].id,
            channel_uuid) == 0) {
            return i;
        }
    }
    return -1;
}

int is_user_already_on_team(int client_socket, int team_index)
{
    int j = 0;

    for (j = 0; j < teams[team_index].num_members; j++) {
        if (strcmp(teams[team_index].members[j]->user,
            cur_user[client_socket]->user) == 0) {
            return j;
        }
    }
    return -1;
}

int get_position_to_add_user(int team_index)
{
    int position_to_add = -1;
    int comparison_result = 0;

    for (position_to_add = 0;
        position_to_add < teams[team_index].num_members; position_to_add++) {
        comparison_result = strcmp(teams[team_index].
            members[position_to_add]->user, "");
        if (comparison_result == 0) {
            return position_to_add;
        }
    }
    return position_to_add;
}

int check_uuid(request_t request)
{
    uuid_t uuid;

    if (uuid_parse(
            (const char *)request.args.arg_uuid.uuid, uuid) != 0) {
        printf("UUID inválido.\n");
        return -1;
    }
    return 0;
}
