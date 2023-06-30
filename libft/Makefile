NAME := libft.a
CC := gcc
FLAGS := -Wall -Wextra -Werror

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS := ft_strjoin.c \
	ft_isalnum.c \
	ft_lstiter.c \
	ft_itoa.c \
	ft_strlcpy.c \
	ft_print_str.c \
	ft_print_utoa.c \
	ft_isprint.c \
	ft_lstadd_front.c \
	ft_print_uint.c \
	ft_strmapi.c \
	ft_print_itoa.c \
	ft_isascii.c \
	ft_print_char.c \
	ft_printf.c \
	ft_strnstr.c \
	ft_isalpha.c \
	ft_strrchr.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_memchr.c \
	ft_print_ptr.c \
	ft_strchr.c \
	ft_calloc.c \
	ft_memmove.c \
	ft_substr.c \
	ft_lstdelone.c \
	ft_memcpy.c \
	ft_print_int.c \
	ft_lstmap.c \
	ft_print_hexa.c \
	ft_putchar_fd.c \
	ft_strtrim.c \
	ft_lstsize.c \
	get_next_line.c \
	ft_bzero.c \
	get_next_line_utils.c \
	ft_lstlast.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlcat.c \
	ft_lstclear.c \
	ft_striteri.c \
	ft_memcmp.c \
	ft_putendl_fd.c \
	ft_lstnew.c \
	ft_lstadd_back.c \
	ft_width.c \
	ft_strdup.c \
	ft_atoi.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_flags.c \
	ft_flags_utils.c \
	ft_putnbr_fd.c \
	ft_print_xtoa.c \
	ft_iswhitespace.c \
	ft_strtol.c \
	ft_strcmp.c \
	ft_realloc.c \
	ft_strcpy.c \
	ft_strtok.c \

OBJS := $(SRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV := \033[0m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
CYAN := \033[1;36m
RM := rm -f

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
