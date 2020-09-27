/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:56:57 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/19 14:13:00 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_int_min(int nbr, int len_base, char *base)
{
	long long_nbr;

	long_nbr = nbr;
	long_nbr = -long_nbr;
	if (long_nbr / len_base != 0)
		ft_putnbr_base(long_nbr / len_base, base);
	ft_putchar(base[long_nbr % len_base]);
}

static int		ft_check_base(char *base)
{
	int	index;
	int	index_2;

	index = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		index++;
	}
	index = 0;
	while (base[index])
	{
		index_2 = index + 1;
		while (base[index_2])
		{
			if (base[index] == base[index_2])
				return (0);
			index_2++;
		}
		index++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (ft_check_base(base))
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_int_min(nbr, len_base, base);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else
		{
			if (nbr / len_base != 0)
				ft_putnbr_base(nbr / len_base, base);
			ft_putchar(base[nbr % len_base]);
		}
	}
}
