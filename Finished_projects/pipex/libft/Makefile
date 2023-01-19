# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:29:50 by touteiro          #+#    #+#              #
#    Updated: 2023/01/19 19:49:19 by touteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I incs
#CFLAGS += -fsanitize=address -g3
LIBC = ar -rcs
LIBFT_SRCS = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint ft_itoa ft_lstadd_back ft_lstadd_front \
			ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstmap \
			ft_lstnew ft_lstsize ft_memchr ft_memcmp ft_memcpy ft_memmove \
			ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
			ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat \
			ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
			ft_strtrim ft_substr ft_tolower ft_toupper
			
GNL_SRCS = get_next_line_bonus get_next_line_utils_bonus

PRINTF_SRCS = ft_utils ft_struct_utils ft_printf \
			ft_print_x ft_print_x_2 ft_print_x_3 \
			ft_print_text ft_print_ptr \
			ft_print_num ft_print_num_2 ft_print_num_3
			
LIBFT_OBJS = $(addprefix srcs/libft/, ${LIBFT_SRCS:=.o})
GNL_OBJS = $(addprefix srcs/get_next_line/, ${GNL_SRCS:=.o})
PRINTF_OBJS = $(addprefix srcs/ft_printf/, ${PRINTF_SRCS:=.o})
OBJS = ${LIBFT_OBJS} ${GNL_OBJS} ${PRINTF_OBJS}

${NAME}:	${OBJS}
			@${LIBC} ${NAME} ${OBJS}
			@echo "\033[33m[OK]	" $@ "\033[0m"

all: ${NAME}

clean:
		@rm -rf ${OBJS} ${BONUS_OBJS}

fclean:	clean
		@rm -rf ${NAME}

re:	fclean all

.SILENT: ${OBJS}

.PHONY: all clean fclean re