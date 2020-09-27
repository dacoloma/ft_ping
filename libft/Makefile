# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:06:12 by dcoloma           #+#    #+#              #
#    Updated: 2019/09/05 14:38:58 by dcoloma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = includes

HEADER = includes/libft.h includes/ft_printf.h

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

vpath %c condition conv gnl ft_printf lst mem print str 

SRC =	ft_format.c \
		ft_get_flag.c \
		ft_init.c \
		ft_minilibft.c \
		ft_flags.c \
		ft_free_printf.c \
		ft_get_params.c \
		ft_prefix_signed.c \
		ft_wildcard.c \
		ft_is_prime.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_atoi.c \
		ft_atol.c \
		ft_hhtoa_base.c \
		ft_htoa_base.c \
		ft_itoa.c \
		ft_lftoa.c \
		ft_lltoa_base.c \
		ft_ltoa_base.c \
		ft_u_hhtoa_base.c \
		ft_u_htoa_base.c \
		ft_u_itoa_base.c \
		ft_u_ltoa_base.c \
		ft_u_lltoa_base.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_address.c \
		ft_print_decimal.c \
		ft_print_hexa.c \
		ft_print_octal.c \
		ft_print_udecimal.c \
		ft_print_char.c \
		ft_print_float.c \
		ft_print_modulo.c \
		ft_print_str.c \
		ft_printf.c \
		ft_putbuf.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putnbr_base.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_range.c \
		ft_sort_integer.c \
		ft_swap.c \
		ft_elem.c \
		ft_tabjoin.c\
		ft_strncat_gnl.c\
		ft_strnjoin.c\
		ft_strndup.c\
		get_next_line.c

DIR_OBJ = obj

OBJ = $(SRC:%.c=$(DIR_OBJ)/%.o)

.PHONY = all clean fclean re

all: $(NAME) $(OBJ)

$(DIR_OBJ): 
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)


$(NAME): $(DIR_OBJ) $(HEADER) $(SRC) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(DIR_OBJ)

re: fclean all
