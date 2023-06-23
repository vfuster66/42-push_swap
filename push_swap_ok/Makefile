# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:34:32 by vfuster-          #+#    #+#              #
#    Updated: 2023/06/22 16:23:53 by vfuster-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP_SRCS = push_swap.c
HEADERS = push_swap.h

CC = gcc -g
CC_FLAGS = -lm -Wall -Werror -Wextra

.PHONY: all libft clean fclean re

# Les cibles all, libft, push_swap et checker dépendent de leurs fichiers objets respectifs
all: libft push_swap
	@echo "✅ Push_swap compiled\n"

# Compiler la bibliothèque libft
libft:
	@make -s -C libft
	@echo "✅ Libft compiled\n"

# Compiler push_swap
push_swap: $(PUSHSWAP_SRCS:%.c=%.o) libft/libft.a
	@$(CC) $^ -o $@ $(CC_FLAGS) -Llibft -lft

# Les fichiers objets dépendent des fichiers sources et des en-têtes correspondantes
srcs/%.o: srcs/%.c ${HEADERS}
	@$(CC) -c $< -o $@ $(CC_FLAGS)

# Compiler chaque fichier source individuellement en fichier objet
%.o: %.c ${HEADERS}
	@$(CC) -c $< -o $@ $(CC_FLAGS)

clean:
	@rm -rf $(PUSHSWAP_SRCS:%.c=%.o)
	@make -s clean -C libft
	@echo "✅ Push_swap cleaned\n"

fclean: clean
	@rm -rf push_swap
	@make -s fclean -C libft
	@echo "✅ Libft cleaned\n"

re: fclean all
	@echo "✅ Push_swap recompiled\n"

