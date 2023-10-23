##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	solver.c	\
		my_lib.c	\
		
FLAGS = 

OBJ =	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all