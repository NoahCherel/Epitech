##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	sources/my_hunter.c	\
		sources/my_lib.c	\
		sources/my_second_lib.c	\
		sources/utils.c	\
		sources/fill_struct.c	\

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ =	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all 