/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:33:34 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 16:31:08 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Fonction recursive qui permet d'appliquer une fonction donnee
//a chaque noeud de la liste
void	iterate_nodes(t_node *node, int index, void (*f)(t_node *, int))
{
	if (!node || !f)
		return ;
	f(node, index);
	if (!node->next)
		return ;
	iterate_nodes(node->next, index, f);
}

//Fonction recursive qui calcule la taille d'une liste de noeuds
int	size_node(t_node *list)
{
	if (!list)
		return (0);
	return (1 + size_node(list->next));
}

//Fonction recursive qui met a jour la position de chaque noeud de
//la liste en ajoutant un decalage a chaque position
void	updated_position(int offset, t_node *list)
{
	if (!list)
		return ;
	list->position = list->position + offset;
	updated_position(offset, list->next);
}

//Fonction recursive qui cherche le dernier noeud d'une liste donnee
t_node	*find_last_node(t_node *list)
{
	if (!list)
		return (0);
	else if (list->next == 0)
		return (list);
	return (find_last_node(list->next));
}

//Cree une structure t_stack a partir d'une liste de noeuds
//Alloue la memoire necessaire a la structure
//Initialise les champs avec les informations de la liste
t_stack	*create_structure(t_node *list_a)
{
	t_stack	*new_stack;
	int		len;

	len = size_node(list_a);
	new_stack = ft_calloc(1, sizeof(t_stack));
	if (new_stack == NULL)
		return (free_node(&list_a));
	new_stack->a = list_a;
	new_stack->b = NULL;
	new_stack->len_a = len;
	new_stack->len_b = 0;
	new_stack->total_len = len;
	return (new_stack);
}
