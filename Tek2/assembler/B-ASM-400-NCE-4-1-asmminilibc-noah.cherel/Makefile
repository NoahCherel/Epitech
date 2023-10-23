##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME    =    libasm.so
ASM   	=    nasm
ASFLAGS	=    -f elf64
CC    	=    gcc
CFLAGS	=    -nostdlib -shared -fPIC
SRC    	=    $(wildcard src/*.asm)
OBJ    	=    $(SRC:.asm=.o)

all :    $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o :    %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

.PHONY: all clean fclean re
