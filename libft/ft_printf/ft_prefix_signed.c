/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:17:41 by dcoloma           #+#    #+#             */
/*   Updated: 2019/12/02 19:17:44 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_fill_zeros(t_option *option, int len, int *i)
{
	int	j;

	j = 0;
	while (j < option->precision - len)
	{
		option->buffer[(*i)++] = '0';
		option->width--;
		option->len++;
		j++;
	}
}

void			ft_signed_format(t_option *option, int *i)
{
	if (option->sign && ft_isdigit(option->data[0]))
	{
		option->buffer[(*i)++] = '+';
		option->width--;
		option->len++;
		option->sign = 0;
	}
	if (option->space && ft_isdigit(option->data[0]))
	{
		option->buffer[(*i)++] = ' ';
		option->width--;
		option->len++;
		option->space = 0;
	}
}
