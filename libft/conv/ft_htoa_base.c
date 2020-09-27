/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:01 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/13 15:38:22 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_shrt(short n, int base)
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

char				*ft_htoa_base(short n, int base)
{
	unsigned int		size;
	unsigned long long	tmp;
	char				*result;
	char				*number;

	number = "0123456789abcdef";
	size = get_size_shrt(n, base);
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
