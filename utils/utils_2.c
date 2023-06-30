/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:33:34 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:11:18 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	iterate_nodes(t_node *node, int index, void (*f)(t_node *, int))
{
	if (!node || !f)
		return ;
	f(node, index);
	if (!node->next)
		return ;
	iterate_nodes(node->next, index, f);
}

int	size_node(t_node *stack_a)
{
	if (!stack_a)
		return (0);
	return (1 + size_node(stack_a->next));
}

void	updated_position(int offset, t_node *stack)
{
	if (!stack)
		return ;
	stack->position = stack->position + offset;
	updated_position(offset, stack->next);
}

t_node	*find_last_node(t_node *stack)
{
	if (!stack)
		return (0);
	else if (stack->next == 0)
		return (stack);
	return (find_last_node(stack->next));
}

t_stack	*create_structure(t_node *stack_a)
{
	t_stack	*new_stack;
	int		len;

	len = size_node(stack_a);
	new_stack = ft_calloc(1, sizeof(t_stack));
	if (new_stack == NULL)
		return (free_node(&stack_a));
	new_stack->a = stack_a;
	new_stack->b = NULL;
	new_stack->len_a = len;
	new_stack->len_b = 0;
	new_stack->total_len = len;
	return (new_stack);
}
