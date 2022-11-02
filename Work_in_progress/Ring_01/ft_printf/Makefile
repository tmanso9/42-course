# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/11/02 17:01:30 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
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
LIBFT = libft/libft.a
HEAD = ft_printf.h
#BONUS_HEAD = ft_printf_bonus.h

RM = rm -f

all:	${NAME}

${NAME}:	process_libprintf

process_libprintf:	libft.a ${OBJS}
					cp ${LIBFT} .
					mv libft.a ${NAME}
					${LIBC} ${NAME} ${OBJS}

libft.a:
		cd libft && ${MAKE} all

#bonus:	${BONUS_OBJS}
#		make -C Libft
#		cp Libft/libft.a .
#		mv libft.a ${NAME}
#		${LIBC} ${NAME} ${BONUS_OBJS}

clean:	lib_clean
		${RM} ${OBJS}

lib_clean:
		cd libft && ${MAKE} clean

lib_fclean:
		cd libft && ${MAKE} fclean

fclean:	clean lib_fclean
		${RM} ${NAME} 

re:	fclean all

.PHONY: all clean fclean re bonus