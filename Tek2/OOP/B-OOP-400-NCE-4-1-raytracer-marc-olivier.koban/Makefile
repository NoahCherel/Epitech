##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
## File description:
## Makefile
##

NAME = raytracer

$(NAME):
	@make -C core/ --no-print-directory
	@make -C primitives/ --no-print-directory
	@make -C lights/ --no-print-directory

all: $(NAME)

clean:
	@make clean -C core/ --no-print-directory
	@make clean -C primitives/ --no-print-directory
	@make clean -C lights/ --no-print-directory

fclean: clean
	@make fclean -C core/ --no-print-directory
	@make fclean -C primitives/ --no-print-directory
	@make fclean -C lights/ --no-print-directory

re: fclean all

.PHONY: all clean fclean re
