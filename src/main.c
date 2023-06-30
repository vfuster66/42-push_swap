/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:28:40 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 11:55:09 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
