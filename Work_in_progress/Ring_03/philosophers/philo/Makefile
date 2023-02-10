# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/02/10 12:37:06 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -I incs -Wall -Wextra -Werror -g -pthread #-O3

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
else ifeq ($(THREAD), 1)
	CFLAGS += -fsanitize=thread
endif

SRC = philo.c ft_atoi.c utils.c parse_args.c args_valid.c ft_calloc.c actions.c \
	routine.c time_utils.c
OBJ = $(addprefix srcs/, $(SRC:.c=.o))

%.o: %.c incs/philo.h
	$(CC) -c $(CFLAGS) -o $@ $< 
	@echo "\033[33m[OK]	" $@ "\033[0m"

$(NAME): $(OBJ)
	@echo "------------------------------"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[92m[OK]	 philo ready to use\033[0m"
	@echo "------------------------------"

all: $(NAME)

clean:
	@rm -rf $(OBJ) $(B_OBJ)
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME) 2> /dev/null
	@echo "\033[31mExecutable deleted\033[0m"
	@echo ""

re: fclean all

.SILENT: $(OBJ)

.PHONY: all re clean fclean
