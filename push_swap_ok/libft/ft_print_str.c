/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:04:33 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 07:47:18 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction ft_print_string est une fonction statique qui imprime une chaîne 
 * de caractères sur la sortie standard selon les paramètres de format 
 * spécifiés par la structure t_flag donnée en argument.
 * La fonction commence par initialiser une variable count à zéro, qui 
 * représente le nombre de caractères imprimés. Elle vérifie ensuite si la 
 * précision est spécifiée dans flag et si elle est supérieure ou égale à 
 * zéro. Si c'est le cas, elle ajoute au compteur count la largeur de la 
 * précision, qui correspond au nombre de caractères à imprimer, et utilise 
 * la fonction ft_print_s_precision pour imprimer la chaîne de caractères 
 * en fonction de la précision spécifiée. Sinon, la fonction utilise la 
 * longueur de la chaîne de caractères comme précision et utilise la même 
 * fonction pour l'impression.
 * La fonction renvoie ensuite la valeur de count, qui correspond au nombre 
 * total de caractères imprimés.
 * En résumé, cette fonction est utilisée pour imprimer une chaîne de 
 * caractères sur la sortie standard en fonction des paramètres de format 
 * spécifiés. Elle est capable de gérer la précision de la chaîne de 
 * caractères si elle est spécifiée dans la structure t_flag.
 * 
*****************************************************************************/
static int	ft_print_string(const char *str, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.precision >= 0)
	{
		count += ft_width(flag.precision, ft_strlen(str), 0);
		count += ft_print_s_precision(str, flag.precision);
	}
	else
		count += ft_print_s_precision(str, ft_strlen(str));
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_str permet d'afficher une chaîne de caractères (str) 
 * en appliquant les options de formatage passées en paramètre via une 
 * structure t_flag. Elle retourne le nombre de caractères affichés.
 * Tout d'abord, si la chaîne str est nulle (NULL), elle est remplacée 
 * par la chaîne "(null)".
 * Ensuite, si l'option de précision est spécifiée (flag.precision >= 0) et 
 * que sa valeur est inférieure à la longueur de la chaîne str, la valeur de 
 * la précision est ajustée pour être égale à la longueur de la chaîne str.
 * Si l'option d'alignement à gauche est activée (flag.left == 1), la chaîne 
 * est affichée en premier avec les options de précision appliquées, puis on 
 * applique l'option de largeur en ajoutant des caractères d'espacement à 
 * droite si la longueur de la chaîne est inférieure à la largeur spécifiée. 
 * Le nombre de caractères affichés est retourné dans la variable count.
 * Si l'option d'alignement à gauche n'est pas activée (flag.left == 0), on
 * applique d'abord l'option de largeur en ajoutant des caractères 
 * d'espacement à gauche si la longueur de la chaîne est inférieure à la 
 * largeur spécifiée. Ensuite, la chaîne est affichée avec les options de 
 * précision appliquées, et le nombre de caractères affichés est ajouté à 
 * count.
 * Enfin, count est retourné comme nombre total de caractères affichés.
 * 
*****************************************************************************/
int	ft_print_str(const char *str, t_flag flag)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flag.precision >= 0 && (size_t)flag.precision > ft_strlen(str))
		flag.precision = ft_strlen(str);
	if (flag.left == 1)
		count += ft_print_string(str, flag);
	if (flag.precision >= 0)
		count += ft_width(flag.width, flag.precision, 0);
	else
		count += ft_width(flag.width, ft_strlen(str), 0);
	if (flag.left == 0)
		count += ft_print_string(str, flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_s_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_s_precision permet d'afficher une chaîne de caractères 
 * en respectant une certaine précision. Elle prend en paramètre un pointeur 
 * vers la chaîne de caractères à afficher str et un entier precision qui 
 * représente la précision souhaitée.
 * La fonction commence par initialiser un compteur count à 0. Ensuite, 
 * elle parcourt la chaîne de caractères str en affichant chaque caractère 
 * à l'aide de la fonction write jusqu'à ce que la fin de la chaîne soit 
 * atteinte ou que le compteur atteigne la valeur de la précision souhaitée.
 * La fonction retourne le nombre de caractères affichés.
 * 
*****************************************************************************/
int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
