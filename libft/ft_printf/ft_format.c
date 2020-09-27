/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:58:37 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/08 13:58:39 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_get_char(t_option *option, int *i, char c)
{
	option->buffer[(*i)++] = c;
	if (c == ' ' || c == '0')
		option->width--;
	option->len++;
}

void			ft_set_precision(t_option *option, int len)
{
	if (option->def_precision)
	{
		if (ft_strcmp(option->data, "0") && option->letter[option->i] != 'f')
			option->precision = 1;
		else
			option->precision = 0;
	}
	else if (option->f_precision && !option->precision)
	{
		option->def_precision = 1;
		ft_set_precision(option, len);
	}
	else if (len > option->precision && option->f_precision)
		option->f_precision = 0;
}

void			ft_padding(t_option *option, int *i, int len)
{
	int	j;

	if (!option->l_justify && !option->def_precision)
	{
		if (option->f_precision && option->precision > len)
			option->width = option->width - option->precision;
		else
			option->width = option->width - len;
	}
	j = 0;
	while (j < option->width)
	{
		option->buffer[(*i)++] = option->pad_zero;
		option->len++;
		j++;
	}
}

void			ft_get_sign(t_option *option, int *i, int *len)
{
	if (option->sign && ft_isdigit(option->data[0]))
	{
		if (option->pad_zero == '0')
		{
			option->buffer[(*i)++] = '+';
			option->sign = 0;
			option->len++;
		}
		option->width--;
	}
	if (option->data[0] == '-')
	{
		if (option->neg == 0 && option->pad_zero == '0')
		{
			option->buffer[(*i)++] = '-';
			option->len++;
			option->neg = 1;
		}
		if (!option->l_justify)
		{
			option->width--;
			(*len)--;
		}
	}
}
