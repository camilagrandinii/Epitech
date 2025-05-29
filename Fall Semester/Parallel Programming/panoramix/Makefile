##
## EPITECH PROJECT, 2024
## Concurrent Programming
## File description:
## Makefile to compile, clean and recompile source files
##
CC = gcc
LDLIBS = -Wall -Wextra
TARGET = panoramix
SRC = src/druid/druid_ops.c \
	  src/druid/druid_thread.c \
      src/panoramix.c \
	  src/pot/pot_ops.c \
	  src/villagers/villager_ops.c \
	  src/villagers/villager_threads.c
SRCDIRS := $(sort $(dir $(SRC)))
OBJDIR := tmp
OBJ := $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRC))
.PHONY: all clean fclean re
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(LDLIBS) -o $@ $^
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $<
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(TARGET)
re: fclean all
