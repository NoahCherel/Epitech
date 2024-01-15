BINARY_PATH 	:=	$(shell stack path --local-install-root)
NAMES 			= 	glados glados_vm glados_compiler

all: compiler vm interpreter

compiler:
	echo "Building compiler..."
	make -C compiler/

vm:
	echo "Building VM..."
	make -C vm/

interpreter:
	echo "Building interpreter..."
	make -C interpreter/

clean	:
			stack clean

fclean	:	clean
			rm -f $(NAMES)
			rm -f app/Main

re		:	fclean all

test	:
			make -C compiler/ test
			make -C vm/ test
			make -C interpreter/ test


.PHONY	:	all compiler vm interpreter clean fclean re test
