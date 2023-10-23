##
## EPITECH PROJECT, 2023
## piscine
## File description:
## Makefile
##

C_FILES=*.c

PROJECT_BIN=libstring.a

################################################################################

$(PROJECT_BIN): $(C_FILES)
	gcc -c *.c
	ar rc $(PROJECT_BIN) *.o

all: $(PROJECT_BIN)

clean:
	rm -f $(PROJECT_BIN)
	rm -f z.o
	rm -f *.hi *.o
.PHONY: clean

fclean: clean
	rm -f $(PROJECT_BIN)
.PHONY: fclean

re: fclean all
