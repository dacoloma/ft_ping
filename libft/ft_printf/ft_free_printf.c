/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:03:31 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/09 13:03:34 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free_printf(t_option *option)
{
	option->size = 0;
	option->width = 0;
	option->l_justify = 0;
	option->sign = 0;
	option->pad_zero = ' ';
	option->space = 0;
	option->sharp = 0;
	option->precision = 6;
	option->def_precision = 0;
	option->f_precision = 0;
	option->neg = 0;
	free(option->data);
}
