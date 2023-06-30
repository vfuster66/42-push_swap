/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:56:20 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 10:42:04 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Structures
typedef struct s_node_instructions
{
	char						*parameters;
	int							instructions;
	struct s_node_instructions	*next;
}	t_node_instructions;

typedef struct s_list_instructions
{
	struct s_node_instructions	*all_instructions;
	int							instructions_number ;
}	t_list_instructions;

// checks.c

t_node_instructions	*create_node_instructions(char *parameters);
t_node_instructions	*free_node_instructions(t_node_instructions **head);
t_list_instructions	*create_list_instructions(t_node_instructions *head);
t_list_instructions	*free_list_instructions(t_list_instructions **head);
int					read_parameters(t_node_instructions *node);

// checker.c
t_list_instructions	*parsing_instructions(void);
int					read_instructions(t_list_instructions *all_instruction);
void		perform_instructions(t_node_instructions *instructions, t_stack *stacks);
char		*get_instructions(int instructions_index);

// utils
int			is_sorted(t_stack *stacks);
void		execute_instructions(int display, t_stack *stacks,
int instruction_number, ...);
int			initialize_structure(t_stack **stacks, int ac, char **av);
void		*free_stack(t_stack **stack);

#endif
