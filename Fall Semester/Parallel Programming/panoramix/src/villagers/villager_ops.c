/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Villager Ops File
*/
#include "../../libs/panoramix.h"

void druid_refill(villager_t *villager)
{
    printf("Villager %i: Hey Pano wake up! "
        "We need more potion.\n", villager->id);
    sem_post(&druid_og.empty);
    sem_wait(&druid_og.full);
}

bool drink_potion(villager_t *villager)
{
    pthread_mutex_lock(&druid_og.mutex);
    printf("Villager %i: I need a drink... I see %i "
        "servings left.\n", villager->id,
        druid_og.pot.potions_left);
    if (druid_og.pot.potions_left < 0){
        if (druid_og.nb_refills <= 0){
            pthread_mutex_unlock(&druid_og.mutex);
            return false;
        }
        druid_refill(villager);
    } 
    druid_og.pot.potions_left--;
    pthread_mutex_unlock(&druid_og.mutex);
    return true;
}

void fight(villager_t *villager)
{
    while (villager->nb_fights > 0){
        drink_potion(villager);
        villager->nb_fights--;
        printf("Villager %i: Take that roman scum! "
                "Only %i left.\n", villager->id, villager->nb_fights);
    }
}
