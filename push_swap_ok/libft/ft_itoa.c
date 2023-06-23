/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:28 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 08:59:47 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * fonction qui convertit un entier en chaine de caracteres
 *
 * get_size determine la longueur de la chaine de caracteres en calculant
 * le nombre de chiffres necessaires pour representer l'entier 
 *
 * fill_res remplit la chaine de caracters avec les chiffres de l'entier
 * en utilisant le modulo et la division pour extraire les chiffre 
 * un par un de gauche a droite
 *
 * itoa alloue de la memoire pour la chaine de caracteres resultante
 * gere les cas speciaux (entier negatif) et remplit la chaine de 
 * caracteres avec fill_res.
 * Retourne la chaine de caracteres 
 *
 *****************************************************************************/
static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill_res(int size, int offset, int n, char *res)
{
	while (size > offset)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size --;
	}
}

char	*ft_itoa(int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = get_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	fill_res(size, offset, n, res);
	res[size] = '\0';
	return (res);
}
