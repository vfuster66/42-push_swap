# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# Nom du programme
NAME = push_swap

# Bibliothèques
LIB_PATH = ./libft
LIB_NAME = libft.a
LIB_INC = -I$(LIB_PATH)
LIB_LINK = -L$(LIB_PATH) -lft

# Sources
SRCS = src/main.c src/utils_1.c src/utils_2.c src/utils_sort.c \
		src/push_and_swap.c src/rotate.c src/reverse_rotate.c \
		src/instructions_and_parsing.c src/minimum_median.c \
		src/maximum_median.c src/medium_small_sort.c src/large_sort.c \

# Objets
OBJS = $(SRCS:.c=.o)

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
		else \
				echo "✅ All is up-to-date"; \
		fi

clean:
		@$(RM) $(OBJS)
		@make -s -C $(LIB_PATH) clean
		@echo "✅ Libft Cleaned\n"

fclean: clean
		@$(RM) $(NAME)
		@make -s -C $(LIB_PATH) fclean
		@echo "✅ Push_Swap Cleaned\n"

re: fclean all

# Colors
RED = \033[0;31m
NO_COLOR = \033[0m
YELLOW = \033[1;33m

# Ascii
info: ascii

define ASCII_MANDATORY

$(NO_COLOR)
$(YELLOW)██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████  $(YELLOW)
$(YELLOW)██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██ $(YELLOW)
$(YELLOW)██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████  $(YELLOW)
$(YELLOW)██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██      $(YELLOW)
$(YELLOW)██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██      $(YELLOW)


$(RED)                                  ██████████                         $(RED)
$(RED)                            ██████░░      ░░██████                   $(RED)
$(RED)                          ████                  ████                 $(RED)
$(RED)                      ▒▒██                          ██               $(RED)
$(RED)                      ██                              ██             $(RED)
$(RED)                    ██░░                              ████           $(RED)
$(RED)                    ██  ▓▓                          ▒▒  ██           $(RED)
$(RED)                    ██  ██                          ██  ██           $(RED)
$(RED)                    ██  ██                          ██  ██           $(RED)
$(RED)                    ██  ██                          ██▒▒██           $(RED)
$(RED)                    ▒▒████  ░░██████      ████████  ████             $(RED)
$(RED)                      ████  ████████      ████████  ██░░             $(RED)
$(RED)            ░░██░░      ██  ████████      ████████  ██      ░░██▓▓   $(RED)
$(RED)            ██▓▓██      ██  ░░████          ██████  ██      ██░░██   $(RED)
$(RED)            ██  ██▒▒    ██    ░░    ██░░██    ▒▒    ██    ████  ██   $(RED)
$(RED)          ██▒▒    ██████████        ██░░██        ████████        ██ $(RED)
$(RED)          ██▓▓████      ▒▒██████    ██  ██    ██████▒▒    ▒▒████████ $(RED)
$(RED)                  ██████    ██▒▒██          ██▓▓██    ██████         $(RED)
$(RED)                        ██████████▓▓██▓▓██▓▓██████████               $(RED)
$(RED)                            ██░░██▒▒▒▒▒▒▓▓▒▒██████                   $(RED)
$(RED)                        ▒▒████  ██░░▒▒▒▒▓▓░░██  ██████               $(RED)
$(RED)              ██████████▒▒  ░░██              ░░██    ██████████     $(RED)
$(RED)            ░░██          ██████▒▒          ▒▒██████          ████   $(RED)
$(RED)              ████    ████▒▒    ██████▓▓██████    ████▒▒    ████     $(RED)
$(RED)                ██  ██▒▒                              ████  ██       $(RED)
$(RED)                ██████                                  ██████       $(RED)


$(NO_COLOR)

endef
export ASCII_MANDATORY

.PHONY: all clean fclean re bonus




