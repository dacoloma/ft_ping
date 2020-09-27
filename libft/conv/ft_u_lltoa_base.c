/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_lltoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:56:03 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/12 17:58:06 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_ull(unsigned long long int n, int base)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char				*ft_u_lltoa_base(unsigned long long int n, int base)
{
	unsigned int	size;
	char			*result;
	char			*number;

	number = "0123456789abcdef";
	size = get_size_ull(n, base);
	if (!(result = ft_strnew(size)))
		return (NULL);
	result[size--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[size--] = number[n % base];
		n /= base;
	}
	return (result);
}
