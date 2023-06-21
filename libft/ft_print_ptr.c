/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:33:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/10 07:43:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * La fonction ft_plen est utilisée pour calculer la longueur d'un nombre en 
 * base 16 (hexadécimal). Elle prend un argument de type unsigned long int 
 * qui représente le nombre à calculer et retourne un entier qui correspond 
 * à la longueur de ce nombre en hexadécimal.
 * La fonction commence par initialiser la variable len à zéro, qui 
 * représente la longueur du nombre en hexadécimal. Si le nombre est égal à 
 * zéro, la fonction retourne simplement 1 car la longueur de 0 est 1.
 * Ensuite, la fonction parcourt le nombre en divisant successivement par 
 * 16 (la base hexadécimale) et en incrémentant len jusqu'à ce que le nombre 
 * devienne inférieur à 1. À ce stade, la fonction retourne len qui 
 * représente la longueur du nombre en hexadécimal.
 * En résumé, cette fonction est utilisée pour déterminer la longueur 
 * d'un nombre en hexadécimal, ce qui peut être utile pour allouer la 
 * mémoire nécessaire pour stocker le nombre sous forme de chaîne de 
 * caractères.
 * 
*****************************************************************************/
int	ft_plen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
}

/****************************************************************************
 *
 * Utilisée pour afficher une adresse mémoire sous forme hexadécimale en 
 * utilisant la notation conventionnelle de C avec le préfixe "0x". La 
 * fonction prend en argument un entier non signé n qui représente l'adresse 
 * à afficher.
 * La fonction commence par vérifier si n est supérieur ou égal à 16, 
 * c'est-à-dire s'il y a des chiffres hexadécimaux à afficher. Si c'est 
 * le cas, elle divise n par 16 et appelle récursivement ft_print_address 
 * sur le quotient pour afficher les chiffres hexadécimaux dans l'ordre 
 * correct. Ensuite, elle prend le reste de la division de n par 16 et 
 * l'affiche en utilisant la fonction auxiliaire ft_print_c.
 * Si n est inférieur à 16, la fonction vérifie si n est inférieur à 10. 
 * Si oui, elle ajoute '0' à la valeur de n et l'affiche en utilisant 
 * ft_print_c. Sinon, elle soustrait 10 de n et ajoute 'a' pour afficher 
 * la lettre hexadécimale correspondante.
 * En fin de compte, cette fonction est utilisée pour afficher des 
 * adresses mémoire en hexadécimal, ce qui est particulièrement utile pour 
 * le débogage et la compréhension des programmes C.
 * 
*****************************************************************************/
void	ft_print_address(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_address(n / 16);
		ft_print_address(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else if (n >= 10)
			ft_print_c((n - 10) + 'a');
	}
}

/****************************************************************************
 *
 * La fonction ft_print_p prend en entrée un nombre entier non signé de type 
 * unsigned long int et renvoie le nombre total de caractères imprimés pour 
 * représenter l'adresse en hexadécimal.
 * Tout d'abord, la fonction vérifie si l'adresse est nulle, c'est-à-dire 
 * si elle vaut 0. Si c'est le cas, la fonction affiche la chaîne "(nil)" à 
 * l'aide de la fonction ft_print_s et retourne le nombre de caractères 
 * imprimés.
 * Si l'adresse n'est pas nulle, la fonction affiche la chaîne "0x" à l'aide 
 * de la fonction ft_print_s. Ensuite, elle appelle la fonction ft_print_address 
 * pour afficher l'adresse en hexadécimal. Enfin, la fonction appelle la 
 * fonction ft_plen pour déterminer la longueur en chiffres hexadécimaux de 
 * l'adresse et ajoute cette valeur au nombre total de caractères imprimés.
 * En résumé, la fonction ft_print_p est utilisée pour imprimer une adresse 
 * en hexadécimal en ajoutant la chaîne "0x" devant et en calculant le 
 * nombre total de caractères imprimés.
 * 
*****************************************************************************/
int	ft_print_p(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_s("(nil)");
		return (count);
	}
	count += ft_print_s("0x");
	ft_print_address(n);
	count += ft_plen(n);
	return (count);
}

/****************************************************************************
 *
 * La fonction ft_print_ptr prend en argument un pointeur de type unsigned 
 * long int et une structure de type t_flag contenant des indicateurs de 
 * formatage. Elle retourne le nombre de caractères imprimés.
 * La fonction commence par initialiser une variable count à zéro, qui 
 * eprésente le nombre de caractères imprimés. Si n est égal à zéro, la 
 * fonction ajuste la largeur en soustrayant la longueur de la chaîne "(nil)" 
 * moins 1, sinon elle soustrait 2. Cette largeur sera utilisée plus tard 
 * pour imprimer le résultat avec le bon nombre d'espaces de remplissage.
 * Ensuite, si l'indicateur left est défini à 1, la fonction appelle 
 * ft_print_p(n) pour imprimer l'adresse avec le formatage approprié, 
 * puis incrémente count de la valeur de retour. Sinon, elle appelle la 
 * fonction ft_width pour imprimer les espaces de remplissage nécessaires 
 * avant l'adresse, puis appelle ft_print_p(n) pour imprimer l'adresse 
 * elle-même, et enfin incrémente count de la valeur de retour de ces deux 
 * fonctions.
 * Finalement, la fonction retourne count qui représente le nombre total 
 * de caractères imprimés.
 * 
*****************************************************************************/
int	ft_print_ptr(unsigned long int n, t_flag flag)
{
	int	count;

	count = 0;
	if (n == 0)
		flag.width -= ft_strlen("(nil)") - 1;
	else
		flag.width -= 2;
	if (flag.left == 1)
		count += ft_print_p(n);
	count += ft_width(flag.width, ft_plen(n), 0);
	if (flag.left == 0)
		count += ft_print_p(n);
	return (count);
}
