/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:19:59 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:07:37 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Itere sur tous les caracteres d'une chaine de caracteres en passant
 * leur index a une fonction donnee
 * Verifie aue s et f ne sont pas nuls
 * Calcule la longueur de s avec ft_strlen
 * i stocke la longueur de la chaine et i2 sert de compteur
 * La boucle itere sur tous les caracteres de la chaine
 * A chaque iteration elle appelle (*f)(i2, s) ce qui passe i2 et le pointeur
 * vers le caractere actuel a la fonction f
 * Deplace s pour pointer vers le caractere suivant et incremente i2 pour
 * passer a la prochaine iteration
 *
 *****************************************************************************/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	if (s != NULL || f != NULL)
	{
		i = ft_strlen(s);
		while (i2 < i)
		{
			(*f)(i2, s);
			s++;
			i2++;
		}
	}
}
