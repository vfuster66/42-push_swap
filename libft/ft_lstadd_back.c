/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:44 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:08:38 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Ajoute un nouvel element a la fin d'une liste chainee
 * Prend en entree un pointeur sur un pointeur t_list (adresse du pointeur
 * sur le 1er element de la liste chainee) et un pointeur t_list pour
 * le nouvel element a ajouter
 * Si la liste existe la fonction definit un pointeur elem pour pointer
 * sur le dernier element de la liste existante. Elle definit ensuite next
 * du dernier element pour pointer sur le nouvel element ce qui ajoute ce 
 * nouvel element a la fin de la liste
 * Si la liste n'existe pas encore, la fonction definit *lst pour pointer
 * sur le nouvel elememt 
 * ce qui cree une nouvelle liste avec ce seul element
 *
 *****************************************************************************/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst != NULL && *lst != NULL)
	{
		elem = *lst;
		elem = ft_lstlast(*lst);
		elem->next = new;
		return ;
	}
	*lst = new;
}
