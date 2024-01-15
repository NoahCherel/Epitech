BINARY_PATH 	:=	$(shell stack path --local-install-root)
NAME 			= 	glados_compiler

all		:
			stack build
			cp $(BINARY_PATH)/bin/$(NAME)-exe ../$(NAME)

clean	:
			stack clean

fclean	:	clean
			rm -f $(NAME)
			rm -f app/Main

re		:	fclean all

test	:
			stack test

.PHONY	:	all clean fclean re test
