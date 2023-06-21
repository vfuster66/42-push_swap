/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 07:32:41 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/21 16:32:33 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <ctype.h>

typedef struct	s_node {
	int	value;
	struct s_node	*next;
	int	index;
}				t_node;

typedef struct	s_stack {
	struct s_node	*top;
	int				size;
	int				value;
}				t_stack;

typedef struct	s_struct {
	int	min;
	int	max;
	int	mid;
}				t_struct;

struct s_stack		*initstack(void);
t_struct			*init_nbr(void);
int						isEmpty(struct s_stack *stack);
void				push(struct s_stack *stack, int content);
int						peek(struct s_stack *stack);
int						pop(struct s_stack *stack);
void				print_stack(struct s_stack *stack);
int						isInt(char *str);
int						is_sorted(t_stack *a);


void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *stack1, t_stack *stack2);
void				pb(t_stack *stack1, t_stack *stack2);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *a, t_stack *b);


void				sorting_2_elements(t_stack *a);
void				sorting_3_elements(t_stack *a);
void				push_min_to_b(t_stack *a, t_stack *b, int max_rotations, t_struct *nbr);
void				sorting_4_elements(t_stack *a, t_stack *b);
void				sorting_5_elements(t_stack *a, t_stack *b);

int						find_index(t_stack *a, int min);
int						find_min(t_stack *a);
int						find_max(t_stack *a);
void				find_mid(t_stack *a, t_struct *nbr);

int						check_nbr(t_stack *a);
void				check_value(t_stack *a, t_struct *nbr);

void sort_stack(t_stack *a, t_stack *b, t_struct *nbr);

void				push_swap(t_stack *a, t_stack *b);

#endif
