/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:45:54 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 07:54:40 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction ft_print_i prend en paramètre une chaîne de caractères nbstr,
 * un entier n et une structure t_flag qui contient des informations sur les
 * options de formatage.
 * La fonction commence par initialiser un compteur count à zéro. Ensuite,
 * elle teste si n est inférieur à zéro. Si c'est le cas, et si l'option
 * flag.zero est égale à zéro ou si la précision est supérieure ou égale à
 * zéro, la fonction appelle ft_print_c pour afficher le signe moins (-) et
 * ajoute le nombre de caractères affichés au compteur count.
 * Si n est supérieur ou égal à zéro, la fonction teste si l'option flag.plus
 * est égale à 1 et flag.zero est égale à zéro. Si c'est le cas, elle appelle
 * ft_print_c pour afficher le signe plus (+) et ajoute le nombre de
 * caractères affichés au compteur count.
 * Si flag.plus est égal à zéro et que l'option flag.space est égale à 1 et
 * flag.zero est égale à zéro, la fonction appelle ft_print_c pour afficher un
 * espace et ajoute le nombre de caractères affichés au compteur count.
 * Ensuite, la fonction teste si la précision est supérieure ou égale à zéro.
 * Si c'est le cas, elle appelle ft_width pour afficher un champ de largeur
 * flag.precision - 1 moins la longueur de la chaîne de caractères nbstr moins
 * un et ajoute le nombre de caractères affichés au compteur count.
 * Enfin, la fonction appelle ft_print_s pour afficher la chaîne de
 * caractères nbstr et ajoute le nombre de caractères affichés au compteur
 * count. Elle retourne ensuite la valeur de count.
 *
 *****************************************************************************/
