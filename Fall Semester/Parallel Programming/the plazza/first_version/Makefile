##
## EPITECH PROJECT, 2024
## CCP
## File description:
## Plazza
##

NAME = plazza

CXX = g++

CPPFLAGS += -g3 -I./includes -I./libs/includes

CFLAGS += -g3 -W -Wall -Wextra -std=c++20# -Werror 

LDFLAGS += -fopenmp

TESTFLAGS += -lcriterion

SRCS	= 	src/main.cpp						\
			src/Plazza/Reception.cpp 			\
			src/Plazza/ProcessKitchen.cpp 		\
			src/Plazza/Pizza.cpp 				\
			src/Plazza/Kitchen.cpp 				\
			src/Plazza/ProcessKitchen.cpp		\
			src/Plazza/Cook.cpp 				\
			src/Plazza/Parsing/Parser.cpp		\
			src/Plazza/Orders/Order.cpp			\
			src/Plazza/Orders/PizzaOrder.cpp	\
			src/Plazza/Status.cpp

LIBS	=	libs/src/EventsLogging.cpp	\
			libs/src/Delta.cpp			\
			libs/src/ICP.cpp			\
			libs/src/IngredientControl.cpp	\
			libs/src/Misc.cpp			\
			libs/src/Mutex.cpp			\
			libs/src/Semaphore.cpp

OBJS =	$(SRCS:.cpp=.o)
LIBSOBJS =	$(LIBS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBSOBJS)
	$(CXX) -g3 -o $(NAME) $(OBJS) $(LIBSOBJS) $(LDFLAGS) $(TESTFLAGS)

clean:
	$(RM) $(OBJS) $(LIBSOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
