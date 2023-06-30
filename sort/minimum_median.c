/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:11:57 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 16:53:14 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//trie une partie de b lorsque la valeur du noeud est superieure ou
//egale au quartile donne
static void	minimum_quartile_sort(t_stack *stack, int quartile)
{
	if (!stack->b)
		return ;
	while (stack->b->index >= quartile)
	{
		if (stack->b->index > quartile + (quartile / 2))
		{
			execute_instructions(TRUE, stack, 1, PA);
		}
		else
			execute_instructions(TRUE, stack, 1, RB);
	}
	while (stack->b->index <= quartile)
	{
		if (stack->b->index < quartile - (quartile / 2))
			execute_instructions(TRUE, stack, 1, PA);
		else
			execute_instructions(TRUE, stack, 1, RB);
	}
}

//trie une partie de a lorsque la valeur du noeud est inferieure ou
//egale a l'octile donne
static void	minimum_octile_sort(t_stack *stack, int octile)
{
	while (stack->a->index <= octile)
	{
		if (!stack->a->index)
			execute_instructions(TRUE, stack, 1, RA);
		else
			execute_instructions(TRUE, stack, 1, PB);
		if (stack->b->index >= (octile / 2))
			execute_instructions(TRUE, stack, 1, RB);
	}
	while (stack->b->index <= octile)
		execute_instructions(TRUE, stack, 1, RB);
	while (stack->a->index <= octile * 4)
	{
		if (!stack->a->index)
			execute_instructions(TRUE, stack, 1, RA);
		else
			execute_instructions(TRUE, stack, 1, PB);
		if (stack->b->index >= (octile * 4) - (octile / 2))
			execute_instructions(TRUE, stack, 1, RB);
	}
	while (find_last_node(stack->b)->index > octile)
		execute_instructions(TRUE, stack, 1, RRB);
}

//trie une partie de b lorsque la valeur du noeud est superieure
//ou egale au seizieme donne
static void	minimum_sixteenth_sort(t_stack *p, int sixteenth)
{
	while (p->b->index >= (sixteenth * 4))
	{
		if (p->b->index >= (sixteenth * 5))
			execute_instructions(TRUE, p, 1, PA);
		else
			execute_instructions(TRUE, p, 1, RB);
	}
	while (p->b->index <= (sixteenth * 4))
	{
		if (p->b->index <= (sixteenth * 3))
			execute_instructions(TRUE, p, 1, PA);
		else
			execute_instructions(TRUE, p, 1, RB);
	}
	while (p->a->index <= (sixteenth * 4))
		execute_instructions(TRUE, p, 2, PB, RB);
	while (p->a->index > sixteenth * 2)
		execute_instructions(TRUE, p, 1, PB);
}

//trie une liste de noeuds lorsque la taille de la liste est
//superieure a la mediane
void	minimum_median(t_stack *stack, int sixteenth)
{
	int	median;
	int	octile;

	octile = sixteenth * 2;
	median = sixteenth * 8;
	while (stack->len_b + 1 <= median)
	{
		if (stack->a->index == 0)
			execute_instructions(TRUE, stack, 1, RA);
		if (stack->a->index <= median)
		{
			execute_instructions(TRUE, stack, 1, PB);
			if (stack->len_b > 1 && stack->b->index <= median / 2)
				execute_instructions(TRUE, stack, 1, RB);
		}
		else
			execute_instructions(TRUE, stack, 1, RA);
	}
	minimum_quartile_sort(stack, sixteenth * 4);
	minimum_sixteenth_sort(stack, sixteenth);
	minimum_octile_sort(stack, octile);
}
