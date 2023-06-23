/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:15:09 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:07:29 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Efface tous les elements d'une liste chainee
 * Prend en entree un pointeur sur un pointeur t_list 
 * (adresse du pointeur sur le 1er element de la liste chainee)
 * et un pointeur sur une fonction del
 * Si la liste chainee existe la fonction definit une variable tmp
 * pour stocker le prochain element de la liste, puis appelle la 
 * fonction del pour liberer le contenu de l'element actuel
 * Repete le processus pour chaque element de la liste 
 * Enfin la fonction definit *lst a NULL pour indiquer que la liste
 * est vide.
 * Si la liste chainee n'existe pas , la fonction ne fait rien
 *
 *****************************************************************************/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		del(start->content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
