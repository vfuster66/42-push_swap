/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:53 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:00:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Ajoute un nouvel element en tete d'une liste chainee
 * Prend en entree un pointeur sur pointeur t_list (adresse du pointeur
 * sur le 1er element de la liste chainee) et un pointeur t_list
 * pour le nouvel element a ajouter
 * Si la liste chainee existe deja la fonction definit le champ next du 
 * nouvel element pour pointer sur le 1er element de la liste existante
 * Ensuite elle definit *lst pour pointer sur le nouvel element ce qui 
 * l'ajoute en tete de la liste existante
 * Si la liste chainee n'existe pas encore, la fonction ne fait rien
 *
 *****************************************************************************/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
