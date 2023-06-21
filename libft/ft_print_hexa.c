/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:44:27 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/09 17:19:23 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * Utilisée pour imprimer le préfixe "0x" ou "0X" pour les nombres 
 * hexadécimaux. Elle prend un argument is_upper qui indique si la lettre "X"
 * doit être en majuscule ou en minuscule. En fonction de la valeur de 
 * is_upper, la fonction imprime soit "0x" soit "0X" en utilisant la fonction 
 * ft_print_s qui imprime une chaîne de caractères.
 * 
*****************************************************************************/
int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_s("0X");
	else
		ft_print_s("0x");
	return (2);
}

/****************************************************************************
 *
 * Utilisée pour imprimer un nombre hexadécimal sous forme de chaîne de 
 * caractères. Elle prend en entrée la chaîne de caractères représentant le 
 * nombre hexadécimal, la longueur de cette chaîne, un drapeau is_upper qui 
 * indique si les lettres doivent être en majuscule ou en minuscule, et un 
 * drapeau flag qui contient les informations de formatage. La fonction 
 * commence par vérifier si le drapeau flag indique que le préfixe "0x" ou 
 * "0X" doit être imprimé en utilisant la fonction ft_print_x_prefix si 
 * nécessaire. Ensuite, si le drapeau flag indique une précision (nombre 
 * de chiffres à imprimer), la fonction utilise la fonction ft_width pour 
 * imprimer les espaces nécessaires pour aligner la chaîne de caractères. 
 * Enfin, la fonction imprime la chaîne de caractères elle-même en utilisant 
 * la fonction ft_print_s.
 * 
*****************************************************************************/
int	ft_print_x(char *nbstr, int n, int is_upper, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 0 && flag.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flag.precision >= 0)
		count += ft_width(flag.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

/****************************************************************************
 *
 * La fonction commence par initialiser une variable count à 0. Cette variable 
 * sera utilisée pour compter le nombre de caractères qui seront affichés à 
 * l'écran.
 * La première partie de la fonction vérifie si l'indicateur flag.zero est non 
 * nul et si l'indicateur flag.hash est non nul et si la longueur du nombre n 
 * est différente de zéro. Si ces conditions sont remplies, la fonction 
 * appelle ft_print_x_prefix(is_upper) pour imprimer le préfixe "0x" ou "0X" 
 * en fonction de la valeur de is_upper. La fonction ft_print_x_prefix est une 
 * autre fonction qui imprime le préfixe "0x" ou "0X" et renvoie le nombre de 
 * caractères imprimés.
 * Ensuite, la fonction vérifie si l'indicateur flag.left est non nul. Si c'est 
 * le cas, la fonction appelle ft_print_x pour afficher la chaîne de caractères 
 * nbstr, en utilisant les indicateurs n, is_upper, et flag comme arguments. La 
 * fonction ft_print_x est une autre fonction qui imprime la chaîne de 
 * caractères nbstr et renvoie le nombre de caractères imprimés.
 * La prochaine partie de la fonction vérifie si l'indicateur flag.precision 
 * est supérieur ou égal à zéro et si la précision spécifiée est inférieure à 
 * la longueur de la chaîne nbstr. Si c'est le cas, la fonction met à jour la 
 * valeur de flag.precision à la longueur de la chaîne nbstr. Cette étape 
 * garantit que la précision spécifiée ne dépasse pas la longueur de la chaîne 
 * nbstr.
 * Ensuite, la fonction vérifie si l'indicateur flag.precision est supérieur 
 * ou égal à zéro. Si c'est le cas, la fonction calcule la largeur nécessaire 
 * en soustrayant la précision flag.precision de la largeur totale flag.width. 
 * Ensuite, la fonction appelle ft_width pour afficher les espaces vides 
 * nécessaires pour atteindre cette largeur totale. La fonction ft_width 
 * calcule le nombre d'espaces nécessaires et renvoie le nombre de caractères 
 * imprimés.
 * Si l'indicateur flag.precision est nul ou négatif, la fonction calcule la 
 * largeur totale nécessaire en ajoutant la longueur de la chaîne nbstr à deux
 * caractères supplémentaires pour le préfixe "0x" ou "0X"
 * 
*****************************************************************************/
int	ft_print_hexadec(char *nbstr, int n, int is_upper, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 1 && flag.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flag.left == 1)
		count += ft_print_x(nbstr, n, is_upper, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width,
				ft_strlen(nbstr) + (flag.hash * 2), flag.zero);
	if (flag.left == 0)
		count += ft_print_x(nbstr, n, is_upper, flag);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_hexa prend en paramètre un entier non signé n, un 
 * booléen is_upper qui indique si l'affichage doit être en majuscules ou en 
 * minuscules et une structure t_flag qui contient des informations sur les 
 * options de formatage.
 * La fonction commence par initialiser un compteur count à zéro. Ensuite, 
 * elle teste si le nombre à afficher n est zéro et que la précision est égale 
 * à zéro. Dans ce cas, la fonction appelle ft_width pour afficher un champ 
 * de largeur flag.width et retourne le nombre de caractères affichés.
 * Si le nombre n est différent de zéro ou que la précision est différente de 
 * zéro, la fonction appelle ft_print_xtoa pour convertir n en une chaîne de 
 * caractères héxadécimale nbstr. Si la conversion échoue, la fonction 
 * retourne zéro.
 * Ensuite, la fonction appelle ft_print_hexadec avec les arguments nbstr, 
 * n, is_upper et flag pour afficher la chaîne de caractères héxadécimale 
 * formatée. La valeur de retour de cette fonction est ajoutée au compteur 
 * count.
 * Enfin, la fonction libère la mémoire allouée à nbstr et retourne le nombre
 * total de caractères affichés.
 * 
*****************************************************************************/
int	ft_print_hexa(unsigned int n, int is_upper, t_flag flag)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_print_hexadec(nbstr, n, is_upper, flag);
	free(nbstr);
	return (count);
}
