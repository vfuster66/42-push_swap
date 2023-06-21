/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 07:32:17 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/21 08:52:26 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*init_nbr(void)
{
	struct s_struct	*new = malloc(sizeof(struct s_struct));

	new->mid = 0;
	new->max = 0;
	new->min = 0;
	return (new);
}

struct s_stack	*initstack(void)
{
	struct s_stack	*new = malloc(sizeof(struct s_stack));

	new->top = NULL;
	return (new);
}

int	isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	push(struct s_stack *stack, int content)
{
	struct s_node	*new = malloc(sizeof(struct s_node));

	new->value = content;
	new->next = stack->top;
	stack->top = new;
}

int	peek(struct s_stack *stack)
{
	if (isEmpty(stack) == 1)
		return (-1);
	return (stack->top->value);
}

int	pop(struct s_stack *stack)
{
	int	pop;
	struct s_node	*tmp;
	if (isEmpty(stack) == 1)
		return (-1);
	pop = stack->top->value;
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return (pop);
}

void	sa(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next)
	{
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next)
	{
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	sa(stack1);
	sb(stack2);
	ft_printf("ss\n");
}

void	pa(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack2) == 1)
		return ;
	tmp = pop(stack2);
	push(stack1, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack1) == 1)
		return ;
	tmp = pop(stack1);
	push(stack2, tmp);
	ft_printf("pb\n");
}

void	ra(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return ;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return ;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void rra(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if(isEmpty(stack) == 1 || !stack->top->next)
		return ;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while(b->next->next)
	{
		b = b->next;
	}
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rra\n");
}

void rrb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if(isEmpty(stack) == 1 || !stack->top->next)
		return ;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while(b->next->next)
	{
		b = b->next;
	}
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

void sorting_2_elements(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a);
}

void sorting_3_elements(t_stack *a)
{
    t_struct *nbr;

    nbr = init_nbr();
    check_value(a, nbr);

    if (a->top->value == nbr->min && a->top->next->value == nbr->max)
    {
        sa(a);
        ra(a);
    }
    else if (a->top->value == nbr->mid)
    {
        if (a->top->next->value == nbr->min)
            sa(a);
        else
            rra(a);
    }
    else if  (a->top->value == nbr->max)
    {
        if (a->top->next->value == nbr->mid)
        {
            sa(a);
            rra(a);
        }
        else
            ra(a);
    }
    free(nbr);
}

void push_min_to_b(t_stack *a, t_stack *b, int max_rotations, t_struct *nbr)
{
    int min_val;
    int rotations = 0;
    check_value(a, nbr);
    min_val = nbr->min;

    while (rotations < max_rotations)
    {
        if (a->top->value == min_val)
        {
            break;
        }
        ra(a);
        rotations++;
    }
    pb(a, b);
}

void sorting_4_elements(t_stack *a, t_stack *b)
{
    t_struct *nbr = init_nbr();

    push_min_to_b(a, b, 3, nbr);
    sorting_3_elements(a);
    pa(a, b);
    free(nbr);
}

void sorting_5_elements(t_stack *a, t_stack *b)
{
    t_struct *nbr = init_nbr();

    push_min_to_b(a, b, 4, nbr);
	if (!is_sorted(a))
		pa(a, b);
	else
	{
   		push_min_to_b(a, b, 3, nbr);
   		sorting_3_elements(a);
   		pa(a, b);
   		pa(a, b);
	}
    free(nbr);
}

