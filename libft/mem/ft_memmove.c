/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:09:15 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/14 15:39:53 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst1;
	const char		*src1;
	size_t			i;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	i = len;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (i > 0)
		{
			dst1[i - 1] = src1[i - 1];
			i--;
		}
	}
	return (dst);
}
