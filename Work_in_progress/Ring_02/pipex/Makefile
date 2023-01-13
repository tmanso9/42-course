# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/01/13 19:08:36 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -I incs/
# CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -fsanitize=address
SRC = pipex.c parse_args.c utils.c execute.c
OBJ = $(addprefix srcs/, $(SRC:.c=.o))
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "- - - - - - - - - - - - - - - "
	@echo "Temporary object files created"
	@make --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[92mpipex ready to use\033[0m"
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

.SILENT: $(OBJ)

.PHONY: all libft clean fclean libft_clean libft_fclean
