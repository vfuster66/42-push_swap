/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:30:08 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 16:22:51 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Manipulation sructure de donnees en liste chainee t_node
//Recherche le noeud avec la valeur index la plus petite ds la liste
t_node	*find_minimum(t_node *head)
{
	t_node	*index;
	t_node	*result;

	index = head;
	result = head;
	while (index)
	{
		if (index->index < result->index)
			result = index;
		if (result->index == 0)
			return (result);
		index = index->next;
	}
	return (result);
}

//Recherche le noeud avec la valeur index la plus grande ds la liste
t_node	*find_maximum(t_node *head)
{
	t_node	*index;
	t_node	*result;

	index = head;
	result = head;
	while (index)
	{
		if (index->index > result->index)
			result = index;
		index = index->next;
	}
	return (result);
}

// Fonction recursive utilisee pour mettre a jour la valeur index
// Compare la valeur previous et current
void	get_index(t_node *previous, t_node *current)
{
	if (!previous)
		return ;
	if (previous->value > current->value)
		previous->index++;
	else if (previous->index >= current->index)
		current->index = previous->index + 1;
	get_index(previous->previous, current);
}

// cherche le noeud le plus proche de la cible
t_node	*find_closest_node(t_node *list_a, t_node *target_node)
{
	t_node	*closest_node;
	int		index_diff;
	int		current_diff;
	t_node	*current_node;

	current_node = list_a;
	index_diff = 0;
	while (current_node)
	{
		if (target_node->index > current_node->index)
			current_diff = target_node->index - current_node->index;
		else
			current_diff = current_node->index - target_node->index;
		if (!index_diff || current_diff < index_diff)
		{
			closest_node = current_node;
			index_diff = current_diff;
		}
		current_node = current_node->next;
	}
	return (closest_node);
}

//cree un nouveau noeud avec une valeur donnee, une position donnee
//et un noeud precedent donne
t_node	*create_node(int value, int position, t_node *previous)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (0);
	new_node->value = value;
	new_node->index = 0;
	new_node->position = position;
	new_node->previous = previous;
	new_node->next = 0;
	get_index(previous, new_node);
	return (new_node);
}
