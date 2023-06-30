/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:04:10 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/29 14:17:14 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *stacks, int display)
{
	t_node	*element;

	if (!stacks || stacks->b == 0)
		return ;
	if (display)
		write(1, "pa\n", 3);
	element = stacks->b;
	stacks->b = element->next;
	if (stacks->b)
		stacks->b->previous = 0;
	element->position = 0;
	element->next = 0;
	updated_position(-1, stacks->b);
	updated_position(1, stacks->a);
	element->next = stacks->a;
	if (element->next)
		element->next->previous = element;
	stacks->a = element;
	stacks->len_a = stacks->len_a + 1;
	stacks->len_b = stacks->len_b - 1;
}

void	pb(t_stack *stacks, int display)
{
	t_node	*element;

	if (!stacks || stacks->a == 0)
		return ;
	if (display)
		write(1, "pb\n", 3);
	element = stacks->a;
	stacks->a = element->next;
	if (stacks->a)
		stacks->a->previous = 0;
	element->position = 0;
	element->next = 0;
	updated_position(-1, stacks->a);
	updated_position(1, stacks->b);
	element->next = stacks->b;
	if (element->next)
		element->next->previous = element;
	stacks->b = element;
	stacks->len_b = stacks->len_b + 1;
	stacks->len_a = stacks->len_a - 1;
}

void	sa(t_stack *stacks, int display)
{
	t_node	*second;
	t_node	*first;

	if (!stacks || stacks->a == 0 || stacks->len_a <= 1)
		return ;
	if (display)
		write(1, "sa\n", 3);
	first = stacks->a;
	second = stacks->a->next;
	first->position = 1;
	second->position = 0;
	first->previous = second;
	second->previous = 0;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	stacks->a = second;
}

void	sb(t_stack *stacks, int display)
{
	t_node	*second;
	t_node	*first;

	if (!stacks || stacks->b == 0 || stacks->len_b <= 1)
		return ;
	if (display)
		write(1, "sb\n", 3);
	first = stacks->b;
	second = stacks->b->next;
	first->position = 1;
	second->position = 0;
	first->previous = second;
	second->previous = 0;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	stacks->b = second;
}

void	ss(t_stack *stacks, int display)
{
	if (display)
		write(1, "ss\n", 3);
	sa(stacks, 0);
	sb(stacks, 0);
}
