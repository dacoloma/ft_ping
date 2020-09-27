/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:30:23 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/08 19:45:23 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;
	char	to_find;

	len_s = ft_strlen(s);
	to_find = (char)c;
	while (len_s >= 0)
	{
		if (s[len_s] == to_find)
			return ((char *)&s[len_s]);
		len_s--;
	}
	return (NULL);
}
