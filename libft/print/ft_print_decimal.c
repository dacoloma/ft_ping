/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:20:21 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/02 13:16:23 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_number(int size, va_list ap)
{
	if (size == 1)
		return (ft_htoa_base((short)va_arg(ap, int), 10));
	else if (size == 3)
		return (ft_hhtoa_base((signed char)va_arg(ap, int), 10));
	else if (size == 2)
		return (ft_ltoa_base(va_arg(ap, long int), 10));
	else if (size == 6)
		return (ft_lltoa_base(va_arg(ap, long long int), 10));
	else
		return (ft_itoa(va_arg(ap, int)));
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
	if (option->width == 0)
		return ;
	ft_get_sign(option, i, &len);
	if (!option->l_justify && option->space && ft_isdigit(option->data[0]))
	{
		option->buffer[(*i)++] = ' ';
		option->width--;
		option->len++;
		option->space = 0;
	}
	ft_padding(option, i, len);
}

static void		ft_get_data(t_option *option, int *i)
{
	int	j;

	j = 0;
	if ((option->def_precision || !option->precision)
		&& !ft_strcmp(option->data, "0"))
		return ;
	if (option->space && ft_isdigit(option->data[0]))
	{
		option->buffer[(*i)++] = ' ';
		option->width--;
		option->len++;
		option->space = 0;
	}
	if (option->neg)
		j++;
	while (option->data[j])
	{
		option->buffer[(*i)++] = option->data[j++];
		option->width--;
		option->len++;
	}
}

void			ft_print_decimal(t_option *option, int *i, va_list ap)
{
	int		len;

	ft_wildcard(option, ap);
	option->data = get_number(option->size, ap);
	if (option->data == NULL)
		return ;
	len = (int)ft_strlen(option->data);
	ft_set_precision(option, len);
	if (option->l_justify)
	{
		ft_put_prefix(option, i, len);
		ft_get_data(option, i);
		ft_get_pad(option, i, len);
	}
	else
	{
		ft_get_pad(option, i, len);
		ft_put_prefix(option, i, len);
		ft_get_data(option, i);
	}
	ft_free_printf(option);
}
