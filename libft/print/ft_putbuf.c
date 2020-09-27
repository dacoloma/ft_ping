/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:41:19 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/10 17:41:22 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuf(t_option *option)
{
	int	i;

	i = 0;
	while (i < option->len || option->buffer[i] != '\0')
		ft_putchar(option->buffer[i++]);
}
