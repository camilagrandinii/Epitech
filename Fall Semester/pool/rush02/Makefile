CC = gcc
CFLAGS = -std=gnu17 -Wall -Wextra
INCLUDES = -I.
LFLAGS = -L.
LIBS = -lm
SRCS = new.c ex05.c player.c point.c vertex.c int.c float.c char.c array.c
OBJS = $(SRCS:.c=.o)
MAIN = my_program

.PHONY: clean fclean re all

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(MAIN)

re: fclean all

