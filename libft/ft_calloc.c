/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:28 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:04:38 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * alloue de la memoire et l'initialise a 0
 * si count ou size sont nuls, ils sont definis a 1 pour eviter 
 * une division par 0.
 * ensuite la fonction verifie si count * size est superieur a la taille 
 * maximale pouvant etre allouee. Si oui -> NULL. Si non -> malloc
 * Si la memoire ne peut pas etre allouee -> NULL
 * Enfin on utilise ft_memset pour initialiser cette memoire a 0.
 * La fonction renvoie le pointeur sur la memoire allouee et initialisee.
 *
 *****************************************************************************/
void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > (count * size) / size)
		return (NULL);
	pnt = malloc(count * size);
	if (pnt == NULL)
		return (NULL);
	ft_memset((unsigned char *)pnt, 0, count * size);
	return (pnt);
}
