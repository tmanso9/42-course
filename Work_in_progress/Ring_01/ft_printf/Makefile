# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/11/04 18:42:09 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
SRCS = ft_printf.c \
		ft_print_text.c \
		ft_print_num.c \
		ft_print_num_2.c \
		ft_print_x.c \
		ft_print_ptr.c \
		ft_struct_utils.c
BONUS = ft_printf_bonus.c \
		ft_print_text_bonus.c ##\
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

${NAME}:	libft.a ${OBJS}
			cp ${LIBFT} .
			mv libft.a ${NAME}
			${LIBC} ${NAME} ${OBJS}

libft.a:
		cd libft && ${MAKE}

bonus:	${NAME}

clean:	lib_clean
		${RM} ${OBJS} ${BONUS_OBJS}

lib_clean:
		cd libft && ${MAKE} clean

lib_fclean:
		cd libft && ${MAKE} fclean

fclean:	clean lib_fclean
		${RM} ${NAME} 

re:	fclean all

.PHONY: all clean fclean re bonus