/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:29:51 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 10:19:54 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_list_instructions	*parsing_instructions(void)
{
	t_node_instructions	*head;
	t_node_instructions	*index;
	char				*input;

	input = get_next_line(0);
	head = NULL;
	index = NULL;
	while (input)
	{
		if (!head)
		{
			head = create_node_instructions(input);
			index = head;
		}
		else
		{
			index->next = create_node_instructions(input);
			index = index->next;
		}
		if (!index)
			return (free_node_instructions(&head), free(input), NULL);
		input = get_next_line(0);
	}
	return (free(input), create_list_instructions(head));
}

int	read_instructions(t_list_instructions *all_instructions)
{
	t_node_instructions	*index;

	if (!all_instructions)
		return (1);
	index = all_instructions->all_instructions;
	while (index)
	{
		if (read_parameters(index))
			return (1);
		index = index->next;
	}
	return (0);
}

void	perform_instructions(t_node_instructions *instructions, t_stack *stacks)
{
	while (instructions)
	{
		execute_instructions(0, stacks, 1, instructions->instructions);
		instructions = instructions->next;
	}
	if (is_sorted(stacks) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

char	*get_instructions(int instructions_index)
{
	if (instructions_index == 0)
		return ("pa\n");
	else if (instructions_index == 1)
		return ("pb\n");
	else if (instructions_index == 2)
		return ("rra\n");
	else if (instructions_index == 3)
		return ("rrb\n");
	else if (instructions_index == 4)
		return ("rrr\n");
	else if (instructions_index == 5)
		return ("ra\n");
	else if (instructions_index == 6)
		return ("rb\n");
	else if (instructions_index == 7)
		return ("rr\n");
	else if (instructions_index == 8)
		return ("sa\n");
	else if (instructions_index == 9)
		return ("sb\n");
	else if (instructions_index == 10)
		return ("ss\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	t_stack				*stacks;
	t_list_instructions	*all_instructions;

	if (initialize_structure(&stacks, ac, av))
		return (1);
	all_instructions = parsing_instructions();
	if (!all_instructions)
		return (free_stack(&stacks), \
		free_list_instructions(&all_instructions), 1);
	if (read_instructions(all_instructions))
		return (free_stack(&stacks), \
		free_list_instructions(&all_instructions), write(2, "Error\n", 6), 0);
	perform_instructions(all_instructions->all_instructions, stacks);
	free_list_instructions(&all_instructions);
	free_stack(&stacks);
	return (0);
}
