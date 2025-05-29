/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Villager Thread File
*/
#include "../../libs/panoramix.h"

villager_t villagers[MAX_VILLAGERS];

void start_villagers(void)
{
    int i;

    for (i = 0; i < parameters.nb_villagers; i++){
        initialize_villager(i, parameters.nb_fights,
            &villagers[i]);
    }
}

void initialize_villager(int count, int nb_fights, villager_t *villager)
{
    villager->id = count;
    villager->nb_fights = nb_fights;
    villager->has_drank_potion = false;
    villager->druid = &druid_og;
    villager->thread = (pthread_t)malloc(sizeof(pthread_t));
    pthread_create(&(villager->thread), NULL,
        (void *(*)(void *)) fight, villager);
    printf("Villager %i: Going into battle!\n", villager->id);
}

void end_villagers(void)
{
    int i;

    for (i = 0; i < parameters.nb_villagers; i++){
        pthread_join(villagers[i].thread, NULL);
        printf("Villager %d: I'm going to sleep now.\n", villagers[i].id);
    }
}
