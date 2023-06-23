/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:19:42 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:08:46 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Duplique une chaine de caracteres
 * Alloue de la memoire pour une nouvelle chaine de caracteres de la 
 * meme longueur que s + \0 (ft_strlen)
 * Si l'allocation echoue -> NULL
 * Boucle utilisee pour copier les caracteres de s dans str. Boucle terminee
 * lorsqu'elle rencontre \0 de s
 * Ajoute \0 a la fin de la nouvelle chaine
 * Renvoie un pointeur vers le debut de la nouvelle chaine
 *
 *****************************************************************************/
char	*ft_strdup(char const *s)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[n])
	{
		str[n] = s[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
