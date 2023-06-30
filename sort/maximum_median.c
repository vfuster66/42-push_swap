/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:13:11 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:13:31 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	maximum_sixteenth_bottom(t_stack *stack, int sixteenth)
{
	while (stack->b->index > sixteenth * 8)
	{
		if (stack->b->index >= sixteenth * 9)
			execute_instructions(TRUE, stack, 1, PA);
		else
			execute_instructions(TRUE, stack, 1, RB);
	}
	while (find_last_node(stack->b)->index < sixteenth * 10)
		execute_instructions(TRUE, stack, 1, RRB);
	while (stack->a->index && stack->a->index < sixteenth * 11)
		execute_instructions(TRUE, stack, 1, PB);
	while (find_last_node(stack->b)->index > sixteenth * 8)
	{
		if (find_last_node(stack->b)->index \
		&& find_last_node(stack->b)->index >= sixteenth * 11)
			execute_instructions(TRUE, stack, 2, RRB, PA);
		else
			execute_instructions(TRUE, stack, 1, RRB);
	}
	while (stack->a->index && stack->a->index < sixteenth * 13)
		execute_instructions(TRUE, stack, 1, PB);
}

static void	maximum_sixteenth_middle(t_stack *p, int sixteenth)
{
	t_node	*last_nodea;

	last_nodea = find_last_node(p->a);
	while (p->a != last_nodea)
	{
		if (p->a->index && p->a->index <= sixteenth * 14)
		{
			execute_instructions(TRUE, p, 1, PB);
			if (p->b->index >= sixteenth * 13)
				execute_instructions(TRUE, p, 1, RB);
		}
		else
			execute_instructions(TRUE, p, 1, RA);
	}
	if (p->a->index && p->a->index <= sixteenth * 14)
	{
		execute_instructions(TRUE, p, 1, PB);
		if (p->b->index >= sixteenth * 13)
			execute_instructions(TRUE, p, 1, RB);
	}
	while (find_last_node(p->b)->index > sixteenth * 8)
		execute_instructions(TRUE, p, 1, RRB);
}

static void	maximum_sixteenth_top(t_stack *p, int sixteenth)
{
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->total_len - 1)
			execute_instructions(TRUE, p, 1, RA);
		else
			execute_instructions(TRUE, p, 1, PB);
		if (p->b->index >= sixteenth * 15)
			execute_instructions(TRUE, p, 1, RB);
	}
	while (find_last_node(p->b)->index > sixteenth * 8)
		execute_instructions(TRUE, p, 1, RRB);
}

void	maximum_median(t_stack *stack, int sixteenth)
{
	t_node	*last_node;

	last_node = find_last_node(stack->a);
	while (stack->a != last_node)
	{
		if (stack->a->index == 0 || stack->a->index == stack->total_len - 1)
			execute_instructions(TRUE, stack, 1, RA);
		else if (stack->a->index <= sixteenth * 12)
		{
			execute_instructions(TRUE, stack, 1, PB);
			if (stack->b->index >= sixteenth * 10)
				execute_instructions(TRUE, stack, 1, RB);
		}
		else
			execute_instructions(TRUE, stack, 1, RA);
	}
	if (stack->a->index && stack->a->index <= sixteenth * 12)
	{
		execute_instructions(TRUE, stack, 1, PB);
		if (stack->b->index <= sixteenth * 10)
			execute_instructions(TRUE, stack, 1, RB);
	}
	maximum_sixteenth_bottom(stack, sixteenth);
	maximum_sixteenth_middle(stack, sixteenth);
	maximum_sixteenth_top(stack, sixteenth);
}
