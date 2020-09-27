# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 11:38:55 by dcoloma           #+#    #+#              #
#    Updated: 2019/10/30 13:37:43 by dcoloma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ping

HEADER = libft/includes

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror 

SRC = ft_ping.c

DIR_OBJ = obj

OBJ = $(SRC:%.c=$(DIR_OBJ)/%.o)

.PHONY = all clean fclean re

all: $(DIR_OBJ) $(NAME) $(CHECKER)

$(DIR_OBJ): 
	mkdir -p $(DIR_OBJ)

$(LIBFT) : FORCE
	$(MAKE) -C libft/

FORCE:

$(DIR_OBJ)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) -g $(OBJ) -L libft/ -lft -I $(HEADER)

clean:
	$(MAKE) clean -C libft/
	$(RM) -r $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) -C libft/ fclean

re: fclean all
