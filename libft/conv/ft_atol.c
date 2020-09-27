/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:45 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/13 13:50:48 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *str)
{
	int						i;
	int						negat;
	unsigned long long		res;

	negat = 1;
	i = 0;
	res = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negat = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = ((res * 10LL) + str[i++] - '0');
	if (negat == -1)
		res = (res > 9223372036854775808U) ? 0 : -res;
	else
		res = (res > 9223372036854775807) ? -1 : res;
	return (long long)res;
}
