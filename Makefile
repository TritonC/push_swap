# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:12:56 by mluis-fu          #+#    #+#              #
#    Updated: 2022/11/16 21:19:22 by mluis-fu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

INCLUDES = -I inc/libft/include

CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -g3

FILES = atoi_pos.c list_assets.c operations.c utils.c main.c

OBJECTS = $(FILES:.c=.o)

LIBFT-DIR = inc/libft

LIBFT_MAKE = inc/libft/libft.a

all: $(NAME)

$(LIBFT_MAKE): | $(LIBFT-DIR)
	make -C $(LIBFT-DIR)

$(NAME): $(OBJECTS) $(LIBFT_MAKE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_MAKE)

clean:
	make clean -C $(LIBFT-DIR)
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make fclean -C $(LIBFT-DIR)
	rm -f $(NAME) $(OBJECTS_BONUS)

re: fclean all

.PHONY:	re clean fclean all bonus