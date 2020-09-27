/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:16:52 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/08 15:33:24 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len_s1;
	int		i;

	len_s1 = ft_strlen(s1);
	i = 0;
	if ((cpy = (char *)malloc(sizeof(char) * (len_s1 + 1))) == NULL)
		return (NULL);
	while (i < len_s1)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
