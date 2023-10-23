##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
## File description:
## Makefile
##

all:
	@make -C nibbler/ --no-print-directory
	@make -C snake/ --no-print-directory
	@make -C menu/ --no-print-directory

clean:
	@make clean -C nibbler/ --no-print-directory
	@make clean -C snake/ --no-print-directory
	@make clean -C menu/ --no-print-directory

fclean:	clean
	@make fclean -C nibbler/ --no-print-directory
	@make fclean -C snake/ --no-print-directory
	@make fclean -C menu/ --no-print-directory

re: fclean all

.PHONY: all clean fclean re
