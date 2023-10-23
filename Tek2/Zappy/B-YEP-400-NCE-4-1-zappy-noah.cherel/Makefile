##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## for zappy
##


################################################################################
#                                    CONFIG                                    #
################################################################################

PROJECT = ⚡Zappy ⚡

AUTHOR = Noah CHEREL - Nathan TRANCHANT - Marc-Oliver KOBAN - Alexis DELHAYE - \
Hugo GRISEL

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	DATE	:= $(shell git log -1 --date=format:"%d/%m/%Y %T" 			\
				--format="%ad")
endif

################################################################################
# 								    COLORS                                     #
################################################################################

DEFAULT = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[0;36m
BOLD = \033[1m

SERVER_FLAGS = -I./include -Wall -Wextra -Werror -lpthread -lm
SERVER_SRC = $(wildcard server/src/*.c)
SERVER_NAME = zappy_server

GUI_FLAGS = -I./include -Wall -Wextra -Wno-unused-function -Werror
GUI_FLAGS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
GUI_SRC = $(wildcard gui/src/*.cpp)
GUI_NAME = zappy_gui

AI_SRC = $(wildcard ai/main.py)
AI_NAME = zappy_ai

.PHONY: all build_zappy_server build_zappy_gui build_zappy_ai clean fclean re

all:
	@printf "Author\t:\t$(BLUE)$(BOLD)$(AUTHOR)$(DEFAULT)\n"
	@printf "Date\t:\t$(BLUE)$(BOLD)$(DATE)$(DEFAULT)\n"
	@printf "Compilation of $(YELLOW)$(BOLD)$(PROJECT)$(DEFAULT)...\n\n"
	@$(MAKE) -s build_zappy_server
	@printf "Compilation of $(SERVER_NAME) \
		$(GREEN)$(BOLD)done$(DEFAULT)\n"
	@$(MAKE) -s build_zappy_gui
	@printf "Compilation of $(GUI_NAME) \
		$(GREEN)$(BOLD)done$(DEFAULT)\n"
	@$(MAKE) -s build_zappy_ai
	@printf "Compilation of $(AI_NAME) \
		$(GREEN)$(BOLD)done$(DEFAULT)\n"
	@printf "\nCompilation of $(YELLOW)$(BOLD)$(PROJECT)$(DEFAULT) \
		$(GREEN)$(BOLD)done$(DEFAULT)\n"

build_zappy_server: $(SERVER_NAME)
build_zappy_gui: $(GUI_NAME)
build_zappy_ai: $(AI_NAME)

$(SERVER_NAME):
	gcc -o $(SERVER_NAME) $(SERVER_SRC) $(SERVER_FLAGS)

$(GUI_NAME):
	g++ -o $(GUI_NAME) $(GUI_SRC) $(GUI_FLAGS)

$(AI_NAME):
	cp $(AI_SRC) $(AI_NAME)
	chmod +x $(AI_NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER_NAME) $(GUI_NAME) $(AI_NAME)

linked:
	rm -f $(SERVER_NAME) $(GUI_NAME) $(AI_NAME)
	g++ -o $(GUI_NAME) -L/usr/local/lib $(GUI_SRC) $(GUI_FLAGS)

re: fclean all
