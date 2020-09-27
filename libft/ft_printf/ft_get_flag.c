/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:08:55 by dcoloma           #+#    #+#             */
/*   Updated: 2019/10/03 18:08:58 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_flag_index(const char *restrict *str, t_option *option)
{
	char	*flags;

	flags = "-+0 #";
	option->j = 0;
	while (flags[option->j] && flags[option->j] != **str)
		option->j++;
	if (flags[option->j] == '\0')
		return (0);
	return (1);
}

static void	ft_init(void (*flags[5])(const char *restrict *str,
	t_option *option, char *c))
{
	flags[0] = &ft_l_justify;
	flags[1] = &ft_sign;
	flags[2] = &ft_pad_zero;
	flags[3] = &ft_space;
	flags[4] = &ft_sharp;
}

int			ft_get_flag(const char *restrict *str, t_option *option, va_list ap)
{
	char	c;
	void	(*flags[5])(const char *restrict *str, t_option *option, char *c);

	(void)ap;
	ft_init(flags);
	while (**str && (**str == '-' || **str == '+' || **str == '0'
		|| **str == ' ' || **str == '#'))
	{
		if (!ft_get_flag_index(str, option))
		{
			return (0);
		}
		flags[option->j](str, option, &c);
		if (ft_is_type(option, **str) || ft_is_width(**str)
			|| ft_is_size(**str) || **str == '.')
		{
			return (1);
		}
	}
	return (0);
}
