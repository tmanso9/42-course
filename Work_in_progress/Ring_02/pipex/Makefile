# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/01/15 02:05:40 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I incs/
# CFLAGS += -fsanitize=address
SRC = pipex.c parse_args.c utils.c execute.c
B_SRC = pipex_bonus.c parse_args_bonus.c utils_bonus.c \
		execute_bonus.c heredoc_bonus.c
OBJ = $(addprefix srcs/, $(SRC:.c=.o))
B_OBJ = $(addprefix srcs/bonus/, $(B_SRC:.c=.o))
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "- - - - - - - - - - - - - - - "
	@echo "Temporary object files ready"
	@make --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[92mpipex ready to use\033[0m"
	@echo "------------------------------"

bonus: $(B_OBJ)
	@echo "- - - - - - - - - - - - - - - "
	@echo "Temporary bonus object files ready"
	@make --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(B_OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[92mpipex ready to use\033[0m"
	@echo "------------------------------"

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	@rm -rf $(OBJ) $(B_OBJ)
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean libft_fclean
	@rm -rf $(NAME)
	@echo "\033[31mExecutable deleted\033[0m"

re: fclean all

.SILENT: $(OBJ) $(B_OBJ)

.PHONY: all bonus re libft clean fclean libft_clean libft_fclean
