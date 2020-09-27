/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:37:24 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 15:59:25 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		len_s;

	if (!s || !f)
		return ;
	i = 0;
	len_s = ft_strlen(s);
	while (i < len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
