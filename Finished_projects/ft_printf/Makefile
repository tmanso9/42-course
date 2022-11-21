# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/11/21 14:17:58 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus: ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} 

re:	fclean all

.PHONY: all clean fclean re bonus