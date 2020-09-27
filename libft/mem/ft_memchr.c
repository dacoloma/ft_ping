/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:05:34 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 18:29:06 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	to_find;
	char	*str;

	to_find = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (n--)
	{
		if (str[i] == to_find)
			return (str + i);
		i++;
	}
	return (NULL);
}
