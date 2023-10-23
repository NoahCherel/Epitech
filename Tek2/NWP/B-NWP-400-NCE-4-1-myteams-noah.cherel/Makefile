##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

SERVER	=	server/
CLIENT 	=	client/

SERVER_NAME	=	myteams_server
CLIENT_NAME	=	myteams_cli

all: server client

server:
	@make -C server

client:
	@make -C client

clean:
	@make clean -C server
	@make clean -C client

fclean:
	@make fclean -C server
	@make fclean -C client
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)


re: fclean all

.PHONY: all server client clean fclean re
