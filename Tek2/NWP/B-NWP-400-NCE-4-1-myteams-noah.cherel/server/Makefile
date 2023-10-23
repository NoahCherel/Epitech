##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

CC = gcc
NAME	=	../myteams_server

SRC =	src/main.c \
		src/serv.c \
		src/login.c \
		src/save.c \
		src/serv_client.c \
		src/commands1.c \
		src/misc.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I./include -g3
LIB	=	-L../libs/myteams/ -luuid -lmyteams

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
