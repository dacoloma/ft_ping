/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:06:30 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/14 17:06:57 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char	**ft_tabcpy(char **dest, char **src)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (src[i])
	{
		j = 0;
		len = ft_strlen(src[i]);
		if (!(dest[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (src[i][j])
		{
			dest[i][j] = src[i][j];
			j++;
		}
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static char	**ft_tabncat(char **dest, char **src, int len_src)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = ft_tablen(dest);
	j = 0;
	while (j < len_src)
	{
		len = ft_strlen(src[j]);
		if (!(dest[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		k = 0;
		while (src[j][k])
		{
			dest[i][k] = src[j][k];
			k++;
		}
		dest[i][k] = '\0';
		i++;
		j++;
	}
	dest[i] = NULL;
	return (dest);
}

char		**ft_tabjoin(char **tab1, char **tab2)
{
	char	**tab;
	int		len1;
	int		len2;

	if (!tab1 || !tab2)
		return (NULL);
	len1 = ft_tablen(tab1);
	len2 = ft_tablen(tab2);
	tab = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (tab == NULL)
		return (NULL);
	ft_tabcpy(tab, tab1);
	ft_tabncat(tab, tab2, len2);
	tab[len1 + len2] = NULL;
	return (tab);
}
