# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/03/25 12:53:27 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
PFLAGS = -I incs -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
SRC_FILE = main.cpp errorManagement.cpp replaceStrings.cpp
SRC = $(addprefix src/, $(SRC_FILE))
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
INC = incs/replace.hpp

obj/%.o: %.cpp $(INC)
	mkdir -p $(@D)
	$(CC) $(PFLAGS) -c $< -o $@ 
	@echo "\033[33m[OK]	" $@ "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(PFLAGS) $(OBJ) -o $(NAME)
	@echo -n "\033[92m[OK]	 "
	@echo -n $(NAME)
	@echo " ready to use\033[0m"
	@echo "------------------------------"

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf obj
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mExecutable deleted\033[0m"
	@echo ""

re: fclean all

.SILENT: $(OBJ)

.PHONY: all re clean fclean
