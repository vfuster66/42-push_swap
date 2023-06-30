# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

# Program names
NAME = push_swap
NAME_BONUS = checker

# Library
LIB_PATH = ./libft
LIB_NAME = libft.a
LIB_INC = -I$(LIB_PATH)
LIB_LINK = -L$(LIB_PATH) -lft

# Sources
SRC_MAIN = ./src/main.c \

DIR_SRC = ./parsing/
SRC_FILES = parsing.c initialize_and_free.c \

DIR_SORT = ./sort/
SORT_FILES = large_sort.c medium_small_sort.c \
             minimum_median.c maximum_median.c \

DIR_UTILS = ./utils/
UTILS_FILES = utils_1.c utils_2.c utils_sort.c \

DIR_INSTRUCTION = ./instructions/
INSTRUCTION_FILES = instructions.c push_and_swap.c \
                    rotate.c reverse_rotate.c \

SRC_WITHOUT_MAIN = $(addprefix $(DIR_SRC), $(SRC_FILES)) \
                   $(addprefix $(DIR_UTILS), $(UTILS_FILES)) \
                   $(addprefix $(DIR_SORT), $(SORT_FILES)) \
                   $(addprefix $(DIR_INSTRUCTION), $(INSTRUCTION_FILES))

SRC = $(SRC_MAIN) \
      $(SRC_WITHOUT_MAIN)

DIR_BONUS = ./bonus/
BONUS_FILES = checker.c checks.c

SRC_BONUS = $(addprefix $(DIR_BONUS), $(BONUS_FILES)) \
            $(SRC_WITHOUT_MAIN)

# Objects
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# Rules
%.o: %.c
	@$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

all: compile

compile: $(OBJS)
	@if ! [ -f $(NAME) ] || [ "$(OBJS)" -nt "$(NAME)" ]; then \
		make -s -C $(LIB_PATH); \
		echo "✅ Libft compiled\n"; \
		$(CC) $(CFLAGS) $(OBJS) $(LIB_INC) $(LIB_LINK) -o $(NAME); \
		echo "✅ Push_Swap compiled\n"; \
		echo "$$ASCII_MANDATORY"; \
	fi

bonus: $(OBJS_BONUS)
	@if ! [ -f $(NAME_BONUS) ] || [ "$(OBJS_BONUS)" -nt "$(NAME_BONUS)" ]; then \
		make -s -C $(LIB_PATH); \
		echo "✅ Libft compiled\n"; \
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB_INC) $(LIB_LINK) -o $(NAME_BONUS); \
		echo "✅ Checker compiled\n"; \
		echo "$$ASCII_BONUS"; \
	fi

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -s -C $(LIB_PATH) clean
	@echo "✅ Libft cleaned\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -s -C $(LIB_PATH) fclean
	@echo "✅ Push_Swap cleaned\n"

re: fclean all

# Colors
RED = \033[0;31m
NO_COLOR = \033[0m
YELLOW = \033[1;33m
GREEN = \033[0;32m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Ascii
info: ascii

define ASCII_MANDATORY

$(NO_COLOR)
$(YELLOW)██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████  $(YELLOW)
$(YELLOW)██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██ $(YELLOW)
$(YELLOW)██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████  $(YELLOW)
$(YELLOW)██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██      $(YELLOW)
$(YELLOW)██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██      $(YELLOW)


$(RED)                                ██████████                         $(RED)
$(RED)                          ██████░░      ░░██████                   $(RED)
$(RED)                        ████                  ████                 $(RED)
$(RED)                    ▒▒██                          ██               $(RED)
$(RED)                    ██                              ██             $(RED)
$(RED)                  ██░░                              ████           $(RED)
$(RED)                  ██  ▓▓                          ▒▒  ██           $(RED)
$(RED)                  ██  ██                          ██  ██           $(RED)
$(RED)                  ██  ██                          ██  ██           $(RED)
$(RED)                  ██  ██                          ██▒▒██           $(RED)
$(RED)                  ▒▒████  ░░██████      ████████  ████             $(RED)
$(RED)                    ████  ████████      ████████  ██░░             $(RED)
$(RED)          ░░██░░      ██  ████████      ████████  ██      ░░██▓▓   $(RED)
$(RED)          ██▓▓██      ██  ░░████          ██████  ██      ██░░██   $(RED)
$(RED)          ██  ██▒▒    ██    ░░    ██░░██    ▒▒    ██    ████  ██   $(RED)
$(RED)        ██▒▒    ██████████        ██░░██        ████████        ██ $(RED)
$(RED)        ██▓▓████      ▒▒██████    ██  ██    ██████▒▒    ▒▒████████ $(RED)
$(RED)                ██████    ██▒▒██          ██▓▓██    ██████         $(RED)
$(RED)                      ██████████▓▓██▓▓██▓▓██████████               $(RED)
$(RED)                          ██░░██▒▒▒▒▒▒▓▓▒▒██████                   $(RED)
$(RED)                      ▒▒████  ██░░▒▒▒▒▓▓░░██  ██████               $(RED)
$(RED)            ██████████▒▒  ░░██              ░░██    ██████████     $(RED)
$(RED)          ░░██          ██████▒▒          ▒▒██████          ████   $(RED)
$(RED)            ████    ████▒▒    ██████▓▓██████    ████▒▒    ████     $(RED)
$(RED)              ██  ██▒▒                              ████  ██       $(RED)
$(RED)              ██████                                  ██████       $(RED)


$(NO_COLOR)

endef
export ASCII_MANDATORY

define ASCII_BONUS

$(NO_COLOR)
$(GREEN) ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ $(GREEN)
$(GREEN)██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗$(GREEN)
$(GREEN)██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝$(GREEN)
$(GREEN)██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗$(GREEN)
$(GREEN)╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║$(GREEN)
$(GREEN) ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝$(GREEN)
$(NO_COLOR)

	   $(NO_COLOR)
	   $(WHITE)　　██░▀██████████████▀░██	$(WHITE)
	   $(WHITE)　　█▌▒▒░████████████░▒▒▐█	$(WHITE)
	   $(WHITE)　　█░▒▒▒░██████████░▒▒▒░█	$(WHITE)
	   $(WHITE)　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐	$(WHITE)
	   $(WHITE)　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░	$(WHITE)
	   $(WHITE)　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██	$(WHITE)
	   $(WHITE)　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█	$(WHITE)
	   $(WHITE)　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌	$(WHITE)
	   $(WHITE)　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█	$(WHITE)
	   $(WHITE)　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒	$(WHITE)
	   $(WHITE)　　░░░░░░░░░░└┴┘░░░░░░░░░	$(WHITE)
	   $(WHITE)　　██▄▄░░░░░░░░░░░░░░▄▄██	$(WHITE)
	   $(WHITE)　　████████▒▒▒▒▒▒████████	$(WHITE)
	   $(WHITE)　　█▀░░███▒▒░░▒░░▒▀██████	$(WHITE)
	   $(WHITE)　　█▒░███▒▒╖░░╥░░╓▒▐█████	$(WHITE)
	   $(WHITE)　　█▒░▀▀▀░░║░░║░░║░░█████	$(WHITE)
	   $(WHITE)　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███	$(WHITE)
	   $(WHITE)　　██████████████████████	$(WHITE)
	   $(NO_COLOR)

endef
export ASCII_BONUS

.PHONY: all clean fclean re bonus
