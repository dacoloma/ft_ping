/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:27:20 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/09 14:10:43 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		n;
	int		h;

	h = 0;
	n = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[h])
	{
		while (haystack[h + n] == needle[n])
		{
			if (needle[n + 1] == '\0')
				return (char *)(haystack + h);
			n++;
		}
		h++;
		n = 0;
	}
	return (NULL);
}
