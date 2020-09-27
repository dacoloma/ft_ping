/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:11:44 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/05 11:53:02 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_pad(t_option *option, int *i, int len)
{
	while (len < option->width)
	{
		option->buffer[(*i)++] = option->pad_zero;
		option->width--;
		option->len++;
	}
}

void			ft_print_char(t_option *option, int *i, va_list ap)
{
	char	c;

	if (option->width == -1)
		option->width = va_arg(ap, int);
	if (option->width < 0)
	{
		option->l_justify = 1;
		option->pad_zero = ' ';
		option->width = -option->width;
	}
	c = va_arg(ap, int);
	option->data = &c;
	if (option->l_justify)
	{
		option->buffer[(*i)++] = c;
		ft_get_pad(option, i, 1);
	}
	else
	{
		ft_get_pad(option, i, 1);
		option->buffer[(*i)++] = c;
	}
	option->len++;
}
