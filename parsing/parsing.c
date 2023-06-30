/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:28:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 11:39:06 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	validate_atoi_input(char *nptr)
{
	long	number;
	int		sign;
	size_t	i;

	i = 0;
	number = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] == '0' && nptr[i + 1] != '\0')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10;
		number += nptr[i] - '0';
		if (number > 2147483647 || number * sign < -2147483648)
			return (2);
		i++;
	}
	return (nptr[i] != '\0' || !i);
}

static int	handle_parsing_error(char *arg, int value,
	t_node *last_node, int index)
{
	if (validate_atoi_input(arg) >= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_node == NULL)
		return (1);
	else if (last_node->value == value)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (handle_parsing_error(arg, value, last_node->previous, index));
}

static void process_token(char *token, t_node **head, t_node **last_node, int *index)
{
    int new_value;

	new_value = ft_atoi(token);
    if (handle_parsing_error(token, new_value, *last_node, *index))
    {
        free_node(head);
        return;
    }
    if (*head == NULL)
    {
        *last_node = create_node(new_value, *index, NULL);
        *head = *last_node;
    }
    else
    {
        (*last_node)->next = create_node(new_value, *index, *last_node);
        *last_node = (*last_node)->next;
    }
    *index += 1;
}

t_node *parsing(int index, int ac, char **av, t_node *head)
{
	char	*str;
	char	*token;
    t_node *last_node = NULL;

    while ((index + 1) < ac)
    {
        str = ft_strdup(av[index + 1]);
        if (str == NULL)
            return NULL;
        token = ft_strtok(str, " ");
        while (token != NULL)
        {
            process_token(token, &head, &last_node, &index);
            token = ft_strtok(NULL, " ");
        }
        free(str);
    }
    return head;
}
