/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:28:40 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/29 14:19:20 by vfuster-         ###   ########.fr       */
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

static void	push_swap(t_stack *stacks)
{
	int		sort_result;

	sort_result = is_sorted(stacks);
	if (sort_result > 0 || stacks->total_len <= 3)
		sort_less_than_three(stacks, sort_result);
	else if (sort_result && stacks->total_len <= 25)
		medium_sort(stacks);
	else if (sort_result)
		quick_sort(stacks);
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac == 1)
		return (0);
	if (initialize_structure(&stacks, ac, av))
		return (1);
	push_swap(stacks);
	free_stack(&stacks);
	return (0);
}
