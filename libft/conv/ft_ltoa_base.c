/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:24:37 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/12 20:42:57 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_long(long int n, int base)
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

char				*ft_ltoa_base(long int n, int base)
{
	unsigned int		size;
	unsigned long long	tmp;
	char				*result;
	char				*number;

	number = "0123456789abcdef";
	size = get_size_long(n, base);
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
