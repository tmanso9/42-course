# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 15:48:37 by touteiro          #+#    #+#              #
#    Updated: 2023/01/20 11:56:47 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincs
#CFLAGS += -fsanitize=address
SRC = fractol.c \
	check_args.c \
	utils.c \
	struct_utils.c \
	handles.c \
	keys.c \
	keys_2.c \
	draw.c \
	zoom.c \
	fractal_math.c \
	mandelbrot.c \
	julia.c
OBJ = $(addprefix srcs/, $(SRC:.c=.o))
LIBFT = libft/libft.a

%.o: %.c incs/fractol.h
	$(CC) -c $(CFLAGS) -I/usr/include -Imlx_linux -O3 -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "- - - - - - - - - - - - - - - "
	@echo "Temporary object files created"
	@make --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[92mfractol ready to use\033[0m"
	@echo "------------------------------"

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	@rm -rf $(OBJ)
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean libft_fclean
	@rm -rf $(NAME)
	@echo "\033[31mExecutable deleted\033[0m"

re: fclean all

# .SILENT: $(OBJ)

.PHONY: all libft clean fclean libft_clean libft_fclean
