/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:03:48 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:01:45 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Definit un pointeur last sur le debut de s. 
 * Convertit l'entier c en caractere find
 * Calcule la longueur de s
 * Boucle pour parcourir s de la fin vers le debut 
 * Si last[i] correspond a find retourne un pointeur  sur la position
 * actuelle dans s. Sinon decremente i a chaque boucle
 * Si c a la premiere position de s, retourne last. Sinon retourne 0 si
 * c n'a pas ete trouve
 * 
 *****************************************************************************/
char	*ft_strrchr(char const *s, int c)
{
	char	*last;
	char	find;
	int		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (0);
}
