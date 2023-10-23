##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for rush3
##

NAME    = MyGKrellm

CC    = g++

RM    = rm -f

SRC	= 	MyGKrellm.cpp \
		GraphicMode/Graphicmain.cpp \
		TextMode/Textmain.cpp \
		Corefiles/MonitorCore.cpp \

all: fclean $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRC) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
