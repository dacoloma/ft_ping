/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:32 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/19 10:29:01 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
		res = ((res * 10) + str[i++] - '0');
	if (negat == -1)
		res = (res > 9223372036854775808U) ? 0 : -res;
	else
		res = (res > 9223372036854775807) ? -1 : res;
	return (int)res;
}
