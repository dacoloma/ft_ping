/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:16:41 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/19 10:33:15 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	uc;
	size_t			i;

	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (uc == src[i])
			return ((void *)&dst[i + 1]);
		i++;
	}
	return (NULL);
}
