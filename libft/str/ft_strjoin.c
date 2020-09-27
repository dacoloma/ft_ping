/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:41:41 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/15 20:48:18 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		l_s1;
	int		l_s2;

	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	if ((concat = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1))) == NULL)
		return (NULL);
	ft_strcpy(concat, s1);
	ft_strncat(concat, s2, l_s2);
	concat[l_s1 + l_s2] = '\0';
	return (concat);
}
