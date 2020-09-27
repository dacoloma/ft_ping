/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:05:59 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/14 17:06:11 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	ft_get_elem_content(char *content, int fd, t_gnl **list)
{
	size_t	len;

	if (content == NULL)
		(*list)->content = NULL;
	else
	{
		len = ft_strlen(content);
		(*list)->content = (char *)malloc(sizeof(char) * (len + 1));
		if ((*list)->content == NULL)
		{
			free(*list);
			return (INVALID);
		}
		ft_strcpy((*list)->content, content);
	}
	(*list)->fd = fd;
	(*list)->tmp = NULL;
	(*list)->next = NULL;
	return (VALID);
}

t_gnl		*ft_new_elem(char *content, int fd)
{
	t_gnl	*list;

	list = (t_gnl *)malloc(sizeof(t_gnl));
	if (list == NULL)
		return (NULL);
	if (ft_get_elem_content(content, fd, &list) == INVALID)
		return (NULL);
	return (list);
}

void		ft_add_elem(t_gnl **alst, t_gnl *new)
{
	new->next = *alst;
	*alst = new;
}

void		ft_del_elem(t_gnl **head)
{
	t_gnl	*tmp;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		ft_strdel(&(*head)->content);
		free(*head);
		*head = tmp;
	}
}

t_gnl		*ft_get_elem(t_gnl **head, const int fd)
{
	t_gnl	*elem;

	elem = *head;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (elem == NULL)
	{
		elem = ft_new_elem(NULL, fd);
		if (elem == NULL)
		{
			ft_del_elem(&(elem));
			return (NULL);
		}
		ft_add_elem(head, elem);
	}
	return (elem);
}
