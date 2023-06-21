/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:48:40 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:03:00 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Cherche un caractere c dans une chaine de caracteres s
 * Renvoie un pointeur vers la 1ere occurence de c dans s
 * Ou renvoie nul si c non trouve
 * Parcourt s caractere par caractere jusqu'a ce qu'elle trouve c
 * ou qu'elle atteigne la fin de la chaine
 *
 *****************************************************************************/
char	*ft_strchr(char const *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}
