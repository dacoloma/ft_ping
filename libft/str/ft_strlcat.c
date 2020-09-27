/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:00:02 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/19 10:45:36 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	size_t		len_src;
	size_t		i;
	size_t		j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	j = len_dst;
	if (size < len_dst)
		return (len_src + size);
	while (src[i] && j < (size - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_dst + len_src);
}
