##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
## File description:
## Makefile
##

all:
	@make -C plane/ --no-print-directory
	@make -C sphere/ --no-print-directory

clean:
	@make clean -C plane/ --no-print-directory
	@make clean -C sphere/ --no-print-directory

fclean:	clean
	@make fclean -C plane/ --no-print-directory
	@make fclean -C sphere/ --no-print-directory

re: fclean all

.PHONY: all clean fclean re
