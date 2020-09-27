/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:46:53 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 15:59:16 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len_s;
	int		i;
	char	*strmap;

	if (!s || !f)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if ((strmap = (char*)malloc(sizeof(*strmap) * (len_s + 1))) == NULL)
		return (NULL);
	while (i < len_s)
	{
		strmap[i] = f(s[i]);
		i++;
	}
	strmap[i] = '\0';
	return (strmap);
}
