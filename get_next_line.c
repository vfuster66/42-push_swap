/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:01:51 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/02 09:44:50 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*****************************************************************************
 *
 * Prend en entree un pointeur vers une chaine de caracteres
 * Renvoie une nouvelle chaine de caracteres qui contient tous les 
 * caracteres de s jusqu'au premier caractere de '\n' ou la chaine de 
 * caracteres complete si elle ne contient pas de saut de ligne
 * Parcourt la chaine de caracteres s a l'aide d'une boucle pour trouver
 * la position du 1er '\n'. Si elle le trouve elle incremente i pour passer 
 * au caractere suivant
 * Alloue de la memoire pour stocker la nouvelle chaine avec ft_malloc_zero
 * Si l'allocation echoue -> NULL
 * La 2eme boucle copie chaque caractere de s dans res.
 * Si elle trouve '\n' elle l'ajoute a res et incremente i
 * Renvoie res contenant la nouvelle chainede caracteres
 * Utile pour extraire la 1ere ligne d'un fichier
 *
 * **************************************************************************/
char	*get_before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

/****************************************************************************
 *
 * Prend en entree un pointeur vers une chaine de caracteres
 * Renvoie une nouvelle chaine de caracteres qui contient tous les 
 * caracteres de s apres le 1er caractere de saut de ligne '\n' inclus
 * ou une chaine vide si elle ne contient pas de saut de ligne
 *
 * Utilise j pour calculer la longueur de s en utilisant une boucle qui 
 * parcourt la chaine s jusqu'a trouver '\0'. Incremente j a chaque iteration
 * Utilise i pour trouver la position du 1er caractere de saut de ligne
 * dans s. Si elle trouve un saut de ligne, elle incremente i a chaque
 * iteration.
 * Alloue la memoire pour stocker res a l'aide de ft_malloc_zero.
 * Si l'allocation echoue -> renvoie NULL
 * Utilise une boucle pour copier les caracteres de s qui se trouvent apres
 * le 1er '\n' dans res.
 * Utile pour extraire le contenu d'un fichier apres la 1ere ligne ou
 * pour ignorer la 1ere ligne d'une entree utilisateur  
 *
 * *************************************************************************/
char	*get_after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

/****************************************************************************
 *
 * Prend en entree un file descriptor et 2 pointeurs de chaines de caracteres
 * Alloue de la memoire de taille BUFFER_SIZE + 1 grace a malloc
 * Si l'allocation echoue, la fonction quitte immediatement.
 * Boucle qui se repete tant que read retourne un nombre de caracteres > 0.
 * read lit les donnees depuis fd et les stocke dans buf.
 * Si read retourne une valeur negative, une erreur s'est produite. La 
 * fonction quitte en appelant ft_free_strs pour liberer la memoire.
 * Si la lecture reussit, ajoute '\0' a la fin de buf pour garantir que la
 * chaine est correctement terminee.
 * Copie la valeur de la chaine pointee par keep vers la chaine pointee
 * par tmp a l'aide de ft_strdup, puis libere la memoire allouee pour keep
 * en appelant ft_free_strs.
 * La fonction concatene les chaines pointees par tmp et buf avec join_strs
 * pour former une chaine plus grande et stocke le resultat dans keep.
 * Libere la memoire alloue pour tmp avec ft_free_strs.
 * La boucle lit les donnees tant que la chaine pointee par keep ne 
 * contient pas de '\n', ce qui signifie aue la fin de la ligne n'est pas
 * encore atteinte.
 * * Lorsque la boucle se termine, la fonction libere la memoire allouee
 * pour buf avec ft_free_strs.
 * Utilisee pour lire des donnees a partir d'un file descriptor jusqu'a ce
 * qu'elle atteigne la fin de ligne, puis stocke les donnees lues dans la 
 * chaine de caracteres pointee par keep.
 *
 * *************************************************************************/
void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_dup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = join_strs(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
}

/****************************************************************************
 *
 * Prend 2 pointeurs vers des pointeurs de caracteres:
 *    - keep pointe vers la chaine dans laquelle on veut extraire la 1ere
 * ligne.
 *    - tmp est utilise pour stocker une copie temporaire de la chaine
 * Cree une copie de la chaine stockee dans tmp.
 * Utilisationde ft_free_strs pour liberer la memoire utilisee par keep
 * Utilisation de get_after_newline pour extraire la partie de la chaine
 * qui se trouve apres la 1ere occurence de '\n'. Cette partie est
 * stockee dans keep.
 * Utilisation de get_before_newline pour extraire la premiere occurence
 * d'un caractere de nouvelle ligne. Cette partie est stockee dans keep.
 * Utilisation de ft_free_strs pour liberer la memoire occupee par tmp.
 * Renvoie la chaine extraite line.
 *
 * *************************************************************************/
char	*ft_parse_line(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_dup(*keep);
	ft_free_strs(keep, 0, 0);
	*keep = get_after_newline(*tmp);
	line = get_before_newline(*tmp);
	ft_free_strs(tmp, 0, 0);
	return (line);
}

/*****************************************************************************
 *
 * Pour le bonus.
 * On utilise un tableau de pointeurs keep pour stocker la chaine de 
 * caracteres non lue associee a chaque file descriptor.
 * L'utilisation d'un tableau de pointeurs permet de stocker plusieurs 
 * chaines de caracteres non lues simultanement en appelant
 * get_next_line avec differents fd.
 *
 * **************************************************************************/
char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &keep[fd], &tmp);
	if (keep[fd] != NULL && *keep[fd] != '\0')
		line = ft_parse_line(&keep[fd], &tmp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&keep[fd], &line, &tmp);
		return (NULL);
	}
	return (line);
}
