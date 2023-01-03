# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 15:48:37 by touteiro          #+#    #+#              #
#    Updated: 2023/01/03 18:48:09 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
#CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address -g3
SRC = new_main.c \
	utils.c \
	draw.c \
	shapes.c \
	render.c \
	mandelbrot.c \
	julia.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C libft
	$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	rm -rf $(OBJ)

fclean: clean libft_fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all libft clean fclean libft_clean libft_fclean