int		find_index(t_stack *a, int min)
{
	t_node	*tmp;
	int	i;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == min)
			return (i + 1);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int		find_max(t_stack *a)
{
	t_node	*tmp;
	int	max = 0;

	tmp = a->top;
	while(tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return(max);
}

int		find_min(t_stack *a)
{
	t_node	*tmp;
	int	min;

	tmp = a->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	find_mid(t_stack *a, t_struct *nbr)
{
	t_node	*tmp;
	int	mid;

	tmp = a->top;
	mid = tmp->value;
	while(tmp)
	{
		if (tmp->value != nbr->min && tmp->value
			!= nbr->max)
			mid = tmp->value;
		tmp = tmp->next;
	}
	nbr->mid = mid;
}

void	check_value(t_stack *a, t_struct *nbr)
{
	nbr->min = find_min(a);
	nbr->max = find_max(a);
	find_mid(a, nbr);
}

int		check_nbr(t_stack *a)
{
	int	count = 0;
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while(tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*void insertion_sort_avec_operations_pile(t_stack *a, t_stack *b) {
    int n = a->size;
    int i = 1;

    while (i < n) {
        pb(a, b);
        int rotations = 0;

        while (a->size > 0 && peek(a) > peek(b)) {
            ra(a);
            rotations++;
        }

        pa(a, b);

        int j = 0;
        while (j < rotations) {
            rra(a);
            j++;
        }

        i++;
    }
}

void merge_with_stack_operations(t_stack *a, t_stack *b, t_stack *c, int len1, int len2) {
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (peek(b) < peek(c)) {
            pa(a, b);
            i++;
        } else {
            pa(a, c);
            j++;
        }
    }

    while (i < len1) {
        pa(a, b);
        i++;
    }

    while (j < len2) {
        pa(a, c);
        j++;
    }
}

void timsort_with_stack_operations(t_stack *a) {
    int n = a->size;
    t_stack b, c;
    initstack();

    int RUN = 32;
    int i = 0;

    while (i < n) {
        int runSize = n - i;
        if (runSize > RUN) {
            runSize = RUN;
        }

        int j = 0;
        while (j < runSize) {
            pb(a, &b);
            j++;
        }

        insertion_sort_avec_operations_pile(&b, &c);

        i += RUN;
    }

    int size = RUN;
    while (size < n) {
        i = 0;
        while (i < n) {
            int left = i;
            int mid = i + size - 1;
            int right = i + 2 * size - 1;

            if (mid >= n) {
                mid = n - 1;
            }

            if (right >= n) {
                right = n - 1;
            }

            int len1 = mid - left + 1;
            int len2 = right - mid;

            int j = 0;
            while (j < len1) {
                pb(a, &b);
                j++;
            }

            j = 0;
            while (j < len2) {
                pb(a, &c);
                j++;
            }

            merge_with_stack_operations(a, &b, &c, len1, len2);

            i += 2 * size;
        }
        size *= 2;
    }
}*/

void merge(t_stack **a, t_stack **b, int left, int right) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < left && j < right) {
        if ((*b)->value < (*a)->value) {
            pa(*a, *b);
            j++;
        } else {
            pb(*b, *a);
            i++;
        }
        k++;
    }

    while (i < left) {
        pb(*b, *a);
        i++;
        k++;
    }

    while (j < right) {
        pa(*a, *b);
        j++;
        k++;
    }

    while (k > 0) {
        pb(*a, *b);
        k--;
    }
}

void merge_sort_with_stack_operations(t_stack **a, t_stack **b, int len) {
    int mid;
    int i;

    if (len < 2) {
        return;
    }

    mid = len / 2;

    for (i = 0; i < mid; i++) {
        pb(*a, *b);
    }
    merge_sort_with_stack_operations(b, a, mid);
    merge_sort_with_stack_operations(a, b, len - mid);
    merge(a, b, mid, len - mid);
}


void	push_swap(t_stack *a, t_stack *b)
{

	if (check_nbr(a) == 2)
		sorting_2_elements(a);
	else if (check_nbr(a) == 3)
		sorting_3_elements(a);
	else if (check_nbr(a) == 4)
		sorting_4_elements(a, b);
	else if (check_nbr(a) == 5)
		sorting_5_elements(a, b);
	else
		merge_sort_with_stack_operations(&a, &b, check_nbr(a));
    free(a);
    free(b);
}

void	print_stack(struct s_stack *stack)
{
	while (stack->top)
	{
		ft_printf("%d\n", stack->top->value);
		stack->top = stack->top->next;
	}
}

int	isInt(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct s_stack	*a;
	struct s_stack	*b;

	a = initstack();
	b = initstack();
	if (ac >= 2)
	{
		int	i;

		i = ac - 1;
		while (av[i] && i != 0)
		{
			if (isInt(av[i]) == 1) {
				ft_printf("ERROR\n");
				exit(0);
			}
			push(a, ft_atoi(av[i]));
			i--;
		}
	}
	if (is_sorted(a) == 1)
		return (0);
	push_swap(a, b);
	return (0);
}




