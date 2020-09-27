/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:03:01 by dcoloma           #+#    #+#             */
/*   Updated: 2018/11/16 11:41:37 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer(int *tab, int n)
{
	int		i;
	int		j;
	int		key;

	i = 1;
	while (i < n)
	{
		j = i - 1;
		key = tab[i];
		while (j >= 0 && key < tab[j])
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}
