/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:07:43 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 10:21:08 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_node_instructions	*create_node_instructions(char *parameters)
{
	t_node_instructions	*new_node;

	new_node = ft_calloc(1, sizeof(t_node_instructions));
	if (!new_node)
		return (NULL);
	new_node->parameters = parameters;
	new_node->instructions = -1;
	new_node->next = NULL;
	return (new_node);
}

t_node_instructions	*free_node_instructions(t_node_instructions **head)
{
	if (!head || !(*head))
		return (NULL);
	free((*head)->parameters);
	(*head)->parameters = NULL;
	(*head)->parameters = 0;
	free_node_instructions(&(*head)->next);
	(*head)->next = NULL;
	free(*head);
	*head = NULL;
	return (NULL);
}

t_list_instructions	*create_list_instructions(t_node_instructions *head)
{
	t_list_instructions	*new_list;
	t_node_instructions	*index;
	int					number;

	number = 0;
	index = head;
	while (index)
	{
		index = index->next;
		number++;
	}
	new_list = ft_calloc(1, sizeof(t_list_instructions));
	if (new_list == NULL)
	{
		free_node_instructions(&head);
		return (0);
	}
	new_list->all_instructions = head;
	new_list->instructions_number = number;
	return (new_list);
}

t_list_instructions	*free_list_instructions(t_list_instructions **head)
{
	if (!head || !(*head))
		return (NULL);
	free_node_instructions(&((*head)->all_instructions));
	(*head)->all_instructions = NULL;
	(*head)->instructions_number = 0;
	free(*head);
	(*head) = NULL;
	return (NULL);
}

int	read_parameters(t_node_instructions *node)
{
	int	len_parameters;
	int	index;

	len_parameters = 0;
	index = 0;
	while (node->parameters[len_parameters])
		len_parameters++;
	while (index < 11)
	{
		if (len_parameters == 4 && (index >= 2 && index <= 4))
		{
			if (!ft_strncmp(get_instructions(index), node->parameters, 5))
				return (node->instructions = index, 0);
		}
		else if (len_parameters == 3)
		{
			if (!ft_strncmp(get_instructions(index), node->parameters, 4))
				return (node->instructions = index, 0);
		}
		index++;
	}
	return (node->instructions = -2, 1);
}
