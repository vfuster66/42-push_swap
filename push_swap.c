/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 07:32:17 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/21 16:34:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct *init_nbr(void)
{
    t_struct *new = malloc(sizeof(t_struct));

    new->mid = 0;
    new->max = 0;
    new->min = 0;
    return (new);
}

t_stack *initstack(void)
{
    t_stack *new = malloc(sizeof(t_stack));

    new->top = NULL;
    return (new);
}

int isEmpty(t_stack *stack)
{
    if (!stack->top)
        return (1);
    return (0);
}

void push(t_stack *stack, int content)
{
    t_node *new = malloc(sizeof(t_node));

    new->value = content;
    new->next = stack->top;
    stack->top = new;
}

int peek(t_stack *stack)
{
    if (isEmpty(stack) == 1)
        return (-1);
    return (stack->top->value);
}

int pop(t_stack *stack)
{
    int pop;
    t_node *tmp;
    if (isEmpty(stack) == 1)
        return (-1);
    pop = stack->top->value;
    tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
    return (pop);
}

void sa(t_stack *stack)
{
    t_node *a;
    t_node *b;

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

void sb(t_stack *stack)
{
    t_node *a;
    t_node *b;

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

void ss(t_stack *stack1, t_stack *stack2)
{
    sa(stack1);
    sb(stack2);
    ft_printf("ss\n");
}

void pa(t_stack *stack1, t_stack *stack2)
{
    int tmp;

    if (isEmpty(stack2) == 1)
        return;
    tmp = pop(stack2);
    push(stack1, tmp);
    ft_printf("pa\n");
}

void pb(t_stack *stack1, t_stack *stack2)
{
    int tmp;

    if (isEmpty(stack1) == 1)
        return;
    tmp = pop(stack1);
    push(stack2, tmp);
    ft_printf("pb\n");
}

void ra(t_stack *stack)
{
    t_node *tmp1;
    t_node *tmp2;

    if (isEmpty(stack) == 1 || !stack->top->next)
        return;
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

void rb(t_stack *stack)
{
    t_node *tmp1;
    t_node *tmp2;

    if (isEmpty(stack) == 1 || !stack->top->next)
        return;
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

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    ft_printf("rr\n");
}

void rra(t_stack *stack)
{
    t_node *a;
    t_node *b;
    t_node *c;

    if (isEmpty(stack) == 1 || !stack->top->next)
        return;
    a = stack->top;
    b = stack->top;
    c = stack->top;
    while (b->next->next)
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
    t_node *a;
    t_node *b;
    t_node *c;

    if (isEmpty(stack) == 1 || !stack->top->next)
        return;
    a = stack->top;
    b = stack->top;
    c = stack->top;
    while (b->next->next)
    {
        b = b->next;
    }
    c = b->next;
    c->next = a;
    b->next = NULL;
    stack->top = c;
    ft_printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
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
    else if (a->top->value == nbr->max)
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
    if (is_sorted(a))
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

int find_index(t_stack *a, int min)
{
    t_node *tmp;
    int i;

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

int find_max(t_stack *a)
{
    t_node *tmp;
    int max = 0;

    tmp = a->top;
    while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return (max);
}

int find_min(t_stack *a)
{
    t_node *tmp = a->top;
    int min = tmp->value;

    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }

    return min;
}

void find_mid(t_stack *a, t_struct *nbr)
{
    t_node *tmp;
    int mid;

    tmp = a->top;
    mid = tmp->value;
    while (tmp)
    {
        if (tmp->value != nbr->min && tmp->value != nbr->max)
            mid = tmp->value;
        tmp = tmp->next;
    }
    nbr->mid = mid;
}

void check_value(t_stack *a, t_struct *nbr)
{
    nbr->min = find_min(a);
    nbr->max = find_max(a);
    find_mid(a, nbr);
}

int check_nbr(t_stack *a)
{
    int count = 0;
    t_node *tmp;

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
    t_node *tmp;

    tmp = a->top;
    while (tmp && tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void sort_stack(t_stack *a, t_stack *b, t_struct *nbr) {
    int n = check_nbr(a); // Supposant que check_nbr renvoie la taille de la pile

    // Pousser le plus petit élément de 'a' à 'b' à chaque itération
    for (int i = 0; i < n; i++) {
        push_min_to_b(a, b, n - i, nbr);
    }

    // Ramener les éléments triés de 'b' à 'a'
    for (int i = 0; i < n; i++) {
        pa(a, b);
    }
}


void push_swap(t_stack *a, t_stack *b)
{
    t_struct *nbr;

    nbr = init_nbr();
    if (check_nbr(a) == 2)
        sorting_2_elements(a);
    else if (check_nbr(a) == 3)
        sorting_3_elements(a);
    else if (check_nbr(a) == 4)
        sorting_4_elements(a, b);
    else if (check_nbr(a) == 5)
        sorting_5_elements(a, b);
    else
    {
        sort_stack(a, b, nbr);
    }
    free(a);
    free(b);
}

void print_stack(t_stack *stack)
{
    t_node *tmp = stack->top;
    while (tmp)
    {
        ft_printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int isInt(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] < 48 || str[i] > 57)
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    b = initstack();
    a = initstack();
    if (ac >= 2)
    {
        int i;

        i = ac - 1;
        while (av[i] && i != 0)
        {
            if (isInt(av[i]) == 1)
            {
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


