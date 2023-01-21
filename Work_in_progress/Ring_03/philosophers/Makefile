# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/01/20 20:16:25 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread
# CFLAGS += -fsanitize=address
SRC = philo.c
# B_SRC = 
OBJ = $(addprefix srcs/, $(SRC:.c=.o))
# B_OBJ = $(addprefix srcs/bonus/, $(B_SRC:.c=.o))

%.o: %.c incs/philo.h
	$(CC) -c $(CFLAGS) -o $@ $< 
	@echo "\033[33m[OK]	" $@ "\033[0m"

$(NAME): $(OBJ)
	@echo "------------------------------"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[92m[OK]	 philo ready to use\033[0m"
	@echo "------------------------------"

all: $(NAME)

bonus: $(B_OBJ)
	@echo "------------------------------"
	@$(CC) $(CFLAGS) $(B_OBJ) -o $(NAME)
	@echo "\033[92m[OK]	 philo ready to use\033[0m"
	@echo "------------------------------"

clean:
	@rm -rf $(OBJ) $(B_OBJ)
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mExecutable deleted\033[0m"
	@echo ""

re: fclean all

# .SILENT: $(OBJ) $(B_OBJ)

.PHONY: all bonus re clean fclean
