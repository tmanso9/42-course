# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/04/06 15:12:02 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
PFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

obj/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -c $(PFLAGS) -o $@ $< 
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
	@rm -rf obj/
	@echo "\033[31mTemporary object files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mExecutable deleted\033[0m"

newLine:
	@echo ""

re: fclean newLine all

.SILENT: $(OBJ)

.PHONY: all re clean fclean
