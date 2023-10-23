##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for lem-in project
##

NAME	=	lem_in

SRC 	=	src/main.c	\
		src/parser.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-O2 -g3 -Wall -Wextra

LIB	=	-L./ -lmy

RM	=	rm -rf

CC	=	cc

$(NAME)	:	$(OBJ)
	cd lib/ && make
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

all	:	$(NAME)

clean	:
	$(RM) $(OBJ) *~ *# vgcore*
	cd lib/ && make clean

fclean	:	clean
	$(RM) $(NAME)
	cd lib/ && make fclean

re	:	fclean all

.PHONY	:	all clean fclean re
