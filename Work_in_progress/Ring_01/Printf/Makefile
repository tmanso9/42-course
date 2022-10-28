# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/10/28 17:26:08 by touteiro         ###   ########.fr        #
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
BONUS = ft_printf_bonus.c \
		ft_print_text_bonus.c \
		ft_print_num.c \
		ft_print_x.c \
		ft_print_ptr.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

HEAD = ft_printf.h
BONUS_HEAD = ft_printf_bonus.h

.c.o:
		${CC} ${FLAGS} -c $<

RM = rm -f

all:	${NAME}

${NAME}:	${OBJS}
			make -C Libft
			cp Libft/libft.a .
			mv libft.a ${NAME}
			${LIBC} ${NAME} ${OBJS}


#bonus:	${BONUS_OBJS}
#		make -C Libft
#		cp Libft/libft.a .
#		mv libft.a ${NAME}
#		${LIBC} ${NAME} ${BONUS_OBJS}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus