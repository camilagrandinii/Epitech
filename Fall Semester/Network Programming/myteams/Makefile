##
## EPITECH PROJECT, 2024
## Network Programming
## File description:
## Makefile to compile, clean and recompile source files
##

CC = gcc
SERVER_TARGET = myteams_server
CLIENT_TARGET = myteams_cli
LIBRARY_PATH = -Llibs/myteams

SERVER_SRC = src/server/channels_operations_initializer.c \
	src/server/commands_processing.c \
	src/server/file_descriptor_dealer.c \
    src/server/server_answers.c \
    src/server/server_initilizer.c \
    src/server/server_sender.c \
	src/server/server.c \
	src/server/teams_initial_handler.c \
	src/server/thread_operations_initializer.c \
	src/server/serialize_response.c \
	src/server/server_answers.c \
	src/server/commands/channels_operations.c \
	src/server/commands/general_commands.c \
    src/server/commands/login.c \
	src/server/commands/teams_operations_initial.c \
	src/server/commands/teams_operations.c \
	src/server/commands/threads_operations.c \
	src/server/commands/user_operations.c \
	src/server/utils/teams_operations_utils.c \
	src/server/utils/threads_operations_utils.c \
	src/server/utils/prepare_responses.c \
	src/server/utils/user_operations_utils.c

CLIENT_SRC = src/client/client.c \
	src/client/command_mapping.c \
	src/client/process_answers.c \
	src/client/process_message.c \
	src/client/response_code_mappings.c \
	src/client/deserialize_response.c \
	src/client/response_print.c

SERVER_OBJ = $(patsubst server/%.c, tmp/%.o, $(SERVER_SRC))
CLIENT_OBJ = $(patsubst client/%.c, tmp/%.o, $(CLIENT_SRC))

.PHONY: all clean fclean re
all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(SERVER_TARGET): $(SERVER_OBJ)
	$(CC) -o $@ $^ $(LIBRARY_PATH) -lmyteams -luuid -Wall -Wextra

$(CLIENT_TARGET): $(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LIBRARY_PATH) -lmyteams -luuid -Wall -Wextra

tmp/%.o: server/%.c
	@mkdir -p tmp
	$(CC) -c -o $@ $<

tmp/%.o: client/%.c
	@mkdir -p tmp
	$(CC) -c -o $@ $<

clean:
	rm -f server/*.o
	rm -f client/*.o
	rm -rf tmp/*

fclean: clean
	rm -f $(SERVER_TARGET) $(CLIENT_TARGET)

re: fclean all
