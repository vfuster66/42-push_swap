/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_small_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:30:02 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:40:03 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_less_than_three(t_stack *stack, int minimum_position)
{
	if (!stack || !minimum_position)
		return ;
	if (stack->total_len == 2 || (stack->len_a == 3 && minimum_position == -2))
		return (execute_instructions(TRUE, stack, 1, SA));
	else if (stack->len_a == 3 && minimum_position == -3)
		return (execute_instructions(TRUE, stack, 2, RA, SA));
	else if (stack->len_a == 3 && minimum_position == -1)
		return (execute_instructions(TRUE, stack, 2, RRA, SA));
	else if (minimum_position > 0)
		return (perform_rotation(stack, minimum_position, STACK_A));
}

static void	sort_m(t_stack *stack, t_node *node_b)
{
	t_node	*next_node;

	next_node = find_closest_node(stack->a, node_b);
	if (next_node->index < node_b->index)
	{
		if (next_node->next == NULL)
			next_node = stack->a;
		else
			next_node = next_node->next;
	}
	perform_rotation(stack, next_node->position, STACK_A);
	execute_instructions(TRUE, stack, 1, PA);
}

void	medium_sort(t_stack *stack)
{
	while (stack->len_a > 3)
		execute_instructions(1, stack, 1, PB);
	sort_less_than_three(stack, is_sorted(stack));
	while (stack->b)
		sort_m(stack, stack->b);
	perform_rotation(stack, find_minimum(stack->a)->position, STACK_A);
}
