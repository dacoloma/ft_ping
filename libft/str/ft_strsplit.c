/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:24:43 by dcoloma           #+#    #+#             */
/*   Updated: 2018/11/15 13:57:59 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_char_count(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static void	ft_free_tab(char **tab, int len)
{
	int	i;

	if (tab != NULL)
	{
		i = 0;
		while (i < len)
			ft_strdel(&tab[i++]);
		free(tab);
	}
}

static int	ft_get_str(char **tab, int len, char const *s, char split)
{
	int	i;
	int	wd_index;

	i = 0;
	wd_index = 0;
	while (s[i] && wd_index < len)
	{
		while (s[i] == split)
			i++;
		tab[wd_index] = ft_strsub(s, i, ft_char_count(s, split, i));
		if (tab[wd_index] == NULL)
		{
			ft_free_tab(tab, wd_index);
			return (INVALID);
		}
		while (s[i] && s[i] != split)
			i++;
		wd_index++;
	}
	tab[wd_index] = NULL;
	return (VALID);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_word_count(s, c);
	if (len == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (tab == NULL)
		return (NULL);
	if (ft_get_str(tab, len, s, c) == INVALID)
	{
		ft_free_tab(tab, len);
		return (NULL);
	}
	return (tab);
}
