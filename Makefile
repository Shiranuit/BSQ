##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

NAME	=	bsq
SRC	=	*.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -I./include -o $(NAME) -g3

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all
