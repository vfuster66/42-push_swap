/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:20:07 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/23 12:33:11 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_medianquartile
{
	int	median;
	int	first_quart;
	int	second_quart;
	int	len;
}		t_medianquartile;

int			ft_atoi_and_check(const char *nptr, int *error);
void		quick_sort(int array[], int low, int high);
void		find_median_quartile(char **spl, t_medianquartile **data, int *error);
void		fill_median_quartile(t_medianquartile **data, int len, int array[]);
void		free_stacks(t_stack **a, t_stack **b, t_medianquartile **data);

// list_utils
int			new_element(int nbr, t_stack **element);
int			add_to_list(t_stack **stack, int number);
void		free_stack(t_stack **stack);
int			len(t_stack *stack);

// getter
int			find_index(t_stack *stack, int element);
int			find_minimum(t_stack *stack);
int			find_maximum(t_stack *stack);
int			find_insertion_position(t_stack *stack, int element);
int			find_best_move(t_stack *a, t_stack *b);

// swap
void		sa(t_stack **a);
void		sb(t_stack **b);

// push
void		pa(t_stack **a, t_stack **b, t_medianquartile **data);
void		pb(t_stack **a, t_stack **b, t_medianquartile **data);

// rotate
void		rr(t_stack **a, t_stack **b);
void		ra(t_stack **a, int print);
void		rb(t_stack **b, int print);

void		rrr(t_stack **a, t_stack **b);
void		rra(t_stack **a, int print);
void		rrb(t_stack **b, int print);

//algo
void		sort_three(t_stack **a);
int			is_sorted(t_stack *stack);
int			is_value_in_range(t_stack *stack, int first_quart, int second_quart);
void		replace_stack(t_stack **stack);
void		insertion_sort(t_stack **a, t_stack **b, int b_move, t_medianquartile **data);
void		optimize_pb(t_stack *a, t_stack *b, t_medianquartile *data);
void		optimize_pa(t_stack *a, t_stack *b, t_medianquartile *data);

#endif


