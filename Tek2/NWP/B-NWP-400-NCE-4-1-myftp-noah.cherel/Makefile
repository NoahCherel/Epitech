##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME    =    myftp
CC    	=    gcc
SRC    	=   src/main.c \
			src/ftp_commands.c \
			src/ftp_commands1.c \
			src/ftp_commands2.c \
			src/ftp_server.c \
			src/ftp_client.c \
			src/management.c \
			src/pasv.c \
			src/retr.c \

OBJ    	=    $(SRC:.c=.o)

all :    $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o :    %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

.PHONY: all clean fclean re