int	ft_print_i(char *nbstr, int n, t_flag flag)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flag.zero == 0 || flag.precision >= 0)
			count += ft_print_c('-');
	}
	else if (flag.plus == 1 && flag.zero == 0)
		count += ft_print_c('+');
	else if (flag.space == 1 && flag.zero == 0)
		count += ft_print_c(' ');
	if (flag.precision >= 0)
		count += ft_width(flag.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_sign_precision permet d'imprimer le signe (+ ou -)
 * ou l'espace d'un nombre entier en fonction des flags spécifiés dans la
 * structure t_flag, ainsi que de gérer la précision.
 * La fonction prend en paramètre un entier n et un pointeur vers une
 * structure t_flag qui contient les différents flags et spécifications
 * de format pour l'impression du nombre. Elle renvoie un entier qui
 * représente le nombre de caractères imprimés.
 * Tout d'abord, la fonction vérifie si n est inférieur à zéro, ce qui
 * signifie qu'il s'agit d'un nombre négatif. Si c'est le cas et que la
 * précision n'a pas été spécifiée, la fonction imprime un signe moins
 * ("-") et décrémente la largeur d'un caractère. Si n est supérieur ou
 * égal à zéro ou que la précision est spécifiée, la fonction ne fait rien.
 * Ensuite, si le flag plus est activé, la fonction imprime un signe plus
 * ("+") et incrémente le compteur de caractères. Si le flag space est activé,
 * la fonction imprime un espace et décrémente la largeur d'un caractère.
 * Enfin, la fonction renvoie le nombre de caractères imprimés.
 *
 *****************************************************************************/
int	ft_print_sign_precision(int n, t_flag *flag)
{
	int	count;

	count = 0;
	if (n < 0 && flag->precision == -1)
	{
		count += ft_print_c('-');
		flag->width--;
	}
	else if (flag->plus == 1)
		count += ft_print_c('+');
	else if (flag->space == 1)
	{
		count += ft_print_c(' ');
		flag->width--;
	}
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_integer prend en argument une chaîne de caractères
 * représentant un entier nbstr, un entier n, et une structure flag de type
 * t_flag qui contient plusieurs drapeaux (zero, left, precision, width, plus,
 * space) utilisés pour formater la sortie.
 * La fonction commence par initialiser le compteur count à 0.
 * Si le drapeau zero est activé, la fonction ft_print_sign_precision est
 * appelée pour imprimer le signe ou le symbole + ou de l'entier, selon les
 * drapeaux plus et space. Le nombre de caractères imprimés par cette fonction
 * est ajouté au compteur count.
 * Si le drapeau left est activé, la fonction ft_print_i est appelée pour
 * imprimer la chaîne nbstr représentant l'entier n dans le format spécifié
 * par les drapeaux. Le nombre de caractères imprimés par cette fonction est
 * ajouté au compteur count.
 * Si le drapeau precision est positif et inférieur à la longueur de nbstr,
 * il est mis à jour pour être égal à la longueur de nbstr.
 * Si le drapeau precision est activé, le drapeau width est ajusté en
 * conséquence et la fonction ft_width est appelée pour imprimer les espaces
 * nécessaires pour atteindre la largeur spécifiée. Le nombre de caractères
 * imprimés par cette fonction est ajouté au compteur count.
 * Si le drapeau precision est désactivé, le drapeau width est ajusté en
 * conséquence et la fonction ft_width est appelée pour imprimer les espaces
 * ou les zéros nécessaires pour atteindre la largeur spécifiée. Le nombre de
 * caractères imprimés par cette fonction est ajouté au compteur count.
 * Si le drapeau left est désactivé, la fonction ft_print_i est appelée pour
 * imprimer la chaîne nbstr représentant l'entier n dans le format spécifié
 * par les drapeaux. Le nombre de caractères imprimés par cette fonction est
 * ajouté au compteur count.
 * Finalement, la fonction retourne le nombre total de caractères imprimés,
 * qui correspond à la valeur de count.
 *
 *****************************************************************************/
int	ft_print_integer(char *nbstr, int n, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 1)
		count += ft_print_sign_precision(n, &flag);
	if (flag.left == 1)
		count += ft_print_i(nbstr, n, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		if (n < 0 && flag.left == 0)
			flag.width -= 1;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width - flag.plus - flag.space,
				ft_strlen(nbstr), flag.zero);
	if (flag.left == 0)
		count += ft_print_i(nbstr, n, flag);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_int prend un entier n et une structure de drapeaux 
 * flag en entrée et renvoie le nombre de caractères imprimés.
 * Elle commence par initialiser une variable nb avec la valeur de n, puis 
 * vérifie si nb est négatif. Si c'est le cas, elle le convertit en positif, 
 * car le signe sera traité ultérieurement. Si le drapeau precision est égal 
 * à 0 et que n est égal à 0, la fonction imprime simplement la largeur 
 * spécifiée par le drapeau width et retourne le nombre de caractères imprimés.
 * Ensuite, la fonction convertit nb en chaîne de caractères à l'aide de la 
 * fonction ft_print_itoa, stocke le résultat dans nbstr, puis appelle la 
 * fonction ft_print_integer pour imprimer la chaîne avec les drapeaux 
 * spécifiés dans flag. Le nombre de caractères imprimés est stocké dans 
 * la variable count, qui est renvoyée à la fin de la fonction.
 * La fonction ft_print_integer traite l'impression de la chaîne de 
 * caractères nbstr selon les drapeaux spécifiés dans flag. Si le drapeau 
 * zero est activé, la fonction appelle ft_print_sign_precision pour 
 * imprimer le signe du nombre ou le préfixe "0x" dans le cas d'un nombre 
 * hexadécimal. Si le drapeau left est activé, la fonction appelle ft_print_i 
 * pour imprimer la chaîne nbstr et les éventuels signes, et ajoute le nombre 
 * de caractères imprimés à la variable count. Si le drapeau precision est 
 * défini, la fonction ajuste la largeur de champ en fonction de la précision 
 * et de la longueur de nbstr. Si n est négatif et que le drapeau left n'est 
 * pas activé, la fonction ajuste la largeur de champ pour inclure le signe.
 * Enfin, la fonction appelle ft_print_i pour imprimer la chaîne nbstr et 
 * les signes éventuels si le drapeau left n'est pas activé, et ajoute le 
 * nombre de caractères imprimés à count. En fin de compte, la fonction 
 * renvoie count.
 *
 *****************************************************************************/
int	ft_print_int(int n, t_flag flag)
{
	char	*nbstr;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (flag.zero == 0)
			flag.width--;
	}
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_itoa(nb);
	if (!nbstr)
		return (0);
	count += ft_print_integer(nbstr, n, flag);
	free(nbstr);
	return (count);
}
