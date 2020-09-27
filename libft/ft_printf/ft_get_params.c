/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:30:32 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/30 13:30:35 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** h = 001
 ** hh = 011
*/
/*
 ** l = 010
 ** ll = 100
*/
/*
 ** L = 101
*/

int	ft_get_size(const char *restrict *str, t_option *option, va_list ap)
{
	int	count;

	(void)ap;
	count = 0;
	while ((**str == 'h' || **str == 'l' || **str == 'L') && count < 2)
	{
		if (count == 1 && ((**str == 'h' && option->size != 1)
					|| (**str == 'l' && option->size != 2) || **str == 'L'))
			return (0);
		if (**str == 'h')
			option->size = (option->size << 1) + 1;
		if (**str == 'l')
			option->size = (option->size << 1) + 2;
		if (**str == 'L')
			option->size = 5;
		count++;
		*str = *str + 1;
	}
	return (1);
}

int	ft_get_width(const char *restrict *str, t_option *option, va_list ap)
{
	char	buf_width[10];
	int		i;

	if (**str == '*')
	{
		option->width = -1;
		*str = *str + 1;
		if (ft_is_dot(**str) || ft_is_size(**str) || ft_is_type(option, **str))
		{
			return (1);
		}
		va_arg(ap, int);
	}
	if (**str && **str >= '0' && **str <= '9')
	{
		i = 0;
		while (**str && **str >= '0' && **str <= '9')
			buf_width[i++] = *((*str)++);
		buf_width[i] = '\0';
		option->width = ft_atoi(buf_width);
		return (1);
	}
	return (0);
}

int	ft_get_precision(const char *restrict *str, t_option *option, va_list ap)
{
	char	buf_precision[10];
	int		i;

	(void)ap;
	*str = *str + 1;
	if (**str == '*')
	{
		option->precision = -1;
		*str = *str + 1;
		return (1);
	}
	else if (**str && **str >= '0' && **str <= '9')
	{
		option->pad_zero = ' ';
		i = 0;
		while (**str && **str >= '0' && **str <= '9')
		{
			buf_precision[i++] = **str;
			*str = *str + 1;
		}
		buf_precision[i] = '\0';
		option->precision = ft_atoi(buf_precision);
		return (1);
	}
	return (0);
}

int	ft_get_option(const char *restrict *str, t_option *option, va_list ap)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (**str && option->test_fct[i](**str))
		{
			if (i == 2)
				option->f_precision = 1;
			if (!option->get_fct[i](str, option, ap))
			{
				if (i == 2)
					option->def_precision = 1;
				else
					return (0);
			}
		}
		i++;
	}
	if (**str && ft_is_type(option, **str))
		return (1);
	return (0);
}
/*
 ** % [flags][min_width][.precision][size]type
*/
