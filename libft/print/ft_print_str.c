/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:22:46 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/05 11:53:48 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_data(t_option *option, int *i)
{
	int	j;

	j = 0;
	while (option->data[j])
	{
		if (option->f_precision && j == option->precision)
			return ;
		option->buffer[(*i)++] = option->data[j++];
		option->len++;
	}
}

static void		ft_get_pad(t_option *option, int *i, int len)
{
	if (option->f_precision && option->precision < len)
		len = option->precision;
	while (len < option->width)
	{
		ft_get_char(option, i, option->pad_zero);
	}
}

void			ft_reset(t_option *option)
{
	option->size = 0;
	option->width = 0;
	option->l_justify = 0;
	option->sign = 0;
	option->pad_zero = ' ';
	option->space = 0;
	option->sharp = 0;
	option->precision = 6;
	option->def_precision = 0;
	option->f_precision = 0;
	option->neg = 0;
}

void			ft_print_str(t_option *option, int *i, va_list ap)
{
	int		len;

	if (option->width == -1)
		ft_wildcard_width(option, ap);
	if (option->precision == -1)
		ft_wildcard_precision(option, ap);
	option->data = va_arg(ap, char *);
	if (option->data == NULL)
		option->data = "(null)";
	len = (int)ft_strlen(option->data);
	if (option->def_precision)
		option->precision = 0;
	if (option->l_justify)
	{
		ft_get_data(option, i);
		ft_get_pad(option, i, len);
	}
	else
	{
		ft_get_pad(option, i, len);
		ft_get_data(option, i);
	}
	ft_reset(option);
}
