/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:47:18 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/08 15:47:20 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_l_justify(const char *restrict *str, t_option *option, char *c)
{
	option->l_justify = 1;
	option->pad_zero = ' ';
	*str = *str + 1;
	*c = **str;
}

void	ft_sign(const char *restrict *str, t_option *option, char *c)
{
	if (option->sharp == 0)
	{
		option->sign = 1;
		option->space = 0;
	}
	*str = *str + 1;
	*c = **str;
}

void	ft_pad_zero(const char *restrict *str, t_option *option, char *c)
{
	if (option->l_justify == 0)
		option->pad_zero = '0';
	*str = *str + 1;
	*c = **str;
}

void	ft_space(const char *restrict *str, t_option *option, char *c)
{
	if (option->sign == 0 && option->sharp == 0)
		option->space = 1;
	*str = *str + 1;
	*c = **str;
}

void	ft_sharp(const char *restrict *str, t_option *option, char *c)
{
	option->sharp = 1;
	option->sign = 0;
	option->space = 0;
	*str = *str + 1;
	*c = **str;
}
