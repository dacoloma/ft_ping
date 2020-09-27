/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_htoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:53:19 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/16 15:07:08 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_ushrt(unsigned short n, int base)
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

char				*ft_u_htoa_base(unsigned short n, int base)
{
	unsigned int		size;
	unsigned long long	tmp;
	char				*result;
	char				*number;

	number = "0123456789abcdef";
	size = get_size_ushrt(n, base);
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
