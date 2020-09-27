/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:36:39 by dcoloma           #+#    #+#             */
/*   Updated: 2019/11/15 14:36:41 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_len(long long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int		ft_get_float(long double *f_part, char (*tmp)[100],
	int precision)
{
	int	i;

	i = 1;
	(*tmp)[0] = '.';
	while (precision != 0)
	{
		(*f_part) *= 10;
		(*tmp)[i++] = (long long)(*f_part) % 10 + '0';
		precision--;
	}
	(*tmp)[i] = '\0';
	return (i);
}

static void		ft_rounding(long double nb, char (*tmp)[100],
	long long *int_part)
{
	int	i;
	int	carry;

	i = ft_strlen(*tmp) - 1;
	nb *= 10;
	if ((int)nb % 10 < 5)
		return ;
	carry = 1;
	while (carry == 1 && i > 0)
	{
		if ((*tmp)[i] == '9')
			(*tmp)[i--] = '0';
		else
		{
			(*tmp)[i--]++;
			carry = 0;
		}
	}
	if (i == 0 && carry == 1 && *int_part >= 0)
		(*int_part)++;
	else if (i == 0 && carry == 1 && *int_part < 0)
		(*int_part)--;
}

char			*ft_lftoa(long double n, char *data, int precision)
{
	long long	int_part;
	long double	float_part;
	char		*s1;
	char		s2[100];
	int			len1;

	int_part = (long long)n;
	float_part = n - (long double)int_part;
	len1 = ft_get_len(int_part);
	if (n < 0.0 && int_part == 0)
		len1++;
	if (float_part < 0)
		float_part *= -1;
	ft_get_float(&float_part, &s2, precision);
	ft_rounding(float_part, &s2, &int_part);
	if (!(data = ft_strnew(len1 + 1 + precision)))
		return (NULL);
	if (n < 0.0 && int_part == 0)
		data[0] = '-';
	s1 = ft_lltoa_base(int_part, 10);
	ft_strlcat(data, s1, len1 + 1);
	if (ft_strlen(s2) > 1)
		ft_strlcat(data, s2, len1 + ft_strlen(s2) + 1);
	free(s1);
	return (data);
}
