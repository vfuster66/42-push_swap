/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:09:44 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 07:51:32 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction ft_print_u permet d'afficher un nombre non signé en base 
 * décimale. Elle prend en entrée une chaîne de caractères représentant le 
 * nombre, et une structure t_flag contenant les informations sur les options 
 * d'affichage.
 * La fonction commence par initialiser le compteur de caractères count à zéro.
 * Ensuite, si une précision a été spécifiée, la fonction ajoute au compteur la
 * largeur nécessaire pour afficher le nombre avec cette précision. Pour cela,
 * elle appelle la fonction ft_width en spécifiant la largeur, qui est la
 * précision moins un (caractère réservé pour le premier chiffre), la longueur
 * de la chaîne de caractères représentant le nombre moins un (caractère 
 * réservé pour le premier chiffre), et un flag indiquant que le nombre est 
 * non signé. 
 * Cette fonction calcule la largeur nécessaire pour afficher le nombre avec\
 * les options spécifiées.
 * Ensuite, la fonction ajoute au compteur la longueur de la chaîne de
 * caractères représentant le nombre en appelant la fonction ft_print_s.
 * Finalement, la fonction renvoie le nombre de caractères affichés.
 * 
*****************************************************************************/

int	ft_print_u(char *nbstr, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.precision >= 0)
		count += ft_width(flag.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_uint prend en entrée une chaîne de caractères nbstr 
 * représentant un nombre non signé et une structure t_flag contenant les 
 * informations de formatage. Elle renvoie le nombre de caractères affichés.
 * Tout d'abord, si le drapeau left est activé, cela signifie que le nombre 
 * doit être aligné à gauche. Dans ce cas, on appelle la fonction ft_print_u 
 * qui va afficher le nombre avec éventuellement la précision souhaitée, puis 
 * on affiche les caractères de remplissage nécessaires à droite pour 
 * atteindre la largeur désirée.
 * Si la précision est définie et est plus petite que la longueur de la 
 * chaîne nbstr, on modifie la précision pour qu'elle corresponde à la 
 * longueur de la chaîne.
 * Ensuite, si la précision est définie, on diminue la largeur d'affichage 
 * de la précision (car la précision est incluse dans la largeur).
 * Enfin, si le drapeau left n'est pas activé, on affiche d'abord les 
 * caractères de remplissage nécessaires pour atteindre la largeur désirée, 
 * puis on appelle ft_print_u pour afficher le nombre.
 * En résumé, cette fonction s'occupe de l'affichage d'un nombre non signé 
 * avec les options de formatage précision, largeur et alignement à 
 * gauche/droite.
 * 
*****************************************************************************/
int	ft_print_uint(char *nbstr, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.left == 1)
		count += ft_print_u(nbstr, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width, ft_strlen(nbstr), flag.zero);
	if (flag.left == 0)
		count += ft_print_u(nbstr, flag);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_unsigned prend en entrée un nombre non signé n et un 
 * flag flag spécifiant les options d'affichage et retourne le nombre de 
 * caractères imprimés.
 * Tout d'abord, la fonction vérifie si le nombre est zéro et si la précision 
 * est zéro, auquel cas elle imprime simplement la largeur et retourne le 
 * nombre de caractères imprimés.
 * Ensuite, la fonction utilise la fonction ft_print_utoa pour convertir 
 * le nombre non signé en une chaîne de caractères contenant sa 
 * représentation décimale. Si la conversion échoue, la fonction retourne 0.
 * La fonction appelle ensuite la fonction ft_print_uint avec la chaîne de 
 * caractères et le flag de formatage pour imprimer le nombre avec les options 
 * spécifiées. Le nombre de caractères imprimés est stocké dans count.
 * Enfin, la fonction libère la mémoire allouée pour la chaîne de caractères 
 * et retourne count.
 * 
*****************************************************************************/
int	ft_print_unsigned(unsigned n, t_flag flag)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_print_uint(nbstr, flag);
	free(nbstr);
	return (count);
}
