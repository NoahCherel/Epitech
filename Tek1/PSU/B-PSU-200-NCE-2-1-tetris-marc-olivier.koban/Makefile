##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC	=	sources/tetris.c					\
		sources/my_lib.c					\
		sources/my_lib2.c					\
		sources/my_lib3.c					\
		sources/my_lib4.c					\
		sources/debug.c						\
		sources/open_tetrimino.c			\
		sources/open_tetrimino_bis.c		\
		sources/open_tetrimino_utils.c	\
		sources/open_tetrimino_utils2.c	\
		sources/opt.c						\
		sources/getopt.c					\
		sources/menu.c						\
		sources/utils1.c					\
		sources/utils2.c					\
		sources/utils3.c					\
		sources/print_default.c				\
		sources/deplacement.c				\

OBJ =	$(SRC:.c=.o)

NAME	=	tetris

FLAGS = -lncurses -g

all:	$(NAME)

$(NAME):	$(SRC)
			gcc -o $(NAME) $(SRC) -I include/ $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
