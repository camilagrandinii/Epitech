/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Threads Operations Utils File
*/

#include "../../../libs/database.h"
#include "../../../libs/server.h"
#include "../../../libs/myteams/logging_server.h"

int find_thread_index(int team_index, int channel_index, uuid_t thread)
{
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        if (uuid_compare(teams[team_index].
            channels[channel_index].threads[i]->id, thread) == 0) {
            return i;
        }
    }
    return -1;
}

int find_empty_thread(int team_index, int channel_index)
{
    int i = 0;
    int comparison_result = 0;

    for (i = 0; i < MAX_TEAMS; i++){
        comparison_result = strcmp(teams[team_index].
            channels[channel_index].threads[i]->title, "");
        if (comparison_result == 0){
            return i;
        }
    }
    return -1;
}
