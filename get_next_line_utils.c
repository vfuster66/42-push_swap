/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:52:03 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/02 09:43:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***************************************************************************
 *
 * Prend en entree une chaine de caracteres et retourne un entier.
 * Permet de verifier si la chaine contient '\n'
 * Parcourt la chaine caractere par caractere
 * Si les 2 valeurs sont identiques ('\n') -> retourne 1
 * Si non -> 0
 *
 * *************************************************************************/
int	contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/****************************************************************************
 *
 * Permet de concatener 2 chaines de caracteres en 1 seule.
 * Calcule la longueur de s1 en parcourant les caracteres 1 par 1 jusqu'a
 * la fin de la chaine.
 * Fait la meme chose pour s2.
 * Alloue de la memoire pour contenir la nouvelle chaine en utilisant
 * ft_malloc_zero
 * Copie les caracteres de s1 dans la nouvelle chaine en parcourant les
 * caracteres de s1 1 a 1.
 * Continue avec S2
 * Renvoie la nouvelle chaine
 *
 * *************************************************************************/
char	*join_strs(const char *s1, const char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc_zero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}

/****************************************************************************
 *
 * Permet de copier une chaine de caracteres passee en argument dans une
 * nouvelle zone memoire allouee dynamiquement
 * Verifie si la chaine passee en argument est nulle.
 * Si oui -> renvoie une chaine vide.
 * Si non -> calcule la longueur de la chaine en parcourant chaque caractere
 * jusqu'a '\0'.
 * Alloue de la memoire pour une nouvelle chaine de caractere avec
 * ft_malloc_zero.
 * Si l'allocation echoue -> renvoie NULL
 * Copie chaque caractere de la chaine avec une boucle
 * Renvoie la nouvelle chaine creee
 *
 * *************************************************************************/
char	*ft_dup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_dup(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_malloc_zero(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

/****************************************************************************
 *
 * Alloue de la memoire en prenant en entree 2 parametres :
 *     - le nombre d'elements que l'on veut allouer
 *     - la taille de chaque element
 * Calcule la taille totale de la memoire a allouer par count * size
 * Appelle malloc pour allouer la memoire demandee
 * Si malloc KO -> renvoie NULL
 * Si malloc OK -> parcourt la memoire allouee octet par octet a l'aide
 * d'un pointeur. Initiqlise chaque octet a 0 grace a while jusqu'a ce
 * que tous les octets soient initialises
 * Renvoie le pointeur vers la memoire nouvellement allouee qui est une
 * zone de memoire allouee et initialisee a 0 de la taille demandee afin
 * d'eviter les erreurs de memoire non initialiee
 *
 * ************************************************************************/
void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}

/***************************************************************************
 *
 * Utile dans le cas ou de la memoire est allouee pour plusieurs chaines 
 * de caracteres et que l'on souhaite liberer cette memoire plus tard
 * Permet d'eviter les fuites de memoire en 
 * Prend 3 pointeurs de chaines de caracteres en entree.
 * Verifie si chaque pointeur est non nul et s'il pointe vers une 
 * zone de memoire allouee.
 * Si 1 pointeur n'est pas nul et pointe vers une zone de memoire allouee
 * la fonction libere la memoire de cette zone (free) et met le pointeur a 
 * NULL (evite un acces non autorise a la zone memoire liberee)
 *
 * ************************************************************************/
void	ft_free_strs(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}
