/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:47:18 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/07 17:55:00 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/******************************************************************************
 * 
 * Cette fonction convertit un nombre entier non signé en une chaîne de 
 * caractères hexadécimale. La chaîne résultante peut être en majuscules ou en
 * minuscules en fonction de la valeur de la variable "is_upper".
 * 
******************************************************************************/

/******************************************************************************
* 
* calcule la longueur de la chaîne hexadécimale résultante en comptant 
* le nombre de chiffres hexadécimaux nécessaires pour représenter le nombre 
* donné.
* 
******************************************************************************/
static size_t	ft_xlen(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 16;
	}
	return (len);
}

/******************************************************************************
* 
* Convertit le nombre en une chaîne de caractères hexadécimale en divisant le 
* nombre par 16 (la base hexadécimale) et en stockant les chiffres hexadécimaux
* correspondants dans la chaîne de caractères. Les chiffres hexadécimaux de 
* 0 à 9 sont représentés par les caractères '0' à '9' et les chiffres 
* hexadécimaux de 10 à 15 sont représentés par les caractères 'a' à 'f' pour 
* les minuscules ou 'A' à 'F' pour les majuscules.
*
******************************************************************************/
static char	*ft_xtostr(unsigned long int num, char *str, size_t len)
{
	int	mod;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		num = num / 16;
		len--;
	}
	return (str);
}

/********************************************************************
*
* Appelle les deux fonctions précédentes pour convertir le nombre
* donné en une chaîne hexadécimale et mettre tous les caractères en 
* majuscules si "is_upper" est égal à 1.
*
*********************************************************************/
char	*ft_print_xtoa(unsigned long int num, int is_upper)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_xlen(num);
	str = 0;
	str = ft_xtostr(num, str, len);
	if (!str)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}
