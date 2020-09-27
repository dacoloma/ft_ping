/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:10:11 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/24 16:54:10 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_number(int size, va_list ap)
{
	if (size == 1)
		return (ft_u_htoa_base((short)va_arg(ap, int), 10));
	else if (size == 3)
		return (ft_u_hhtoa_base((signed char)va_arg(ap, int), 10));
	else if (size == 2)
		return (ft_u_ltoa_base(va_arg(ap, unsigned long int), 10));
	else if (size == 6)
		return (ft_u_lltoa_base(va_arg(ap, unsigned long long int), 10));
	else
		return (ft_u_itoa_base(va_arg(ap, unsigned int), 10));
}

static void		ft_put_prefix(t_option *option, int *i, int len)
{
	int		j;

	if (!option->def_precision && option->f_precision
		&& len < option->precision)
	{
		j = 0;
		while (j < option->precision - len)
		{
			option->buffer[(*i)++] = '0';
			option->width--;
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
		&& !ft_strcmp(option->data, "0") && !option->sharp)
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

void			ft_print_udecimal(t_option *option, int *i, va_list ap)
{
	int		len;

	if (option->width == -1)
		ft_wildcard_width(option, ap);
	if (option->precision == -1)
		ft_wildcard_precision(option, ap);
	if ((option->data = get_number(option->size, ap)) == NULL)
		return ;
	len = (int)ft_strlen(option->data);
	ft_set_precision(option, len);
	if (option->sign && ft_isdigit(option->data[0]))
		option->width--;
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
