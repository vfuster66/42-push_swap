/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:19:52 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:08:02 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Compare les n 1ers octets des zones memoire s1 et s2
 * Retourne 0 si les 2 zones sont identiques
 * Retourne un nombre neg si s1 < s2
 * Retourne un nompre pos si s1 > s2
 * 
 *****************************************************************************/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*sone;
	unsigned char		*stwo;

	if (s1 == s2 || n == 0)
		return (0);
	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	while (n--)
	{
		if (*sone != *stwo)
			return (*sone - *stwo);
		if (n)
		{
			sone++;
			stwo++;
		}
	}
	return (0);
}
