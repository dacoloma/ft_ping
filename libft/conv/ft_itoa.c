/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:23:37 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/14 18:40:57 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_int_to_str(int n)
{
	int			count;
	long long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int				len_n;
	char			*str;
	long long		nb;

	nb = n;
	len_n = (nb < 0) ? len_int_to_str(nb) + 1 : len_int_to_str(nb);
	(n == 0) ? len_n++ : 0;
	if ((str = (char *)malloc(sizeof(char) * (len_n + 1))) == NULL)
		return (NULL);
	str[len_n] = '\0';
	len_n--;
	(n == 0) ? str[0] = '0' : 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[len_n--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
