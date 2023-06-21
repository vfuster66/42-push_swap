/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:10:13 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/09 17:13:59 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/***************************************************************************
 * 
 * Prend un caractère en argument et utilise la fonction système write() pour 
 * l'imprimer sur la sortie standard. Elle renvoie le nombre de caractères 
 * imprimés, qui est généralement 1 pour un seul caractère.
 * 
 ****************************************************************************/
int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

/***************************************************************************
 * 
 * imprime un caractère unique dans un format spécifié en utilisant les 
 * drapeaux spécifiés dans une structure t_flag. Elle prend en compte 
 * l'alignement à gauche ou à droite, la largeur de champ et le caractère 
 * de remplissage. Elle utilise la fonction ft_print_c pour imprimer le 
 * caractère et la fonction ft_width pour ajouter des caractères de 
 * remplissage si nécessaire. La fonction renvoie le nombre total de 
 * caractères imprimés.
 * 
 ****************************************************************************/
int	ft_print_char(char c, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.left == 1)
		count += ft_print_c(c);
	count += ft_width(flag.width, 1, flag.zero);
	if (flag.left == 0)
		count += ft_print_c(c);
	return (count);
}
