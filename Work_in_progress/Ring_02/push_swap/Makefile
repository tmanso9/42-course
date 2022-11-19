# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:21:29 by touteiro          #+#    #+#              #
#    Updated: 2022/11/19 01:19:41 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
##DONT FORGET TO REMOVE SANITIZE
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3 -fsanitize=address
RM = rm -f
SRCS = ${wildcard srcs/push_swap/*.c}
HEADERS = ${wildcard incs/*.h}
OBJS = ${SRCS:.c=.o}
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): libft $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) srcs/push_swap.c -L. -lft  $(OBJS) -o $(NAME)

libft:
	@make --no-print-directory -C libft
	@cp $(LIBFT) .

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libft.a $(LIBFT)

.PHONY: all libft clean fclean
