/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:33:52 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 16:59:56 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Tri final de la liste de noeuds
static void	final_sort(t_stack *stack)
{
	t_node	*last_node;

	last_node = find_last_node(stack->a);
	if (stack->b->index > stack->a->index
		&& stack->b->index < stack->a->next->index)
	{
		if (stack->b->next && stack->b->next->next \
		&& stack->b->next->index < stack->b->next->next->index)
			execute_instructions(TRUE, stack, 2, PA, SS);
		else
			execute_instructions(TRUE, stack, 2, PA, SA);
		return ;
	}
	if (stack->b->index > last_node->index && stack->b->index < stack->a->index)
	{
		execute_instructions(TRUE, stack, 1, PA);
		return ;
	}
	else if (stack->b->index > last_node->index)
		execute_instructions(TRUE, stack, 1, RA);
	else
		execute_instructions(TRUE, stack, 1, RRA);
	return (final_sort(stack));
}

//Premier tri de la liste de noeuds
static void	first_sort(t_stack *stack, int sixteenth)
{
	minimum_median(stack, sixteenth);
	maximum_median(stack, sixteenth);
}

//Tri complet de la liste de noeuds
static void	perform_sort(t_stack *stack)
{
	while (stack->b)
		final_sort(stack);
	perform_rotation(stack, find_minimum(stack->a)->position, STACK_A);
}

//Tri rapide de la liste de noeuds
void	quick_sort(t_stack *stack)
{
	first_sort(stack, stack->total_len / 16);
	perform_sort(stack);
}
