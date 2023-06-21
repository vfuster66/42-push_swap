/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:28:36 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 14:14:36 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * Les fonctions servent à initialiser et à manipuler une structure de données
 *  appelée "t_flag", qui stocke les informations de formatage pour chaque 
 * conversion. 
 * 
*****************************************************************************/

/****************************************************************************
 * 
 * Initialise une structure de type t_flag, qui contient des drapeaux qui 
 * indiquent le type de spécificateur de formatage, la largeur de champ, 
 * le caractère de remplissage, l'alignement à gauche ou à droite, 
 * la précision, etc. Les drapeaux sont initialisés à 0 ou à une valeur par
 * défaut appropriée.
 * 
*****************************************************************************/
t_flag	ft_flag_initialize(void)
{
	t_flag	flag;

	flag.specifier = 0;
	flag.width = 0;
	flag.left = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.precision = -1;
	flag.hash = 0;
	flag.space = 0;
	flag.plus = 0;
	return (flag);
}

/****************************************************************************
 * 
 * Modifie le drapeau "left" d'une structure t_flag en le mettant à 1, ce qui
 * signifie que le texte sera aligné à gauche lors de la mise en forme. Elle 
 * met également le drapeau "zero" à 0, ce qui signifie que le caractère de 
 * remplissage sera un espace et non un zéro.
 * 
*****************************************************************************/
t_flag	ft_flag_left(t_flag flag)
{
	flag.left = 1;
	flag.zero = 0;
	return (flag);
}

/****************************************************************************
 * 
 * Ajoute un chiffre au champ de largeur en cours de construction dans la 
 * structure t_flag. Elle multiplie d'abord la largeur actuelle par 10 pour 
 * décaler les chiffres à gauche, puis ajoute le nouveau chiffre à droite en 
 * le soustrayant du caractère '0'.
 * 
*****************************************************************************/
t_flag	ft_flag_digit(char c, t_flag flag)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = (flag.width * 10) + (c - '0');
	return (flag);
}

/****************************************************************************
 * 
 * Modifie la largeur de champ d'une structure t_flag en utilisant une valeur 
 * fournie en argument variable. Elle met également le drapeau "star" à 1, ce 
 * qui signifie que la largeur de champ est fournie sous forme d'argument 
 * variable et non sous forme de chiffre directement dans le format.
 * 
*****************************************************************************/
t_flag	ft_flag_width(va_list args, t_flag flag)
{
	flag.star = 1;
	flag.width = va_arg(args, int);
	if (flag.width < 0)
	{
		flag.left = 1;
		flag.width *= -1;
	}
	return (flag);
}

/****************************************************************************
 * 
 * Extrait la précision à partir de la chaîne de formatage et la stocke dans 
 * la structure t_flag. Elle peut être fournie soit sous forme de chiffre 
 * directement dans le format, soit sous forme d'argument variable. La 
 * fonction renvoie la position de la chaîne de formatage juste après le 
 * dernier chiffre de la précision extraite. Si la précision n'est pas 
 * spécifiée dans le format, le drapeau "precision" de la structure t_flag 
 * est mis à 0.
 * 
*****************************************************************************/
int	ft_flag_precision(const char *str, int pos, va_list args, t_flag *flag)
{
	int	i;

	i = pos + 1;
	if (str[i] == '*')
	{
		flag->precision = va_arg(args, int);
		return (i++);
	}
	flag->precision = 0;
	while (ft_isdigit(str[i]))
	{
		flag->precision = (flag->precision * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}
