/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:20:42 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 15:20:52 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	execute_instructions(int display, t_stack *stacks,
	int instruction_number, ...)
{
	va_list	instruction_list;

	va_start(instruction_list, instruction_number);
	while (instruction_number--)
		instructions(va_arg(instruction_list, int), display, stacks);
	va_end(instruction_list);
}
