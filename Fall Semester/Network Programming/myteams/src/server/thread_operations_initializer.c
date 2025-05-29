/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Threads Initializer File
*/
#include "../../libs/database.h"

thread_t *initialize_thread(void)
{
    thread_t *thread;

    thread = (thread_t *)malloc(sizeof(thread_t));
    if (thread == NULL) {
        printf("Erro ao alocar memória para a thread\n");
    }
    uuid_generate(thread->id);
    strcpy(thread->title, "");
    strcpy(thread->message, "");
    thread->creator = NULL;
    thread->messages = NULL;
    return thread;
}

void initialize_threads(int team_index, int channel_index)
{
    int i = 0;

    for (i = 0; i < MAX_CHANNELS; i++){
        teams[team_index]
            .channels[channel_index].threads[i] = initialize_thread();
    }
}
