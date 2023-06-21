/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:57:11 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:07:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Concatene 2 chaines de caracteres
 * Verifie si src est vde ou si la taille est nulle -> longueur de src
 * Calcule la longueur de dst en parcourantles caracteres jusqu'a la fin
 * de dst ou size
 * Copie tout ou partie de src a la fin de dst en veillant a ne pas 
 * depasser size de la memoire allouee pour dst
 * Retourne la longueur totale de la chaine obtenue
 *
 *****************************************************************************/
size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!src || !size)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = i;
	while (src[i - j] && i < size - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
