##
## EPITECH PROJECT, 2024
## C, Life, the Universe and everything else
## File description:
## Makefile to compile, clean and recompile source files
##
CC = gcc
TARGET = z
SRC = z.c
OBJ = $(patsubst %.c,tmp/%.o,$(SRC))
.PHONY: all clean fclean re
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) -o $@ $^
tmp/%.o: %.c
	@mkdir -p tmp
	$(CC) -c -o $@ $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(TARGET)
re: fclean all
