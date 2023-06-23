/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:14:43 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/23 12:59:44 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int element)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->value == element)
			return (i);
		temp = temp->next;
		++i;
	}
	return (i);
}

int	find_minimum(t_stack *stack)
{
	int		minimum;
	t_stack	*temp;

	temp = stack->next;
	minimum = stack->value;
	while (temp != stack && temp != NULL)
	{
		if (temp->value < minimum)
			minimum = temp->value;
		temp = temp-> next;
	}
	return (minimum);
}

int	find_maximum(t_stack *stack)
{
	int		maximum;
	t_stack	*temp;

	temp = stack->next;
	maximum = stack->value;
	while (temp != stack && temp != NULL)
	{
		if (temp->value > maximum)
			maximum = temp->value;
		temp = temp-> next;
	}
	return (maximum);
}

int	find_insertion_position(t_stack *stack, int element)
{
	int		minimum;
	int		i;
	int		l;
	t_stack	*temp;

	minimum = find_minimum(stack);
	if (element > find_maximum(stack) || element < minimum)
		return (find_index(stack, minimum));
	l = len(stack);
	i = -1;
	temp = stack;
	while (++i < l)
	{
		if (temp->previous->value < element && element < temp->value)
			return (i);
		temp = temp->next;
	}
	return (0);
}

int	new_element(int number, t_stack **element)
{
	(*element) = malloc(sizeof(t_stack));
	if (!(*element))
		return (-1);
	(*element)->value = number;
	(*element)->next = NULL;
	(*element)->previous = NULL;
	return (1);
}

void	free_stacks(t_stack **a, t_stack **b, t_medianquartile **data)
{
	free_stack(a);
	free_stack(b);
	free(*data);
}

