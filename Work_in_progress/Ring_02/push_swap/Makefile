# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:21:29 by touteiro          #+#    #+#              #
#    Updated: 2023/01/19 03:54:08 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I incs -I libft/incs
#CFLAGS += -fsanitize=address -g3
RM = rm -f
SRCS = 	args_checker.c \
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
		utils.c \
		optimize.c
EXE = push_swap.c
CHE = checker.c checker_moves.c
HEADERS = push_swap.h
OBJS = ${addprefix srcs/, ${SRCS:.c=.o}}
OBJ_EXE = ${EXE:.c=.o}
OBJ_CHE = ${addprefix srcs/checker/, ${CHE:.c=.o}}
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[33m[OK]	" $@ "\033[0m"
	
$(NAME): $(OBJ_EXE) $(OBJS)
	@make --no-print-directory -C libft
	@echo "------------------------------"
	@$(CC) $(CFLAGS) $(OBJS) $(OBJ_EXE) -L libft/ -lft -o $(NAME)
	@echo "\033[92m[OK]	 push_swap ready to use\033[0m"
	@echo "------------------------------"

all: $(NAME)

bonus: checker

checker: $(NAME) $(OBJ_CHE)
	@$(CC) $(CFLAGS) $(OBJ_CHE) $(OBJS) -L libft/ -lft -o checker
	@echo "------------------------------"
	@echo "\033[92m[OK]	 checker ready to use\033[0m"
	@echo "------------------------------"

libft:
	@make --no-print-directory -C libft

libft_clean:
	@make --no-print-directory -C libft clean

libft_fclean:
	@make --no-print-directory -C libft fclean

clean: libft_clean
	@$(RM) $(OBJS) $(OBJ_EXE) $(OBJ_CHE)
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean libft_fclean
	@$(RM) $(NAME) checker
	@echo "\033[31mExecutable deleted\033[0m"

re: fclean all bonus

.SILENT: $(OBJS) $(OBJ_EXE) $(OBJ_CHE)

.PHONY: all libft clean fclean libft_clean libft_fclean bonus
