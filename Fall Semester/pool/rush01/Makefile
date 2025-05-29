##
## EPITECH RUSH 01, 2024
## Camila Lacerda Grandini & Marianne Titova
## File description:
## Makefile
##

CFLAGS = -Wall -Wextra -Wpedantic -g3 -I./include -lm

NCURSES = -lncurses

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

SRC = ./Main.hs

NAME = pushswap_checker

all: $(NAME)

$(NAME):
	@ghc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.hi *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean