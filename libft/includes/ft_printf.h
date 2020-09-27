/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:51:50 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/24 16:52:01 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_option
{
	char	*letter;
	int		size;
	int		width;
	int		l_justify;
	int		sign;
	char	pad_zero;
	int		space;
	int		sharp;
	int		precision;
	int		f_precision;
	int		def_precision;
	int		neg;
	int		i;
	int		j;
	void	(*ptr[11])(struct s_option *, int *, va_list ap);
	char	*data;
	char	buffer[10000];
	int		len;
	int		(*get_fct[4])(const char *restrict *str, struct s_option *option,
		va_list ap);
	int		(*test_fct[4])(char c);
}				t_option;
int				ft_printf(const char *restrict format, ...);
int				ft_is_flag(char c);
int				ft_is_width(char c);
int				ft_is_dot(char c);
int				ft_is_size(char c);
int				ft_is_type(t_option *option, char c);
int				get_precision(const char *restrict *str, t_option *option);
t_option		*init_option(void);
void			ft_l_justify(const char *restrict *str, t_option *option,
	char *c);
void			ft_sign(const char *restrict *str, t_option *option, char *c);
void			ft_pad_zero(const char *restrict *str, t_option *option,
	char *c);
void			ft_space(const char *restrict *str, t_option *option, char *c);
void			ft_sharp(const char *restrict *str, t_option *option, char *c);
int				ft_get_option(const char *restrict *str, t_option *option,
	va_list ap);
int				ft_get_flag(const char *restrict *str, t_option *option,
	va_list ap);
int				ft_get_width(const char *restrict *str, t_option *option,
	va_list ap);
int				ft_get_precision(const char *restrict *str, t_option *option,
	va_list ap);
int				ft_get_size(const char *restrict *str, t_option *option,
	va_list ap);
void			ft_get_char(t_option *option, int *i, char c);
char			*ft_u_itoa_base(unsigned int n, int base);
char			*ft_u_htoa_base(unsigned short n, int base);
char			*ft_u_hhtoa_base(unsigned char n, int base);
char			*ft_u_ltoa_base(unsigned long int n, int base);
char			*ft_u_lltoa_base(unsigned long long int n, int base);
char			*ft_htoa_base(short n, int base);
char			*ft_hhtoa_base(signed char n, int base);
char			*ft_ltoa_base(long int n, int base);
char			*ft_lltoa_base(long long int n, int base);
char			*ft_f_lltoa_base(double f_nb);
char			*ft_lftoa(long double n, char *nb, int precision);
void			ft_print_str(t_option *option, int *i, va_list ap);
void			ft_print_char(t_option *option, int *i, va_list ap);
void			ft_print_address(t_option *option, int *i, va_list ap);
void			ft_print_decimal(t_option *option, int *i, va_list ap);
void			ft_print_octal(t_option *option, int *i, va_list ap);
void			ft_print_udecimal(t_option *option, int *i, va_list ap);
void			ft_print_hexa(t_option *option, int *i, va_list ap);
void			ft_print_float(t_option *option, int *i, va_list ap);
void			ft_print_modulo(t_option *option, int *i, va_list ap);
void			ft_putbuf(t_option *option);
void			ft_free_printf(t_option *option);
void			ft_fill_zeros(t_option *option, int len, int *i);
void			ft_padding(t_option *option, int *i, int len);
void			ft_get_sign(t_option *option, int *i, int *len);
void			ft_signed_format(t_option *option, int *i);
void			ft_set_precision(t_option *option, int len);
void			ft_wildcard_width(t_option *option, va_list ap);
void			ft_wildcard_precision(t_option *option, va_list ap);
void			ft_wildcard(t_option *option, va_list ap);
#endif
