/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Channels Initializer File
*/
#include "../../libs/database.h"

channel_t channels[MAX_CHANNELS];

channel_t *initialize_channel(void)
{
    channel_t *channel = (channel_t *)malloc(sizeof(channel_t));

    if (channel == NULL) {
        printf("Erro ao alocar memória para o time\n");
        exit(EXIT_FAILURE);
    }
    uuid_generate(channel->id);
    channel->num_members = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        channel->members[i] = NULL;
    }
    return channel;
}

void initialize_channels(void)
{
    int i = 0;

    for (i = 0; i < MAX_CHANNELS; i++){
        channels[i] = *initialize_channel();
    }
}
