/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:57:25 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/30 17:56:33 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_invalid_param(const char *restrict *s, t_option *option, int *i)
{
	if (**s != '\0')
	{
		option->buffer[(*i)++] = **s;
		option->len++;
	}
}

static int	ft_get_data(const char *restrict str, t_option *option,
	int *i, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str && ft_get_option(&str, option, ap) == 1)
			{
				if (option->i == 5 || option->i == 6
					|| option->i == 7 || option->i == 8)
					option->sign = 0;
				option->ptr[option->i](option, i, ap);
			}
			else
				ft_invalid_param(&str, option, i);
		}
		else
			ft_invalid_param(&str, option, i);
		if (*str != '\0')
			str++;
	}
	option->buffer[*i] = '\0';
	return (1);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			i;
	t_option	*option;

	i = 0;
	va_start(ap, format);
	option = init_option();
	if (!ft_get_data(format, option, &i, ap))
		return (-1);
	ft_putbuf(option);
	va_end(ap);
	free(option);
	return (i);
}
