# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# Noms des programmes
NAME = push_swap
NAME_BONUS = checker

# Bibliothèques
LIB_PATH = ./libft
LIB_NAME = libft.a
LIB_INC = -I$(LIB_PATH)
LIB_LINK = -L$(LIB_PATH) -lft

# Sources
SRCS = src/main.c src/utils_1.c src/utils_2.c src/utils_sort.c \
		src/push_and_swap.c src/rotate.c src/reverse_rotate.c \
		src/instructions.c src/minimum_median.c src/parsing.c \
		src/maximum_median.c src/medium_small_sort.c src/large_sort.c

SRCS_BONUS = bonus/checker.c

# Objets
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Règles
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

.PHONY: all compile bonus clean fclean re


# Colors
RED = \033[0;31m
NO_COLOR = \033[0m
YELLOW = \033[1;33m
GREEN = \033[0;32m

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




endef
export ASCII_BONUS

.PHONY: all clean fclean re bonus




