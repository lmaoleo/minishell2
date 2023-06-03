##
## EPITECH PROJECT, 2023
## B-PSU-200-TLS-2-1-minishell1-leo.maurel
## File description:
## Makefile
##

RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[0;37m
BLUE = \033[1;34m
GOLD = \033[1;33m
BEGINL = \033[A
CLEARL = \033[2K
COL_END  = \033[0m
CLEAR_COL = \033[2K\033[A

NAME = mysh

SRC =	mysh.c \
		get_input.c \
		builtins.c \
		env_base.c \
		env_utils.c \
		env_command.c \
		execute_bin.c \
		utils/my_str_to_word_array.c \
		utils/my_putchar.c \
		utils/my_putstr.c \
		utils/my_strlen.c \
		utils/my_strcmp.c \
		utils/my_strdup.c \
		utils/my_strcpy.c \
		utils/my_strcat.c \
		utils/my_strclean.c \

SRC := $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -I./include -Wpedantic

MAKE = make --no-print-directory

FILE = $(shell echo $(SRC) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find src/ -type f -name '*.o' | wc -l | sed -e 's/ //g')
CURRENT_FILE = $(shell echo '$$(( $(CURRENT_FILES) + 1 ))')

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -en "$(CLEARL)$(BLUE)[$(GOLD)building$(BLUE)]$(WHITE) "
	@echo -en "$(BLUE)$(notdir $@) "
	@echo -e "$(GREEN)($(CURRENT_FILE)/$(FILE))$(WHITE)$(BEGINL)"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(CLEARL)$(BLUE)[$(GREEN)Build$(BLUE)] $(GOLD)$(NAME)$(COL_END)"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "$(BLUE)[$(GOLD)Cleaner$(BLUE)] $(RED)clean success"

fclean: clean
	@rm -f $(NAME)

rclean: all clean

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re
