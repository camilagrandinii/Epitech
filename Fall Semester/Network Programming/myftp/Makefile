##
## EPITECH PROJECT, 2024
## Network Programming
## File description:
## Makefile to compile, clean and recompile source files
##
CC = gcc
TARGET = myftp
SRC = server/server.c \
    server/commands_processing.c \
    server/server_answers.c \
    server/login.c \
    server/commands_functionalities.c \
	server/server_initilizer.c \
	server/server_sender.c \
	server/file_descriptor_dealer.c \
	server/command_directories.c \
	server/file_transfers.c \
	server/command_port.c \
	server/command_pasv.c
OBJ = $(patsubst server/%.c, tmp/%.o, $(SRC))
.PHONY: all clean fclean re
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) -o $@ $^
tmp/%.o: server/%.c
	@mkdir -p tmp
	$(CC) -c -o $@ $<
clean:
	rm -f server/*.o
	rm -rf tmp/*
fclean: clean
	rm -f $(TARGET)
re: fclean all
