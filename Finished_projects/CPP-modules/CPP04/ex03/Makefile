# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:28:45 by touteiro          #+#    #+#              #
#    Updated: 2023/04/14 23:58:23 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Interface
CC = c++
PFLAGS = -I incs -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
SRC_FILE =	main.cpp AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp Character.cpp \
			IMateriaSource.cpp MateriaSource.cpp LinkedList.cpp Node.cpp
INC_FILES = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp \
			IMateriaSource.hpp MateriaSource.hpp LinkedList.hpp Node.hpp

SRC = $(addprefix src/, $(SRC_FILE))
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
INC = $(addprefix incs/, $(INC_FILES))

obj/%.o: %.cpp $(INC)
	@mkdir -p $(@D)
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
