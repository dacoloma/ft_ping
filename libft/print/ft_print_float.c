/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:18:34 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/23 14:34:39 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <math.h>

static char		*get_number(t_option *option, va_list ap)
{
	if (option->size == 2)
		return (ft_lftoa(va_arg(ap, double), option->data, option->precision));
	else if (option->size == 5)
		return (ft_lftoa(va_arg(ap, long double), option->data,
			option->precision));
	else
		return (ft_lftoa(va_arg(ap, double), option->data, option->precision));
}

static void		ft_put_prefix(t_option *option, int *i, int len)
{
	ft_signed_format(option, i);
	if (!option->def_precision && option->f_precision
		&& len <= option->precision)
	{
		if (option->data[0] == '-' && option->pad_zero == ' ')
		{
			if (option->neg == 0)
			{
				option->buffer[(*i)++] = '-';
				option->len++;
				option->neg = 1;
			}
			option->width--;
			len--;
		}
		ft_fill_zeros(option, len, i);
	}
}

static void		ft_get_pad(t_option *option, int *i, int len)
{
	int	j;

	if (option->width == 0)
		return ;
	j = 0;
	if (!option->l_justify && !option->def_precision)
	{
		if (option->f_precision && option->precision > len)
			option->width = option->width - option->precision;
		else
			option->width = option->width - len;
	}
	if (!option->l_justify && option->space && ft_isdigit(option->data[0]))
	{
		option->buffer[(*i)++] = ' ';
		option->width--;
		option->len++;
		option->space = 0;
	}
	while (j < option->width)
	{
		option->buffer[(*i)++] = option->pad_zero;
		option->len++;
		j++;
	}
}

static void		ft_get_data(t_option *option, int *i, int len)
{
	int	j;

	j = 0;
	(void)len;
	while (option->data[j])
	{
		option->buffer[(*i)++] = option->data[j++];
		option->width--;
		option->len++;
	}
	if (option->sharp && option->precision == 0)
	{
		option->buffer[(*i)++] = '.';
		option->width--;
		option->len++;
	}
}

void			ft_print_float(t_option *option, int *i, va_list ap)
{
	int		len;

	ft_wildcard(option, ap);
	if ((option->data = get_number(option, ap)) == NULL)
		return ;
	len = (int)ft_strlen(option->data);
	if (option->l_justify)
	{
		ft_put_prefix(option, i, len);
		ft_get_data(option, i, len);
		ft_get_pad(option, i, len);
	}
	else
	{
		ft_get_pad(option, i, len);
		ft_put_prefix(option, i, len);
		ft_get_data(option, i, len);
	}
	ft_free_printf(option);
}
