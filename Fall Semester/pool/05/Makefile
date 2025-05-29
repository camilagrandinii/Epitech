CC = gcc
CFLAGS = -std=gnu17 -Wall -Wextra
INCLUDES = -I.
LFLAGS = -L.
LIBS = -lm
SRCS = string.c
OBJS = $(SRCS:.c=.o)
LIBRARY = libstring.a
MAIN = a.out

.PHONY: clean fclean re all

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(LIBRARY)

re: fclean all