int	add_to_list(t_stack **stack, int number)
{
	t_stack	*element;

	if (new_element(number, &element) == -1)
		return (-1);
	if ((*stack) == NULL)
	{
		(*stack) = element;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
	}
	else
	{
		element->previous = (*stack)->previous;
		element->next = (*stack);
		(*stack)->previous->next = element;
		(*stack)->previous = element;
		(*stack) = element;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if ((*stack) == NULL)
		return ;
	current = (*stack);
	while (current->next != (*stack))
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	*stack = NULL;
}

int	len(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if ((stack) && stack->next != stack)
	{
		temp = (stack)->next;
		i = 1;
		while (temp != (stack))
		{
			++i;
			temp = temp->next;
		}
		return (i);
	}
	return (0);
}

void	pa(t_stack **a, t_stack **b, t_medianquartile **data)
{
	t_stack	*temp;

	if (add_to_list(a, (*b)->value) == -1)
	{
		free_stacks(a, b, data);
		exit(1);
	}
	temp = (*b);
	(*b)->previous->next = (*b)->next;
	(*b)->next->previous = (*b)->previous;
	(*b) = (*b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_medianquartile **data)
{
	t_stack	*temp;

	if (add_to_list(b, (*a)->value) == -1)
	{
		free_stacks(a, b, data);
		exit(1);
	}
	temp = (*a);
	(*a)->previous->next = (*a)->next;
	(*a)->next->previous = (*a)->previous;
	(*a) = (*a)->next;
	free(temp);
	write(1, "pb\n", 3);
}

void	sa(t_stack **a)
{
	int	temp;

	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	temp;

 	temp = (*b)->value;
 	(*b)->value = (*b)->next->value;
 	(*b)->next->value = temp;
 	write(1, "sb\n", 3);
}

void	ra(t_stack **a, int print)
{
	if (*a && (*a)->next != *a)
	{
		*a = (*a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b, int print)
{
	if (*b && (*b)->next != *b)
	{
		*b = (*b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **p_a, t_stack **p_b)
{
	if (*p_a && (*p_a)->next != *p_a && *p_b && (*p_b)->next != *p_b)
	{
		ra(p_a, 0);
		rb(p_b, 0);
		write(1, "rr\n", 3);
	}
}

void	rra(t_stack **a, int print)
{
	if (*a && (*a)->previous != *a)
	{
		*a = (*a)->previous;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, int print)
{
	if (*b && (*b)->previous != *b)
	{
		*b = (*b)->previous;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **p_a, t_stack **p_b)
{
	if (*p_a && (*p_a)->previous != *p_a && *p_b && (*p_b)->previous != *p_b)
	{
		rra(p_a, 0);
		rrb(p_b, 0);
		write(1, "rrr\n", 4);
	}
}

long long	ft_atoi(const char *nptr)
{
	long long		number;
	int				sign;
	int				i;
	char			*str;

	i = 0;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -sign;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - 48);
	return (number * sign);
}

static int	count_number(int number)
{
	int			count;
	long long	n;

	count = 1;
	if (number < 0)
	{
		n = -number;
		++count;
	}
	else
		n = number;
	while (n >= 10)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static char	*ft_itoa(long long n)
{
	char		*str;
	int			i;
	long long	t;

	i = count_number(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		t = -n;
	else
		t = n;
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (t % 10) + 48;
		t /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_atoi_and_check(const char *nptr, int *error)
{
	char	*temp;

	if (ft_strlen(nptr) > 11)
	{
		*error = 1;
		return (1);
	}
	temp = ft_itoa(ft_atoi(nptr));
	if (!ft_strcmp(temp, nptr))
	{
		free(temp);
		*error = 1;
		return (1);
	}
	free(temp);
	return ft_atoi(nptr);
}

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*between(char *str, char c, int index)
{
	char	*word;
	int		start;
	int		j;
	int		temp;

	start = index;
	temp = ft_strlen(str);
	while (str[index] != c && index < temp)
		index++;
	if (index == start)
		return (NULL);
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < index)
	{
		word[j] = str[start];
		j++;
		start++;
	}
	word[j] = '\0';
	return (word);
}

static char	**make(char **res, char *s, char c, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j <= len)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = between(s, c, i);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;

	len = count_word((char *)s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res = make(res, (char *)s, c, len);
	return (res);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (src[++i])
		new[i] = src[i];
	new[i] = '\0';
	return (new);
}

void	fill_median_quartile(t_medianquartile **data, int len, int array[])
{
	if (len % 2 == 0)
		(*data)->median = len / 2;
	(*data)->first_quart = (((*data)->median) + 1) / 2;
	if ((*data)->median % 2 == 0)
		(*data)->first_quart = ((*data)->median) / 2;
	(*data)->second_quart = ((*data)->median) + ((*data)->first_quart);
	if (len > 5)
	{
		(*data)->first_quart = array[(*data)->first_quart];
		(*data)->second_quart = array[(*data)->second_quart];
	}
	else
	{
		(*data)->first_quart = 0;
		(*data)->second_quart = 0;
	}
}

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

static void	duplicates_and_finish(int array[], int len, t_medianquartile **data)
{
	int	i;
	int	temp;
	int	l;

	i = 0;
	temp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == temp)
			l = 0;
		temp = array[i];
	}
	(*data)->len = len;
	if (!l)
		(*data)->len = l;
	(*data)->median = (len + 1) / 2;
	fill_median_quartile(data, len, array);
}

void	find_median_quartile(char **spl, t_medianquartile **data, int *error)
{
	int		len;
	int		i;
	int		*tab;

	len = 0;
	while (spl[len] && spl != NULL)
		++len;
	tab = malloc(sizeof(int) * len);
	if (!tab || !spl)
	{
		(*data) = NULL;
		return ;
	}
	i = len;
	while (--i != -1)
	{
		tab[i] = ft_atoi_and_check(spl[i], error);
		free(spl[i]);
	}
	free(spl);
	quick_sort(tab, 0, len - 1);
	duplicates_and_finish(tab, len, data);
	(*data)->median = tab[((*data)->median) - 1];
	free(tab);
}

static int	count_move(t_stack *a, t_stack *b, int element)
{
	int	count;
	int	index;

	index = find_index(b, element);
	count = 1;
	if (index > 1 && index > (len(b) / 2))
		count += len(b) - index - 1;
	else if (index > 1 && index <= (len(b) / 2))
		count += index - 1;
	index = find_insertion_position(a, element);
	if (index > 1 && index > (len(a) / 2))
		count += len(a) - index - 1;
	else if (index > 1 && index <= (len(a) / 2))
		count += index - 1;
	return (count);
}

int	find_best_move(t_stack *a, t_stack *b)
{
	int		best_move_element;
	int		move_count;
	int		best_move_count;
	t_stack	*temp;

	best_move_element = b->value;
	best_move_count = count_move(a, b, best_move_element);
	temp = b->next;
	while (temp != b && temp != NULL)
	{
		move_count = count_move(a, b, temp->value);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_element = temp->value;
		}
		temp = temp->next;
	}
	return (best_move_element);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	length;

	length = len(stack);
	if (length > 0)
	{
		i = 1;
		while (i++ < length)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}

int	is_value_in_range(t_stack *stack, int first_quart, int second_quart)
{
	t_stack	*temp;
	int		length;
	int		i;

	length = len(stack);
	i = 0;
	temp = stack;
	while (i < length)
	{
		if (first_quart <= temp->value && temp->value <= second_quart)
			return (1);
		temp = temp->next;
		++i;
	}
	return (0);
}

void	replace_stack(t_stack **stack)
{
	int		m;
	int		index;
	t_stack	*a;

	a = *stack;
	m = find_minimum(a);
	if (a->value != m)
	{
		index = find_index(a, m);
		if (index <= len(a) / 2)
			while (a->value != m)
				ra(&a, 1);
		else
			while (a->value != m)
				rra(&a, 1);
	}
	(*stack) = a;
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->previous->value;
	if ((first < second) && (second > third) && (first < third))
	{
		rra(a, 1);
		sa(a);
	}
	else if ((first < second) && (second > third) && (first > third))
		rra(a, 1);
	else if ((first > second) && (second < third) && (first > third))
		ra(a, 1);
	else if ((first > second) && (second > third))
	{
		sa(a);
		rra(a, 1);
	}
	else
		sa(a);
}

static
int	optimize_check(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = len(*a);
	length_b = len(*b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			rr(a, b);
			i++;
		}
	}
	if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			rrr(a, b);
			i++;
		}
	}
	return (i);
}

static t_stack	*rr_and_rra(t_stack *a, int pos_a, int i)
{
	if (pos_a <= (len(a) / 2))
	{
		while (i <= pos_a - 1)
		{
			ra(&a, 1);
			++i;
		}
	}
	else
	{
		while (i < (len(a) - pos_a))
		{
			rra(&a, 1);
			++i;
		}
	}
	return (a);
}

void	insertion_sort(t_stack **p_a, t_stack **p_b, int b_move, t_medianquartile **data)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = find_insertion_position((*p_a), b_move);
	pos_b = find_index((*p_b), b_move);
	i = optimize_check(p_a, p_b, pos_a, pos_b);
	while ((*p_b)->value != b_move)
	{
		if (pos_b <= (len((*p_b)) / 2))
			rb(p_b, 1);
		else
			rrb(p_b, 1);
	}
	(*p_a) = rr_and_rra((*p_a), pos_a, i);
	pa(p_a, p_b, data);
}

void	optimize_pb(t_stack *a, t_stack *b, t_medianquartile *data)
{
	while (is_value_in_range(a, data->first_quart, data->second_quart) && data->len >= 8)
	{
		if (a->value >= data->first_quart && a->value <= data->median)
		{
			pb(&a, &b, &data);
			rb(&b, 1);
			continue ;
		}
		if (a->value <= data->second_quart && a->value >= data->median)
		{
			pb(&a, &b, &data);
			continue ;
		}
		else
			ra(&a, 1);
	}
	while (len(a) > 3)
	{
		pb(&a, &b, &data);
		if (b->value < data->median)
			rb(&b, 1);
	}
	if (!(is_sorted(a)))
		sort_three(&a);
	optimize_pa(a, b, data);
}

void	optimize_pa(t_stack *a, t_stack *b, t_medianquartile *data)
{
	data->len -= 3;
	while (data->len)
	{
		insertion_sort(&a, &b, find_best_move(a, b), &data);
		data->len--;
	}
	replace_stack(&a);
	b = NULL;
	free_stacks(&a, &b, &data);
	exit(1);
}

static int	initialize_stack(t_stack **a, t_stack **b, char **spl)
{
	int	i;
	int	t;

	i = 0;
	*a = NULL;
	*b = NULL;
	if (!spl)
		return (-1);
	while (spl[i])
		i++;
	while (--i >= 0)
	{
		t = add_to_list(a, ft_atoi(spl[i]));
		if (t == -1)
			return (-1);
		free(spl[i]);
	}
	free(spl);
	return (1);
}

static int	split_len(char **spl)
{
	int	i;

	i = -1;
	if (!spl)
		return (-1);
	while (spl[++i])
		free(spl[i]);
	free(spl);
	return (i);
}

static char	**find_useful_args(int ac, char **av)
{
	int		i;
	char	**split;

	if (ac > 2)
	{
		i = 0;
		split = malloc(sizeof(char *) * ac);
		while (++i < ac)
		{
			if (split_len(ft_split(av[i], ' ')) != 1 || !split)
			{
				i++;
				while (--i != 0 || split != NULL)
					free(split[i]);
				free(split);
				return (NULL);
			}
			split[i - 1] = ft_strdup(av[i]);
		}
		split[ac - 1] = NULL;
		return (split);
	}
	if (ac == 2)
		return (ft_split(av[1], ' '));
	return (NULL);
}

static void	push_swap(t_stack *a, t_stack *b, t_medianquartile *data)
{
	if (data->len == 2)
		if (a->value > a->next->value)
			write(1, "sa\n", 3);
	if (data->len > 2)
		if (!is_sorted(a))
			optimize_pb(a, b, data);
	free_stacks(&a, &b, &data);
	exit(1);
}

int	main(int ac, char **av)
{
	t_medianquartile	*data;
	int		error;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		exit(1);
	data = malloc(sizeof(t_medianquartile));
	if (!data)
		return (1);
	error = 0;
	find_median_quartile(find_useful_args(ac, av), &data, &error);
	if (error || data->len == 0 || !data)
	{
		write(2, "Error\n", 6);
		if (data)
			free(data);
		return (1);
	}
	if (initialize_stack(&a, &b, find_useful_args(ac, av)) == 1)
		push_swap(a, b, data);
	free_stack(&a);
	free(data);
	return (0);
}
