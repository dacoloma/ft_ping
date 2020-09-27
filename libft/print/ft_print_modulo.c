/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modulo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:51:46 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/23 11:41:52 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_pad(t_option *option, int *i)
{
	while (option->width > 1)
	{
		option->buffer[(*i)++] = option->pad_zero;
		option->len++;
		option->width--;
	}
}

void		ft_print_modulo(t_option *option, int *i, va_list ap)
{
	if (option->width == -1)
		option->width = va_arg(ap, int);
	if (option->l_justify)
	{
		option->buffer[*i] = '%';
		*i = *i + 1;
		ft_put_pad(option, i);
	}
	else
	{
		ft_put_pad(option, i);
		option->buffer[*i] = '%';
		*i = *i + 1;
	}
	option->len++;
}
