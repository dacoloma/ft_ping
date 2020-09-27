/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:09:32 by dcoloma           #+#    #+#             */
/*   Updated: 2019/11/29 12:09:36 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wildcard_width(t_option *option, va_list ap)
{
	option->width = va_arg(ap, int);
	if (option->width < 0)
	{
		option->width = -option->width;
		option->l_justify = 1;
		option->pad_zero = ' ';
	}
}

void		ft_wildcard_precision(t_option *option, va_list ap)
{
	option->precision = va_arg(ap, int);
	if (option->precision < 0)
	{
		option->f_precision = 0;
		option->precision = 0;
	}
	else
	{
		option->pad_zero = ' ';
	}
}

void		ft_wildcard(t_option *option, va_list ap)
{
	if (option->width == -1)
		ft_wildcard_width(option, ap);
	if (option->precision == -1)
		ft_wildcard_precision(option, ap);
}
