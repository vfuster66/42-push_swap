/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:26:58 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 07:39:07 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * Calcule la longueur en chiffres d'un entier num. Elle prend en argument un 
 * nombre entier num de type long et retourne un entier de type size_t qui 
 * correspond à la longueur de num en chiffres.
 * La fonction commence par initialiser une variable len à zéro, qui représente
 * la longueur du nombre en chiffres. Si num est égal à zéro, la fonction 
 * retourne simplement 1 car la longueur de 0 est 1. Si num est négatif, la 
 * fonction incrémente la variable len de 1 car le signe négatif prend un 
 * caractère supplémentaire. Ensuite, elle convertit num en positif en le 
 * multipliant par -1.
 * Ensuite, la fonction parcourt num en divisant successivement par 10 et en 
 * incrémentant len jusqu'à ce que num devienne inférieur à 1. À ce stade, 
 * la fonction retourne len qui représente la longueur de num en chiffres.
 * En résumé, cette fonction est utilisée pour déterminer la longueur en 
 * chiffres d'un nombre entier, ce qui peut être utile pour allouer la 
 * mémoire nécessaire pour stocker le nombre sous forme de chaîne de 
 * caractères.
 * 
*****************************************************************************/
static size_t	ft_ilen(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/****************************************************************************
 *
 * La fonction ft_itostr est une fonction statique qui convertit un nombre 
 * entier num de type long en une chaîne de caractères str de longueur len. 
 * Elle retourne un pointeur sur la chaîne de caractères str.
 * La fonction commence par allouer de la mémoire pour la chaîne de caractères 
 * str à l'aide de la fonction ft_calloc, qui initialise la mémoire allouée à 
 * zéro. Si l'allocation de mémoire échoue, la fonction retourne un pointeur 
 * nul.Ensuite, la fonction vérifie si le nombre num est négatif en comparant 
 * avec zéro. Si c'est le cas, elle ajoute le signe '-' au début de la chaîne 
 * de caractères str, met num en valeur absolue en le multipliant par -1. 
 * Ensuite, elle décrémente len de 1 pour prendre en compte le caractère du 
 * signe moins.
 * Ensuite, la fonction parcourt num à l'aide d'une boucle while qui décrémente 
 * len de 1 à chaque itération jusqu'à ce que len soit égal à zéro. À chaque 
 * itération, elle calcule le chiffre de droite de num à l'aide de l'opération 
 * de modulo 10, ajoute le caractère correspondant à ce chiffre (en ajoutant 
 * '0' pour convertir de l'entier au caractère ASCII) à la position 
 * correspondante dans la chaîne de caractères str, puis divise num par 10 
 * pour supprimer ce chiffre de droite.
 * Enfin, la fonction vérifie si le premier caractère de la chaîne de 
 * caractères str est différent de '-' (pour le cas où num est positif) et, 
 * si c'est le cas, elle ajoute le dernier chiffre de num à la position 0 
 * de la chaîne de caractères str.
 * En résumé, cette fonction est utilisée pour convertir un nombre entier en 
 * une chaîne de caractères. Elle est utilisée dans la fonction f
 * t_print_integer pour convertir un nombre entier en une chaîne de 
 * caractères avant de l'afficher.
 * 
*****************************************************************************/
static char	*ft_itostr(long num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (str[0] != '-')
		str[0] = (num % 10) + '0';
	return (str);
}

/****************************************************************************
 *
 * Utilisée pour convertir un nombre entier de type long en une chaîne de 
 * caractères de type char*. Elle prend en argument le nombre entier à 
 * convertir num et retourne un pointeur vers la chaîne de caractères résultante.
 * La fonction commence par appeler la fonction ft_ilen pour calculer la 
 * longueur de num en chiffres. Cette longueur sera utilisée pour allouer 
 * l'espace mémoire nécessaire pour stocker la chaîne de caractères résultante.
 * Ensuite, la fonction appelle la fonction ft_itostr pour effectuer la 
 * conversion de num en une chaîne de caractères. Cette fonction prend en 
 * argument le nombre entier à convertir num, un pointeur vers une chaîne de 
 * caractères str et la longueur de num en chiffres len. Elle alloue 
 * l'espace mémoire nécessaire pour str en appelant la fonction ft_calloc, 
 * initialise str avec des zéros, puis effectue la conversion en stockant 
 * les chiffres de num dans str de droite à gauche en utilisant le modulo 10 
 * et la division entière par 10. Si num est négatif, le premier caractère de 
 * str est défini à '-' et num est rendu positif.
 * Enfin, la fonction ft_print_itoa retourne la chaîne de caractères 
 * résultante str.En résumé, la fonction ft_print_itoa est utilisée pour 
 * convertir un nombre entier en une chaîne de caractères, qui peut ensuite 
 * être utilisée pour l'affichage ou le stockage dans un fichier ou une base 
 * de données.
 * 
*****************************************************************************/
char	*ft_print_itoa(long num)
{
	size_t	len;
	char	*str;

	len = ft_ilen(num);
	str = 0;
	str = ft_itostr(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}
