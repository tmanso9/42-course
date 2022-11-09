# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/11/09 00:53:02 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ${wildcard srcs/*.c}
BONUS_SRCS = ${wildcard bonus/*.c}
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all:	${NAME}

${NAME}: ${BONUS_OBJS}
		ar rcs ${NAME} ${BONUS_OBJS}

bonus: ${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME} 

re:	fclean all

.PHONY: all clean fclean re bonus