/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:21:23 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/02 14:21:54 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_ptr(t_option *option)
{
	option->ptr[0] = &ft_print_char;
	option->ptr[1] = &ft_print_str;
	option->ptr[2] = &ft_print_address;
	option->ptr[3] = &ft_print_decimal;
	option->ptr[4] = &ft_print_decimal;
	option->ptr[5] = &ft_print_octal;
	option->ptr[6] = &ft_print_udecimal;
	option->ptr[7] = &ft_print_hexa;
	option->ptr[8] = &ft_print_hexa;
	option->ptr[9] = &ft_print_float;
	option->ptr[10] = &ft_print_modulo;
}

static void	ft_init_var(t_option *option)
{
	option->letter = "cspdiouxXf%";
	option->size = 0;
	option->width = 0;
	option->l_justify = 0;
	option->sign = 0;
	option->pad_zero = ' ';
	option->space = 0;
	option->sharp = 0;
	option->len = 0;
	option->precision = 6;
	option->f_precision = 0;
	option->i = 0;
	option->def_precision = 0;
	option->neg = 0;
}

static void	ft_init_fct(t_option *option)
{
	option->get_fct[0] = &ft_get_flag;
	option->get_fct[1] = &ft_get_width;
	option->get_fct[2] = &ft_get_precision;
	option->get_fct[3] = &ft_get_size;
	option->test_fct[0] = &ft_is_flag;
	option->test_fct[1] = &ft_is_width;
	option->test_fct[2] = &ft_is_dot;
	option->test_fct[3] = &ft_is_size;
}

t_option	*init_option(void)
{
	t_option	*option;

	if ((option = (t_option *)malloc(sizeof(t_option))) == NULL)
		return (NULL);
	ft_init_ptr(option);
	ft_init_var(option);
	ft_init_fct(option);
	return (option);
}
