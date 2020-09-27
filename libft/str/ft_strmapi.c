/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:08:26 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 15:59:51 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len_s;
	int		i;
	char	*strmapi;

	if (!s || !f)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if ((strmapi = (char*)malloc(sizeof(*strmapi) * (len_s + 1))) == NULL)
		return (NULL);
	while (i < len_s)
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
