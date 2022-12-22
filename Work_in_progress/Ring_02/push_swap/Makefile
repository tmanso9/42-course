# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:21:29 by touteiro          #+#    #+#              #
#    Updated: 2022/12/22 22:06:24 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address -g3
RM = rm -f
SRCS = args_checker.c \
		args_valid.c \
		buffer_write.c \
		five_stack.c \
		four_stack_b.c \
		moves.c \
		quicksort_a.c \
		quicksort_b.c \
		stack_utils.c \
		three_stack_b.c \
		three_stack.c \
		two_stack_b.c \
		two_stack.c \
		utils_b.c \
		utils.c
HEADERS = push_swap.h
OBJS = ${SRCS:.c=.o}
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) push_swap.o
	@echo "- - - - - - - - - - - - - - - "
	@echo "Temporary object files created"
	@make --no-print-directory -C libft
	@$(CC) $(CFLAGS) push_swap.o $(OBJS) -L libft/ -lft -o $(NAME)
	@echo "\033[92mpush_swap ready to use\033[0m"
	@echo "------------------------------"

checker: $(OBJS) checker.o
	@$(CC) $(CFLAGS) checker.o $(OBJS) -L libft/ -lft -o checker

libft:
	@make --no-print-directory -C libft

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	@$(RM) $(OBJS) push_swap.o checker.o
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean libft_fclean
	@$(RM) $(NAME) checker
	@echo "\033[31mExecutable deleted\033[0m"

re: fclean all checker

.SILENT: $(OBJS)

.PHONY: all libft clean fclean libft_clean libft_fclean checker
