/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:56:20 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:42:24 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//-_-_-_-_-_-_-_-_-_-_- Constantes
# define TRUE 1
# define FALSE 0
# define STACK_A 1
# define STACK_B 0
# define PA 0
# define PB 1
# define RRA 2
# define RRB 3
# define RRR 4
# define RA 5
# define RB 6
# define RR 7
# define SA 8
# define SB 9
# define SS 10

//-_-_-_-_-_-_-_-_-_-_- Structures
typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
	int				len_a;
	int				len_b;
	int				total_len;
}	t_stack;

// utils_1.c
t_node		*find_minimum(t_node *head);
t_node		*find_maximum(t_node *head);
t_node		*find_closest_node(t_node *list_a, t_node *node_b);
t_node		*create_node(int value, int position, t_node *previous);
void		get_index(t_node *previous, t_node *current);

// utils_2.c
void		iterate_nodes(t_node *node, int index, void (*f)(t_node *, int));
int			size_node(t_node *stack_a);
void		updated_position(int offset, t_node *stack);
t_node		*find_last_node(t_node *stack);
t_stack		*create_structure(t_node *stack_a);

// push_and_swap.c
void		pa(t_stack *stacks, int display);
void		pb(t_stack *stacks, int display);
void		sa(t_stack *stacks, int display);
void		sb(t_stack *stacks, int display);
void		ss(t_stack *stacks, int display);

// rotate.c
void		ra(t_stack *stacks, int display);
void		rb(t_stack *stacks, int display);
void		rr(t_stack *stacks, int display);

// reverse_rotate.c
void		rra(t_stack *stacks, int display);
void		rrb(t_stack *stacks, int display);
void		rrr(t_stack *stacks, int display);

// instructions_and_parsing.c
t_node		*parsing(int index, int ac, char **av, t_node *head);
void		execute_instructions(int display, t_stack *stacks,
					int instruction_number, ...);

//utils_sort.c
int			is_sorted(t_stack *stacks);
void		perform_rotation(t_stack *stack, int position, int ab);

// medium_small_sort.c
void		sort_less_than_three(t_stack *stack, int p_min);
void		medium_sort(t_stack *stack);

// large_sort.c
void		quick_sort(t_stack *stack);

// minimum_median.c
void		minimum_median(t_stack *p, int median);

//maximum_median.c
void		maximum_median(t_stack *p, int sezieme);

//main.c
int			initialize_structure(t_stack **stacks, int ac, char **av);
void		*free_stack(t_stack **stack);
void		*free_node(t_node **node);

#endif
