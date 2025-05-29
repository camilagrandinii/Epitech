/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Druid Thread File
*/
#include "../../libs/panoramix.h"

druid_t druid_og;
pthread_t _druid;

void start_druid(void)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    druid_og.mutex = mutex;
    if (pthread_create(&_druid, NULL, get_refill, &druid_og) != 0){
        printf("Erro ao criar a thread.\n");
        exit(84);
    }
    druid_og.nb_refills = parameters.nb_refills;
    druid_og.pot.pot_size = parameters.pot_size;
    druid_og.pot.potions_left = parameters.pot_size;
    sem_init(&druid_og.full, 0, 0);
    sem_init(&druid_og.empty, 0, 0);
    printf("Druid: I'm ready... but sleepy...\n");
}

void end_druid(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_cancel(_druid);
    pthread_join(_druid, 0);
}
