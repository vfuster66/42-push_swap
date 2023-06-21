/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:00 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:06:35 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Fonction qui prend en entree 2 chaines de caracteres s et set
 * Retourne une nouvelle chaine qui est la copie de s sans les 
 * caracteres presents dans set en debut et en fin de chaine
 * Definit 2 variables rear et front pour socker les positions  de fin et
 * de debut de la nouvelle chaine
 * Initialise front a 0 et rear a la longueur de la chaine (ft_strlen)
 * Avance front jusqu'a ce que la valeur du caractere a cette position
 * ne soit plus dans set (ft_strchr)
 * Meme chose pour rear en reculant
 * Alloue de la memoire pour str en specifiant sa taille (rear - front + 1)
 * Copie sous-chaine de s entre front et rear dans str (ft_strlcpy)
 * Retourne str
 *
 *****************************************************************************/
char	*ft_strtrim(char const *s, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	str = 0;
	if (s != 0 && set != 0)
	{
		front = 0;
		rear = ft_strlen(s);
		while (s[front] && ft_strchr(set, s[front]))
			front++;
		while (s[rear - 1] && ft_strchr(set, s[rear - 1]) && rear > front)
			rear--;
		str = (char *)malloc(sizeof(char) * (rear - front +1));
		if (str)
			ft_strlcpy(str, &s[front], rear - front +1);
	}
	return (str);
}
