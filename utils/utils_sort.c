/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:29:30 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 16:36:42 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Verifie si les noeuds de la liste chainee sont tries dans l'ordre
//croissant selon leur champ index
static int	is_ordered(t_node *head, t_node *minimum, t_node *current)
{
	t_node	*index;

	index = current;
	while (index != minimum)
	{
		if (current->index > index->index)
			return (1);
		if (index->next == NULL)
			index = head;
		else
			index = index->next;
	}
	return (0);
}

//Verifie si la liste stacks->a est triee dans l'ordre croissant
int	is_sorted(t_stack *stacks)
{
	t_node	*current;
	t_node	*minimum;

	if (!stacks || stacks->a == NULL)
		return (0);
	minimum = find_minimum(stacks->a);
	current = stacks->a;
	while (current)
	{
		if (is_ordered(stacks->a, minimum, current))
			return ((-1 * minimum->position) - 1);
		current = current->next;
	}
	return (minimum->position);
}

//Calcule le decalage d'une position donnee par rapport a la
//moitie de la longueur totale de la liste.
//Si la position est superieure a la moitie de la longueur
//elle renvoie la difference entre la position et la longueur.
//Sinon, renvoie la position elle-meme
static int	calculate_offset_position(int position, int len)
{
	if (position > len / 2)
		return (position - len);
	return (position);
}

//Effectue un decalage circulaire des noeuds dans une liste
void	perform_rotation(t_stack *stack, int position, int stack_a)
{
	int	offset;

	if (stack_a)
		offset = calculate_offset_position(position, stack->len_a);
	else
		offset = calculate_offset_position(position, stack->len_b);
	while (offset)
	{
		if (offset < 0)
		{
			if (stack_a)
				execute_instructions(TRUE, stack, 1, RRA);
			else
				execute_instructions(TRUE, stack, 1, RRB);
			offset++;
		}
		else
		{
			if (stack_a)
				execute_instructions(TRUE, stack, 1, RA);
			else
				execute_instructions(TRUE, stack, 1, RB);
			offset--;
		}
	}
}
