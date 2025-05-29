/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Panoramix HeaderFile
*/
#ifndef PANORAMIX_H
    #define PANORAMIX_H
    #define MAX_VILLAGERS 60
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <semaphore.h>
    #include <signal.h>
    #include <pthread.h>
    #include <uuid/uuid.h>

typedef struct parameters_t {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} parameters_t;

typedef struct cooking_pot_t {
    int pot_size;
    int potions_left;
} cooking_pot_t;

typedef struct druid_t {
    cooking_pot_t pot;
    int nb_refills;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
} druid_t;

typedef struct villager_t {
    int id;
    int nb_fights;
    bool has_drank_potion;
    pthread_t thread;
    druid_t *druid;
} villager_t;

extern druid_t druid_og;
extern villager_t villagers[MAX_VILLAGERS];
extern parameters_t parameters;
extern pthread_t _druid;

// druid_ops.c
void *get_refill(void *args);

// druid_thread.c
void start_druid(void);
void end_druid(void);

// pot_ops.c
void start_pot(void);

// villager_ops.c
void druid_refill(villager_t *villager);
bool drink_potion(villager_t *villager);
void fight(villager_t *villager);

// villager_threads.c
void start_villagers(void);
void initialize_villager(int count, int nb_fights, villager_t *villager);
void end_villagers(void);

#endif
