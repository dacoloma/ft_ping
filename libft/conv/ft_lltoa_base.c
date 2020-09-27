/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:42:04 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/12 20:42:23 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_llong(long long int n, int base)
{
	unsigned int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char				*ft_lltoa_base(long long int n, int base)
{
	unsigned int		size;
	unsigned long long	tmp;
	char				*result;
	char				*number;

	number = "0123456789abcdef";
	size = get_size_llong(n, base);
	if (!(result = ft_strnew(size)))
		return (NULL);
	result[size--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp)
	{
		result[size--] = number[tmp % base];
		tmp /= base;
	}
	return (result);
}

static unsigned int	get_size_f_llong(double f_nb)
{
	long long int	n;
	unsigned int	size;

	size = 0;
	if (f_nb < 0.0)
		size++;
	n = (long long)f_nb;
	if (n == 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char				*ft_f_lltoa_base(double f_nb)
{
	unsigned int		size;
	unsigned long long	tmp;
	char				*result;
	int					i;

	i = 0;
	size = get_size_f_llong(f_nb);
	if (!(result = ft_strnew(size)))
		return (NULL);
	result[size--] = '\0';
	if (f_nb < 0.0)
	{
		result[i++] = '-';
		tmp = (long long)(-f_nb);
	}
	else
		tmp = (long long)(f_nb);
	if (tmp == 0)
		result[i] = '0';
	while (tmp)
	{
		result[size--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (result);
}
