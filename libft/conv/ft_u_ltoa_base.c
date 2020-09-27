/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_ltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:16:29 by dcoloma           #+#    #+#             */
/*   Updated: 2019/09/12 17:53:11 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_size_ul(unsigned long int n, int base)
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

char				*ft_u_ltoa_base(unsigned long int n, int base)
{
	unsigned int	size;
	char			*result;
	char			*number;

	number = "0123456789abcdef";
	size = get_size_ul(n, base);
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
