##
## EPITECH PROJECT, 2024
## IOStream, String and objects
## File description:
## Makefile to compile, clean and recompile source files
##
CPLUS = g++
CPLUSFLAGS = -std=c++20 -Wall -Wextra -Werror
INCLUDES = -I.
LFLAGS = -L.
LIBS = -lm
SRCS = Assistant.cpp Student.cpp Dean.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = Main

.PHONY: clean fclean re all

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CPLUS) $(CPLUSFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CPLUS) $(CPLUSFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(MAIN)

re: fclean all
