/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:10:03 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/14 17:10:11 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include "libft.h"
# define GNL_ERROR -1
# define GNL_READ 1
# define GNL_EOF 0

typedef struct	s_gnl
{
	int				fd;
	char			*content;
	char			*tmp;
	struct s_gnl	*next;
}				t_gnl;
t_gnl			*ft_new_elem(char *content, int fd);
void			ft_add_elem(t_gnl **alst, t_gnl *new);
t_gnl			*ft_get_elem(t_gnl **head, const int fd);
void			ft_del_elem(t_gnl **head);
char			*ft_strnjoin(char *s1, char *s2, int len2);
char			*ft_strncat_gnl(char *s1, const char *s2, int len);
char			*ft_strndup(char *src, int len);
#endif
