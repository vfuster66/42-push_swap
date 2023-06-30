/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:28:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/30 17:01:34 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//convertit une str en int, gere les signes +/- et verifie les
//depassements de capacite
static int	atoi_check(char *nptr)
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

//Verifie si le nombre est valide et s'il y a des doublons
static int	handle_parsing_error(char *arg, int val,
	t_node *last_node, int index)
{
	if (atoi_check(arg) >= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_node == NULL)
		return (1);
	else if (last_node->value == val)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (handle_parsing_error(arg, val, last_node->previous, index));
}

//cree un nouveau noeud a partir d'une struct t_arg_manager et de l'index
t_node	*create_and_link_node(t_arg_manager *manager, int index, t_node **head)
{
	t_node	*new_node;

	new_node = create_node(manager->new_value, index, manager->last_node);
	if (!new_node)
		return (NULL);
	if (manager->last_node)
		manager->last_node->next = new_node;
	else
		*head = new_node;
	return (new_node);
}

//Checke les arguments de la ligne de commande a partir de l'index
//Separe les chaines en tokens separes par des espaces avec ft_strtok
//puis les convertit en int avec ft_atoi
t_node	*parsing(int index, int ac, char **av, t_node *head)
{
	t_arg_manager	manager;

	manager.last_node = NULL;
	while ((index + 1) < ac)
	{
		manager.str = ft_strdup(av[index + 1]);
		if (manager.str == NULL)
			return (NULL);
		manager.token = ft_strtok(manager.str, " ");
		while (manager.token != NULL)
		{
			manager.new_value = ft_atoi(manager.token);
			if (handle_parsing_error(manager.token,
					manager.new_value, manager.last_node, index))
				return (free_node(&head));
			manager.last_node = create_and_link_node(&manager, index, &head);
			if (!manager.last_node)
				return (free_node(&head));
			manager.token = ft_strtok(NULL, " ");
			index++;
		}
		free(manager.str);
	}
	return (head);
}
