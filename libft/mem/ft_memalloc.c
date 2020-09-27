/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansiguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:18:03 by ansiguie          #+#    #+#             */
/*   Updated: 2018/11/08 15:30:57 by ansiguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_zone;

	if ((mem_zone = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(mem_zone, size);
	return (mem_zone);
}
