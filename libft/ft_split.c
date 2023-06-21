/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:19:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/16 09:02:10 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/******************************************************************************
 *
 * Prend en entree une chaine de caractere str et un caractere de separation c
 * Renvoie un tableau de chaines de caracteres correspondant aux mots
 * separes par le caractere c
 * 1- Determine le nombre de mots dans str
 * 2- Alloue de la memoire pour le tableau de mots
 * 3- Determine la longueur des mots suivants
 * 4- Alloue de la memoire pour chaque mot
 * 5- Remplit le tableau avec les mots
 * 6- Renvoie le tableau
 * Si l'allocation de memoire echoue, la fonction libere toute la memoire
 * allouee jusqu'a ce point  et renvoie 0
 *
 *****************************************************************************/
static int	ft_wordscount(char const *str, char sep)
{
	int	i;
	int	count;

	if (!str || !str[0])
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc_words(char const *str, char sep)
{
	int		len;
	char	**tab;

	if (!str)
		return (0);
	len = ft_wordscount(str, sep);
	tab = (char **)malloc(sizeof(*tab) * (len + 1));
	return (tab);
}

static int	ft_next_word_count(char const *str, char sep, int i)
{
	int	count;

	count = 0;
	while (str[i] == sep && str[i])
		i++;
	while (str[i] && str[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j])
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	int		word_start;
	int		i;
	int		j;
	char	**tab;

	word_start = 0;
	i = -1;
	tab = ft_malloc_words(str, c);
	if (!tab)
		return (0);
	while (++i < ft_wordscount(str, c))
	{
		j = 0;
		tab[i] = (char *)malloc(ft_next_word_count(str, c, word_start) + 1);
		if (!tab[i])
			return (ft_free(tab, i));
		while (str[word_start] && str[word_start] == c)
			word_start++;
		while (str[word_start] && str[word_start] != c)
			tab[i][j++] = str[word_start++];
		tab[i][j] = 0;
	}
	tab[i] = 0;
	return (tab);
}
