/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:09:03 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 17:57:39 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
