/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:52:20 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/08 19:20:08 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	to_find;

	to_find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char *)&s[i]);
		i++;
	}
	if (to_find == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
