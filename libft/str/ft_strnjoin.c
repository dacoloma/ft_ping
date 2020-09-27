/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:49:00 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/21 17:49:02 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char *s2, int len2)
{
	char	*concat;
	int		len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	concat = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);
	ft_strcpy(concat, s1);
	ft_strncat_gnl(concat, s2, len2);
	concat[len1 + len2] = '\0';
	return (concat);
}
