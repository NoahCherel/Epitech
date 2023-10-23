##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	sources/my_runner.c	\
		sources/my_lib.c	\
		sources/utils.c	\
		sources/utils2.c	\
		sources/utils3.c	\
		sources/parallax.c	\
		sources/character.c	\
		sources/gameobject.c	\
		sources/score.c	\
		sources/map.c	\

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ =	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all