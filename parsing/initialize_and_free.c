/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:54:32 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 11:55:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	initialize_structure(t_stack **stacks, int ac, char **av)
{
	t_node	*a;

	a = parsing(0, ac, av, NULL);
	if (a == NULL)
		return (1);
	(*stacks) = create_structure(a);
	if ((*stacks) == NULL)
		return (1);
	return (0);
}

void	*free_node(t_node **node)
{
	if (!node || !(*node))
		return (NULL);
	(*node)->index = 0;
	(*node)->position = 0;
	(*node)->value = 0;
	(*node)->previous = NULL;
	free_node(&(*node)->next);
	(*node)->next = NULL;
	free(*node);
	*node = NULL;
	return (NULL);
}

void	*free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return (NULL);
	free_node(&((*stack)->a));
	(*stack)->a = NULL;
	free_node(&((*stack)->b));
	(*stack)->b = NULL;
	(*stack)->len_a = 0;
	(*stack)->len_b = 0;
	(*stack)->total_len = 0;
	free(*stack);
	*stack = NULL;
	return (NULL);
}
