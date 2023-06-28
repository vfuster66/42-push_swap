/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:05:56 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:44:06 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *stacks, int display)
{
	t_node	*last;

	if (display)
		write(1, "rra\n", 4);
	if (!stacks || stacks->a == 0 || stacks->len_a <= 1)
		return ;
	last = find_last_node(stacks->a);
	if (last->previous)
		last->previous->next = 0;
	last->previous = 0;
	last->position = 0;
	updated_position(+1, stacks->a);
	last->next = stacks->a;
	if (last->next)
		last->next->previous = last;
	stacks->a = last;
}

void	rrb(t_stack *stacks, int display)
{
	t_node	*last;

	if (display)
		write(1, "rrb\n", 4);
	if (!stacks || stacks->b == 0 || stacks->len_b <= 1)
		return ;
	last = find_last_node(stacks->b);
	if (last->previous)
		last->previous->next = 0;
	last->previous = 0;
	last->position = 0;
	updated_position(+1, stacks->b);
	last->next = stacks->b;
	if (last->next)
		last->next->previous = last;
	stacks->b = last;
}

void	rrr(t_stack *stacks, int display)
{
	if (display)
		write(1, "rrr\n", 4);
	rra(stacks, 0);
	rrb(stacks, 0);
}
