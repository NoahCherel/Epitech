##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	sources/sokoban.c	\
		sources/my_lib.c	\
		sources/movement.c	\
		sources/lib2.c	\

NAME	=	my_sokoban

FLAGS = -lncurses

all:	$(NAME)

$(NAME):	$(SRC)
		gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f *.o*
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
