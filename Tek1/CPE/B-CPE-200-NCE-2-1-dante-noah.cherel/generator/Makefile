##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	generator.c	\
		maze.c		\
		my_lib.c	\

OBJ =	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all