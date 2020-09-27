/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:52:16 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/16 15:52:45 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *head_new_list;
	t_list *cur;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if ((head_new_list = ft_lstnew(elem->content, elem->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	cur = head_new_list;
	while (lst)
	{
		elem = f(lst);
		if ((cur->next = ft_lstnew(elem->content, elem->content_size)) == NULL)
			return (NULL);
		cur = cur->next;
		lst = lst->next;
	}
	return (head_new_list);
}
