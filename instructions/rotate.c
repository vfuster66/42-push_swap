/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:05:02 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:05:22 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stacks, int display)
{
	t_node	*first;
	t_node	*last;

	if (display)
		write(1, "ra\n", 3);
	if (!stacks || stacks->a == 0 || stacks->len_a <= 1)
		return ;
	last = find_last_node(stacks->a);
	first = stacks->a;
	stacks->a = first->next;
	stacks->a->previous = 0;
	first->next = 0;
	last->next = first;
	first->previous = last;
	first->position = last->position + 1;
	updated_position(-1, stacks->a);
}

void	rb(t_stack *stacks, int display)
{
	t_node	*first;
	t_node	*last;

	if (display)
		write(1, "rb\n", 3);
	if (!stacks || stacks->b == 0 || stacks->len_b <= 1)
		return ;
	last = find_last_node(stacks->b);
	first = stacks->b;
	stacks->b = first->next;
	stacks->b->previous = 0;
	first->next = 0;
	last->next = first;
	first->previous = last;
	first->position = last->position + 1;
	updated_position(-1, stacks->b);
}

void	rr(t_stack *stacks, int display)
{
	if (display)
		write(1, "rr\n", 3);
	ra(stacks, 0);
	rb(stacks, 0);
}
