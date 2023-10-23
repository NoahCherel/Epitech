##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
## File description:
## Makefile
##

all:
	@make -C ncurses/ --no-print-directory
	@make -C sdl2/ --no-print-directory
	@make -C sfml/ --no-print-directory

clean:
	@make clean -C ncurses/ --no-print-directory
	@make clean -C sdl2/ --no-print-directory
	@make clean -C sfml/ --no-print-directory

fclean:	clean
	@make fclean -C ncurses/ --no-print-directory
	@make fclean -C sdl2/ --no-print-directory
	@make fclean -C sfml/ --no-print-directory

re: fclean all

.PHONY: all clean fclean re
