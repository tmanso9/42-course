# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:46:50 by touteiro          #+#    #+#              #
#    Updated: 2022/11/08 16:48:13 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
SRCS = ft_printf.c \
		ft_print_text.c \
		ft_print_num.c \
		ft_print_num_2.c \
		ft_print_num_3.c \
		ft_print_x.c \
		ft_print_x_2.c \
		ft_print_x_3.c \
		ft_print_ptr.c \
		ft_struct_utils.c
OBJS = ${SRCS:.c=.o}
LIBFT = libft/libft.a

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