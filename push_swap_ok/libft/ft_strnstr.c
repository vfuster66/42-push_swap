/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:41:19 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:01:27 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Cherche la 1ere occurence d'une chaine little dans une autre chaine big
 * Double boucle pour comparer les caracteres des 2 boucles
 * 1ere boucle (i) parcourt les len 1ers caracteres de big
 * 2eme boucle (j) compare les caracteres de little avec les caracteres
 * correspondant a big
 * Si un caractere ne correspond pas la 2eme boucle s'arrete et la 1ere
 * boucle passe au prochain caractere de big
 * Si tous les caracteres de little correspondent la fonction renvoie
 * un pointeur vers le 1er caractere correspondant dans big
 *
 *****************************************************************************/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (0);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				j++;
				if (!little[j])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
