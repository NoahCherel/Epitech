##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for need4stek
##

SRC	=	src/main.c 					\
		src/detect_end.c			\
		src/exec_cmd.c				\
		src/direction.c				\
		src/get_next_line.c			\
		src/utils.c					\

NAME	=	ai

OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(SRC)
		gcc -o $(NAME) $(SRC) -I include/

clean:
		rm -rf $(NAME)
		rm -rf *.o
		rm -rf *.gcda
		rm -rf *.gcno

fclean:		clean

re:
	make fclean
	make
