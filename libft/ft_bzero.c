/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:52 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 08:29:07 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
 *
 *  prend en entree un pointeur s sur un espace memoire et une taille n
 *  en octet
 *  Initialise a 0 n octets de l espace memoire en utilisant un pointeur 
 *  de type unsigned char
 *  La boucle while parcourt l'espace memoire et met a 0 chaque octet 
 *  jusqu'a ce que i atteigne n.
 *
 ****************************************************************************/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}
