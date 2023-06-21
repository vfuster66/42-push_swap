/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:17:38 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:56:39 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction a pour but d'imprimer un nombre de caractères suffisant pour 
 * atteindre une largeur totale total_width. Le nombre de caractères actuel 
 * est donné par size. Elle retourne un entier qui représente le nombre de 
 * caractères imprimés.
 * 
*****************************************************************************/

/****************************************************************************
 *
 * La fonction utilise une boucle while pour imprimer des caractères 
 * supplémentaires jusqu'à ce que la largeur totale soit atteinte. Elle 
 * compare la différence entre la largeur totale et le nombre de caractères 
 * actuel à zéro pour déterminer le nombre de caractères supplémentaires à 
 * imprimer.
 * Si zero est vrai, la fonction imprime des zéros (0) à la place des espaces, 
 * sinon elle imprime des espaces.
 * À chaque itération de la boucle, la fonction diminue la largeur totale de 1
 * et incrémente le compteur count du nombre de caractères imprimés. Une fois 
 * que la largeur totale a été atteinte, la fonction retourne le nombre total 
 * de caractères imprimés.
 * 
*****************************************************************************/
int	ft_width(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_print_c('0');
		else
			count += ft_print_c(' ');
		total_width--;
	}
	return (count);
}
