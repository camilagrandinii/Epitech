/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Client HeaderFile
*/
#include <stdio.h>
#include <uuid/uuid.h>
#include <stdint.h>
#include "database.h"
#define COMMAND_SIZE sizeof(uint32_t)
#define BUFFER_MAX 4096
#pragma once

// request from client to server
struct arg_user_name_t {
    char user_name[120];
};

struct arg_uuid_t {
    uuid_t uuid;
};

struct arg_uuid_message_t {
    uuid_t user_uuid;
    char message_body[120];
};

struct arg_use_t {
    uuid_t team_id;
    uuid_t channel_id;
    uuid_t thread_id;
    int num_of_args;
    int context;
};

typedef struct create_team_channel_t {
    uuid_t uuid;
    uuid_t name;
    char description[MAX_DESCRIPTION_LENGTH];
} create_team_channel_t;

union arguments {
    struct arg_user_name_t arg_user_name;
    struct arg_uuid_t arg_uuid;
    struct arg_uuid_message_t arg_uuid_message;
    struct arg_use_t arg_use;
    create_team_channel_t create_team_channel;
};

enum commands {
    help_cmd,
    login_cmd,
    logout_cmd,
    users_cmd,
    user_cmd,
    send_cmd,
    messages_cmd,
    subscribe_cmd,
    subscribed_cmd,
    unsubscribe_cmd,
    use_cmd,
    create_team_cmd,
    create_channel_cmd,
    create_thread_cmd,
    create_reply_cmd,
    list_teams_cmd,
    list_channels_cmd,
    list_threads_cmd,
    list_replies_cmd,
    info_user_cmd,
    info_team_cmd,
    info_channel_cmd,
    info_thread_cmd,
    create_cmd,
    list_cmd,
    info_cmd,
    error_command
};

typedef struct request_t {
    enum commands command;
    union arguments args;
} request_t;

// response from server to client
enum code {
    server_message,

    login,
    logout,

    create_team,
    create_team_event,
    create_channel,
    create_channel_event,
    create_thread,
    create_thread_event,

    receive_reply,
    receive_message,

    print_user,
    print_team,
    print_channel,
    print_thread,

    print_users,
    print_teams,
    print_team_channels,
    print_channel_threads,
    print_thread_replies,
    print_private_messages,

    subscribed,
    unsubscribed,

    error_unknown_team,
    error_unknown_channel,
    error_unknown_thread,
    error_unknown_user,
    error_unauthorized,
    error_already_exist,

    change_context
};

struct error_unknown_team_channel_thread_user_t {
    uuid_t uuid;
};

struct login_logout_t {
    uuid_t user_uuid;
    char user_name[MAX_NAME_LENGTH];
};

struct receive_message_t {
    uuid_t user_uuid;
    char message_body[MAX_BODY_LENGTH];
};

struct receive_reply_t {
    uuid_t team_uuid;
    uuid_t thread_uuid;
    uuid_t user_uuid;
    char reply_body[MAX_BODY_LENGTH];
};

struct print_subscribed_unsubscribed_t {
    uuid_t user_uuid;
    uuid_t team_uuid;
};

typedef struct create_thread_t {
    uuid_t thread_uuid;
    uuid_t user_uuid;
    time_t thread_timestamp;
    char *thread_title[20];
    char *thread_body[20];
    char description[20];
} create_thread_t;

typedef struct print_message_t {
    uuid_t sender_uuid;
    time_t message_timestamp;
    char message_body[MAX_BODY_LENGTH];
} print_message_t;

struct print_all_messages_t {
    print_message_t messages[MAX_MESSAGES];
    size_t size_array;
};

typedef struct print_user_t {
    uuid_t user_uuid;
    char user_name[20];
    int user_status;
} print_user_t;

struct print_all_users_t {
    print_user_t users[MAX_USERS];
    size_t size_array;
};

typedef struct print_team_channel_t {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} print_team_channel_t;

struct print_all_teams_channels_t {
    print_team_channel_t list[MAX_TEAMS];
    size_t size_array;
};

typedef struct print_reply_t {
    uuid_t thread_uuid;
    uuid_t user_uuid;
    time_t reply_timestamp;
    char reply_body[MAX_BODY_LENGTH];
}print_reply_t;

struct print_all_replies_t {
    print_reply_t replies[200];
    size_t size_array;
};

typedef struct print_thread_t {
    uuid_t thread_uuid;
    uuid_t user_uuid;
    time_t thread_timestamp;
    char thread_title[20];
    char thread_body[20];
}print_thread_t;

struct print_all_threads_t {
    print_thread_t threads[MAX_THREADS];
    size_t size_array;
};

struct server_message_t {
    char message[BUFFER_MAX];
    int context;
};

struct use_response_t {
    int new_context;
};

union response_args_t {
    struct login_logout_t login_logout;
    struct receive_message_t receive_message;
    struct receive_reply_t receive_reply;
    struct create_team_channel_t create_team_channel;
    struct create_thread_t create_thread;
    struct print_user_t print_user;
    struct print_message_t print_message;
    struct print_team_channel_t print_team_channel;
    struct print_thread_t print_thread;
    struct print_reply_t print_reply;
    struct print_subscribed_unsubscribed_t print_sub;
    struct server_message_t server_message;
    struct error_unknown_team_channel_thread_user_t error_unknown;
    struct print_all_users_t print_all_users;
    struct print_all_teams_channels_t print_all_teams_channels;
    struct print_all_threads_t print_all_threads;
    struct print_all_replies_t print_all_replies;
    struct print_all_messages_t print_all_messages;
    struct use_response_t use_response;
};

typedef struct response_t {
    enum code code;
    union response_args_t args;
} response_t;
