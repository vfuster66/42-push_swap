/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:44:59 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 09:57:35 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*****************************************************************
 * 
 * Fonctions utilisées pour vérifier si un caractère donné est un 
 * caractère de type, un caractère de spécificateur ou un chiffre, 
 * ce qui peut être utile pour l'analyse de chaînes de format C et
 * la manipulation de chaînes de caractères.
 * 
******************************************************************/

/*****************************************************************
 * 
 * prend un entier en entrée et renvoie 1 si l'entier est un caractère de
 * type, de spécificateur ou un chiffre, et 0 sinon. La fonction appelle 
 * deux autres fonctions ft_istype() et ft_isspecifier() pour effectuer 
 * cette vérification.
 *  
*****************************************************************/
int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspecifier(c));
}

/**************************************************************
 * 
 * Cette fonction prend un entier en entrée et renvoie 1 si l'entier
 * est l'un des caractères spécifiques utilisés dans les chaînes de 
 * format C (par exemple, "-", "0", ".", "*", "#", " ", "+") et 0 
 * sinon.
 *  
**************************************************************/
int	ft_isspecifier(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

/************************************************************
 * 
 * Cette fonction prend un entier en entrée et renvoie 1 si l'entier
 * est l'un des caractères de type utilisés dans les chaînes de 
 * format C (par exemple, "c", "s", "d", "i", "u", "x", "X", "p",
 * "%") et 0 sinon.
 *  
**************************************************************/
int	ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}
