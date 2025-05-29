/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Database HeaderFile
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#define MAX_USERS 20
#define MAX_CHANNELS 20
#define MAX_THREADS 20
#define MAX_TEAMS 10
#define MAX_MESSAGES ((MAX_USERS * (MAX_USERS - 1)) / 2)

#define MAX_BODY_LENGTH 512
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255


#pragma once

// user data
typedef struct message_t {
    char name_sender[MAX_NAME_LENGTH];
    char name_receiver[MAX_NAME_LENGTH];
    char content[MAX_BODY_LENGTH];
    char date[MAX_NAME_LENGTH];
} message_t;

typedef struct message_node_t {
    message_t message;
    struct message_node_t *next;
} message_node_t;

typedef struct context_definition_t {
    uuid_t team_id;
    uuid_t channel_id;
    uuid_t thread_id;
} context_definition_t;


typedef struct user_t {
    uuid_t id;
    char user[MAX_NAME_LENGTH];
    char pass[MAX_NAME_LENGTH];
    int is_logged_in;
    context_definition_t context;
} user_t;

typedef struct personal_messages_t {
    uuid_t id;
    user_t users[2];
    struct message_node_t *messages;
} personal_messages_t;

typedef struct thread_t {
    uuid_t id;
    char title[MAX_NAME_LENGTH];
    char message[MAX_DESCRIPTION_LENGTH];
    user_t *creator;
    message_node_t *messages;
} thread_t;

typedef struct channel_t {
    uuid_t id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    user_t *members[MAX_USERS];
    int num_members;
    thread_t *threads[MAX_THREADS];
    int num_threads;
} channel_t;

typedef struct team_t {
    uuid_t id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    user_t *members[MAX_USERS];
    int num_members;
    channel_t channels[MAX_CHANNELS];
} team_t;

extern user_t *users[MAX_USERS];
extern team_t teams[MAX_TEAMS];
extern channel_t channels[MAX_CHANNELS];
extern personal_messages_t personal_messages[MAX_MESSAGES];

// file_handling
FILE *open_write(const char *file_path);
FILE *open_read(const char *file_path);

// write
void write_user_struct_in_file(char *file_path, user_t user);

// read
user_t read_user_struct_from_file(const char *file_path);

// utils
size_t get_number_of_elements_in_array(void *array);
long get_size_of_file(FILE *file);
