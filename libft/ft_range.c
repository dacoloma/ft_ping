/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:20:34 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/19 15:02:51 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*tab;
	int		index;
	int		range;

	range = max - min;
	if (range <= 0)
		return (0);
	tab = (int *)malloc(sizeof(*tab) * (range));
	if (tab == NULL)
		return (0);
	index = 0;
	while (index < range)
	{
		tab[index] = min;
		index++;
		min++;
	}
	return (tab);
}
