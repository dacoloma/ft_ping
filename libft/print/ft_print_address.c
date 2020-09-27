/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:48:50 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/05 14:28:15 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_prefix(t_option *option, int *i, int len)
{
	int		j;

	option->buffer[(*i)++] = '0';
	option->buffer[(*i)++] = 'x';
	option->len += 2;
	if (!option->def_precision && option->f_precision
		&& len < option->precision)
	{
		j = 0;
		while (j < option->precision - len)
		{
			option->buffer[(*i)++] = '0';
			option->len++;
			j++;
		}
	}
}

static void		ft_get_pad(t_option *option, int *i, int len)
{
	int	j;

	j = 0;
	if (!option->l_justify && !option->def_precision)
	{
		if (option->f_precision && option->precision > len)
			option->width = option->width - option->precision;
		else
			option->width = option->width - len;
	}
	while (j < option->width)
	{
		option->buffer[(*i)++] = option->pad_zero;
		option->len++;
		j++;
	}
}

static void		ft_get_data(t_option *option, int *i)
{
	int	j;

	j = 0;
	if ((option->def_precision || !option->precision)
		&& !ft_strcmp(option->data, "0"))
		return ;
	if (option->data[0] == '-' && (option->pad_zero == '0'
		|| option->f_precision))
		j++;
	while (option->data[j])
	{
		option->buffer[(*i)++] = option->data[j++];
		option->width--;
		option->len++;
	}
}

void			ft_print_address(t_option *option, int *i, va_list ap)
{
	int		len;

	if (option->width == -1)
		ft_wildcard_width(option, ap);
	if ((option->data = ft_lltoa_base(va_arg(ap, long long), 16)) == NULL)
		return ;
	len = (int)ft_strlen(option->data);
	option->width -= 2;
	if (option->l_justify)
	{
		put_prefix(option, i, len);
		ft_get_data(option, i);
		ft_get_pad(option, i, len);
	}
	else
	{
		ft_get_pad(option, i, len);
		put_prefix(option, i, len);
		ft_get_data(option, i);
	}
	ft_free_printf(option);
}
