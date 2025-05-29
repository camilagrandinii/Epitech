##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make re clean fclean
##

NAME = plazza

CXX = g++

CPPFLAGS += -I./includes

CFLAGS += -Wall -Wextra -std=c++23

LDFLAGS += -pthread

SRCS	= 	src/Main.cpp				\
			src/Plazza/Order.cpp		\
			src/Plazza/Kitchen.cpp		\
			src/Plazza/APizza.cpp		\
			src/Plazza/ParseInput.cpp	\
			src/Plazza/Reception.cpp	\
			src/ParsingConfFile.cpp		\
			src/QuadrUplet.cpp			\
			src/ArgsHandling.cpp

OBJS =	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean