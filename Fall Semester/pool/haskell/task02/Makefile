##
## EPITECH PROJECT, 2024
## Camila Lacerda Grandini
## File description:
## Makefile
##
SRC = ./DoOp.hs
NAME = doop
all: $(NAME)
$(NAME):
	@ghc $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -f *.hi *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all re clean fclean