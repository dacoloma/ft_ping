/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:25:20 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 20:14:12 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	h = 0;
	if (len <= 0)
		return (NULL);
	if (needle[0] == '\0')
		return (char*)(haystack);
	while (haystack[h])
	{
		n = 0;
		while (h + n < len && haystack[h + n] == needle[n])
		{
			if (needle[n + 1] == '\0')
				return (char *)(haystack + h);
			n++;
		}
		h++;
	}
	return (NULL);
}
