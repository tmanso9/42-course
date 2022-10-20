# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/10/20 01:27:52 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBC = ar -rc
SRCS = ft_printf.c \
		ft_print_text.c \
		ft_print_num.c \
		ft_print_x.c \
		ft_print_ptr.c

OBJS = ${SRCS:.c=.o}

HEAD = ft_printf.h

.c.o:
		${CC} ${FLAGS} ${HEAD} -c $<

RM = rm -f

${NAME}:	${OBJS}
			make -C Libft
			cp Libft/libft.a .
			mv libft.a ${NAME}
			${LIBC} ${NAME} ${OBJS}

all:	${NAME}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus libftprintf.a