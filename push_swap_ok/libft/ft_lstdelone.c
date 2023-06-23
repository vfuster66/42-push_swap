/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:15:54 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:05:11 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Permet de supprimer un element d'une liste chainee 
 * lst = pointeur sur element a supprimer
 * del = fonction appelee pour liberer la memoire associee a l'element
 * La fonction appelle del avec le pointeur sur le contenu de l'element
 * afin de liberer la memoire associee au contenu
 * Ensuite la fonction libere la memoire associe a l'element lui-meme
 * Enfin l'element est mis a NULL pour eviter les fuites memoire
 *
 *****************************************************************************/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
