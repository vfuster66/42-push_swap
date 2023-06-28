/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:28:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/28 10:09:09 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	validate_atoi_input(char *nptr)
{
	long	number;
	int		sign;
	size_t	i;

	i = 0;
	number = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] == '0' && nptr[i + 1] != '\0')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10;
		number += nptr[i] - '0';
		if (number > 2147483647 || number * sign < -2147483648)
			return (2);
		i++;
	}
	return (nptr[i] != '\0' || !i);
}

static int	handle_parsing_error(char *arg, int value, t_node *last_node, int index)
{
	if (validate_atoi_input(arg) >= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_node == NULL)
		return (1);
	else if (last_node->value == value)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (handle_parsing_error(arg, value, last_node->previous, index));
}

t_node	*parsing(int index, int ac, char **av, t_node *head)
{
	t_node	*last_node;
	int		new_value;

	last_node = 0;
	while ((index + 1) < ac)
	{
		index++;
		new_value = ft_atoi(av[index]);
		if (handle_parsing_error(av[index], new_value, last_node, index - 1))
			return (free_node(&head));
		if (!head)
		{
			last_node = create_node(new_value, (index - 1), 0);
			head = last_node;
		}
		else
		{
			last_node->next = create_node(new_value, (index - 1), last_node);
			last_node = last_node->next;
		}
	}
	return (head);
}

static void	instructions(int instruction_id, int display, t_stack *stacks)
{
	if (instruction_id == 0)
		pa(stacks, display);
	else if (instruction_id == 1)
		pb(stacks, display);
	else if (instruction_id == 2)
		rra(stacks, display);
	else if (instruction_id == 3)
		rrb(stacks, display);
	else if (instruction_id == 4)
		rrr(stacks, display);
	else if (instruction_id == 5)
		ra(stacks, display);
	else if (instruction_id == 6)
		rb(stacks, display);
	else if (instruction_id == 7)
		rr(stacks, display);
	else if (instruction_id == 8)
		sa(stacks, display);
	else if (instruction_id == 9)
		sb(stacks, display);
	else if (instruction_id == 10)
		ss(stacks, display);
}

void	execute_instructions(int display, t_stack *stacks, int instruction_number, ...)
{
	va_list	instruction_list;

	va_start(instruction_list, instruction_number);
	while (instruction_number--)
		instructions(va_arg(instruction_list, int), display, stacks);
	va_end(instruction_list);
}
