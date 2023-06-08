/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:04:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/08 09:19:35 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_duplicate(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = i + 1;
    while (i < ac - 1)
    {
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
            {
                return (1);
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    return (0);
}

int has_non_numeric_chars(int ac, char **av)
{
    int i;
    int len;
    int j;

    i = 1;
    while (i < ac)
    {
        len = ft_strlen(av[i]);
        j = 0;
        while (j < len)
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int check_int_max(char *str)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	if (str[index] == '-')
		index++;
	while (str[index])
	{
		if (num > INT_MAX / 10 || num < INT_MIN / 10)
			return (1);
		num = num * 10 + (str[index] - '0');
			index++;
	}
	return (0);
}

int is_out_of_range(int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        if (check_int_max(av[i]))
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int check_arguments(int ac, char **av)
{
    if (is_duplicate(ac, av) || has_non_numeric_chars(ac, av) || is_out_of_range(ac, av))
    {
        return (1);
    }
    return (0);
}
