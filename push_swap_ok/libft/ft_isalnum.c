/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:51:59 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 08:59:19 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Prend en entree un entier c representant un caractere ASCII
 * Renvoie 1 si le caractere est une lettre (ft_isalpha) 
 * ou un chiffre (ft_isdigit). Renvoie 0 dans le cas contraire
 *
 *****************************************************************************/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
