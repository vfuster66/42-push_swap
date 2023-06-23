/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:14:12 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:49 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
/*--------------FLAGS-----------------*/
typedef struct s_flag
{
	int	specifier;
	int	width;
	int	precision;
	int	left;
	int	star;
	int	hash;
	int	plus;
	int	space;
	int	zero;	
}		t_flag;

t_flag	ft_flag_initialize(void);
t_flag	ft_flag_left(t_flag flag);
t_flag	ft_flag_digit(char c, t_flag flag);
t_flag	ft_flag_width(va_list args, t_flag flag);
int		ft_flag_precision(const char *str, int pos, va_list args, t_flag *flag);
int		ft_width(int total_width, int size, int zero);
int		ft_parse_flag(const char *str, int i, va_list args, t_flag *flag);

/*---------------PRINTF----------------*/

int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flag flag);

/*-------------SPECIFIERS-------------------*/

/* c */
int		ft_print_char(char c, t_flag flag);
int		ft_print_c(char c);

/* s */
int		ft_print_str(const char *str, t_flag flag);
int		ft_print_s(const char *str);
int		ft_print_s_precision(const char *str, int precision);
int		ft_print_sign_precision(int n, t_flag *flag);

/* i, d */
int		ft_print_int(int n, t_flag flag);
int		ft_print_integer(char *nbstr, int n, t_flag flag);
int		ft_print_i(char *nbstr, int n, t_flag flag);

/* u */
int		ft_print_unsigned(unsigned int n, t_flag flag);
int		ft_print_u(char *nbstr, t_flag flag);
int		ft_print_uint(char *nbstr, t_flag flag);

/* x, X */
int		ft_print_hexa(unsigned int n, int is_upper, t_flag flag);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flag flag);
int		ft_print_hexadec(char *nbstr, int n, int is_ipper, t_flag flag);

/* p */
int		ft_print_ptr(unsigned long int n, t_flag flag);
int		ft_print_p(unsigned long int n);
void	ft_print_address(unsigned long int n);

/*-------------------UTILS------------------------------*/
int		ft_plen(unsigned long int n);
int		ft_istype(int c);
int		ft_isflag(int c);
int		ft_isspecifier(int c);
char	*ft_print_utoa(unsigned int num);
char	*ft_print_itoa(long num);
char	*ft_print_xtoa(unsigned long int num, int is_upper);

#endif
