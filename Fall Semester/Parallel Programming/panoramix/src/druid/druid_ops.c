/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Druid Operations File
*/
#include "../../libs/panoramix.h"

void *get_refill(void *args)
{
    while (druid_og.nb_refills > 0){
        sem_wait(&druid_og.empty);
        druid_og.nb_refills--;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! "
            "Beware I can only make %i more refills after this one.\n",
            druid_og.nb_refills);
        druid_og.pot.potions_left = druid_og.pot.pot_size;
        sem_post(&druid_og.full);
    }
    end_druid();
}
