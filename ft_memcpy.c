/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:53:16 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:05:22 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Copie n octets de src vers dest
 * Utilise 2 pointeurs pour parcourir src et dest
 * Utilise une boucle pour copier les octets 1 par 1. A chaque iteration elle 
 * copie la valeur pointee par new_src et new_dest. Incremente les 2 pointeurs
 * Renvoie l'adresse de la zone memoire de destination
 *
 *****************************************************************************/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*new_dest++ = *new_src++;
	return (dest);
}
