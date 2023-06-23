/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:13:53 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:52:48 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_arg(char type, va_list args, t_flag flag)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_char('%', flag);
	else if (type == 'c')
		count += ft_print_char(va_arg(args, int), flag);
	else if (type == 's')
		count += ft_print_str(va_arg(args, const char *), flag);
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(args, int), flag);
	else if (type == 'x')
		count += ft_print_hexa(va_arg(args, unsigned int), 0, flag);
	else if (type == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), 1, flag);
	else if (type == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flag);
	else if (type == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(args, void *), flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_parse_flag(const char *str, int i, va_list args, t_flag *flag)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flag = ft_flag_left(*flag);
		if (str[i] == '#')
			flag->hash = 1;
		if (str[i] == ' ')
			flag->space = 1;
		if (str[i] == '+')
			flag->plus = 1;
		if (str[i] == '0' && flag->left == 0 && flag->width == 0)
			flag->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flag);
		if (str[i] == '*')
			*flag = ft_flag_width(args, *flag);
		if (ft_isdigit(str[i]))
			*flag = ft_flag_digit(str[i], *flag);
		if (ft_istype(str[i]))
		{
			flag->specifier = str[i];
			break ;
		}
	}
	return (i);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_parse(char *str, va_list args)
{
	int		i;
	int		count;
	t_flag	flag;

	i = -1;
	count = 0;
	while (str[++i])
	{
		flag = ft_flag_initialize();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = ft_parse_flag(str, i, args, &flag);
			if (str[i] != '\0' && flag.specifier > 0 && ft_istype(str[i]))
				count += ft_print_arg(str[i], args, flag);
			else if (str[i] != '\0')
				count += ft_print_char(str[i], flag);
		}
		else
			count += ft_print_c(str[i]);
	}
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	char		*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}
