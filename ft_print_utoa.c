/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:34:19 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 08:13:19 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction ft_ulen calcule la longueur d'un nombre entier positif de type 
 * long. Elle prend un argument de type long nommé num et retourne un entier 
 * non signé de type size_t représentant le nombre de chiffres dans la 
 * représentation décimale de num.
 * La fonction commence par initialiser la variable len à 0. Si num est 
 * égal à 0, elle retourne 1 immédiatement, car un nombre à un seul 
 * chiffre est nécessaire pour représenter 0. Sinon, elle effectue une 
 * boucle while qui divise num par 10 à chaque itération et incrémente 
 * la variable len jusqu'à ce que num soit inférieur à 1. Finalement, elle 
 * retourne len.
 * En résumé, ft_ulen est une fonction utilitaire qui calcule le nombre 
 * de chiffres dans un nombre entier positif, ce qui est utile pour 
 * formater correctement les nombres entiers dans la fonction ft_printf.
 * 
*****************************************************************************/
static size_t	ft_ulen(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/****************************************************************************
 *
 * La fonction ft_utostr permet de convertir un nombre non signé en une 
 * chaîne de caractères.
 * Elle prend en paramètres :
 *     num : le nombre non signé à convertir. 
 *     str : un pointeur sur une chaîne de caractères à remplir. 
 * Si ce pointeur vaut NULL, la fonction allouera de la mémoire pour créer 
 * une nouvelle chaîne de caractères.
 *     len : la longueur de la chaîne de caractères à allouer.
 * La fonction commence par allouer de la mémoire pour une chaîne de 
 * caractères de longueur len + 1 (pour inclure le caractère nul de fin 
 * de chaîne). Si str n'est pas NULL, alors la mémoire est supposée avoir 
 * déjà été allouée et str pointe vers cette mémoire.
 * Ensuite, la fonction parcourt la chaîne de caractères de droite à gauche 
 * et insère les chiffres du nombre num dans chaque case de la chaîne. Pour 
 * ce faire, la fonction utilise la division euclidienne pour extraire le 
 * chiffre le moins significatif de num à chaque itération et le convertit 
 * en un caractère en ajoutant le code ASCII de '0'.
 * Finalement, la fonction renvoie un pointeur vers la chaîne de caractères 
 * nouvellement créée ou modifiée. Si l'allocation de mémoire a échoué, 
 * la fonction renvoie NULL.
 * 
*****************************************************************************/
static char	*ft_utostr(unsigned int num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

/****************************************************************************
 *
 * La fonction ft_print_utoa prend un nombre entier non signé en entrée et 
 * renvoie une chaîne de caractères contenant la représentation de ce nombre 
 * en base 10.
 * Tout d'abord, la fonction appelle la fonction ft_ulen pour déterminer 
 * la longueur nécessaire de la chaîne de caractères qui stockera le nombre. 
 * Ensuite, elle alloue de la mémoire pour cette chaîne à l'aide de la 
 * fonction ft_utostr.La fonction ft_utostr prend le nombre, la chaîne de 
 * caractères et la longueur en entrée. Elle alloue de la mémoire pour la 
 * chaîne de caractères et effectue une boucle pour remplir la chaîne de 
 * caractères avec les chiffres du nombre, du moins significatif au plus 
 * significatif.
 * Enfin, la fonction ft_print_utoa renvoie la chaîne de caractères qui 
 * a été créée.Notez que la fonction ft_print_utoa peut retourner NULL si 
 * l'allocation de mémoire échoue dans ft_utostr. Dans ce cas, l'appelant 
 * doit gérer l'erreur.
 * 
*****************************************************************************/
char	*ft_print_utoa(unsigned int num)
{
	size_t	len;
	char	*str;

	len = ft_ulen(num);
	str = 0;
	str = ft_utostr(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}
