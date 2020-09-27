/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:24:45 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/14 18:24:48 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

int	ft_is_width(char c)
{
	return (c == '*' || (c >= '1' && c <= '9'));
}

int	ft_is_dot(char c)
{
	return (c == '.');
}

int	ft_is_size(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int	ft_is_type(t_option *option, char c)
{
	option->i = 0;
	while (option->letter[option->i] && option->letter[option->i] != c)
		option->i++;
	return (option->letter[option->i] != '\0');
}
