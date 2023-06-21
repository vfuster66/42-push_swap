/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:15:39 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 08:28:29 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
 *
 * fonction qui convertit une chaine de caracteres en un nombre entier
 * i = parcourt la chaine de caractere
 * sign = stocke le signe du nombre
 * number = stocke le nombre converti
 * on utilise une boucle pour sauter tous les espaces blancs 
 * et les caracteres de controle au debut de la chaine
 * ensuite, si le 1er caractere est - le signe est negatif 
 * et i est incremente pour ignorer le -. Si + i est simplement incremente
 * enfin une boucle while permet de convertir les caracteres restants 
 * en nombre entier. On verifie si chaque caractere est un chiffre.
 * Si c'est le cas, il est converti en nombre et ajoute au nombre total
 * qui est ensuite multiplie par 10.
 * lorsque la boucle s'arrete, le nombre total est multiplie par le signe 
 * et renvoye en tant que valeur de retour de la fonction
 *
 ************************************************************************** */
int	ft_atoi(char const *nptr)
{
	int		i;
	long	number;
	long	sign;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == ' ' || ((9 <= nptr[i]) && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	return (number * sign);
}
