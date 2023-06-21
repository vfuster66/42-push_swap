/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:22:56 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:06:11 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
 *
 * Parcourt une liste chainee en executant une fonction sur chaque element 
 * de la liste et en renvoyant une nouvelle liste chainee avec les 
 * nouveaux elements retournes par f
 * Verifie si lst et f et del sont non nuls. Si l'un d'entre eux est nul
 * la fonction renvoie NULL
 * Cree une nouvelle liste out en utilisant ft_lstnew avec le 1er arg nul
 * Si out ne peut pas etre cree -> NULL
 * Definit elem = out puis boucle chaque element de lst et traite chaque
 * element avec f
 * Si element suivant existe cree un nouvel element en utilisant ft_lstnew
 * avec le 1er arg nul. Si ne peut pas etre cree ft_lstclear detruit out et
 * renvoie NULL
 * Si elem suivant n'existe pas, passe au prochain element de la liste
 * Renvoie la nouvelle liste out une fois tous les elements traites
 *
 *****************************************************************************/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*out;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	out = ft_lstnew(NULL);
	if (!out)
		return (NULL);
	elem = out;
	while (lst)
	{
		elem->content = (*f)(lst->content);
		if (lst->next)
		{
			elem->next = ft_lstnew(NULL);
			if (!elem->next)
			{
				ft_lstclear(&out, del);
				return (NULL);
			}
			elem = elem->next;
		}
		lst = lst->next;
	}
	return (out);
}
