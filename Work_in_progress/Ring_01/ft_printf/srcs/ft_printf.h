/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:47 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/08 18:52:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <inttypes.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		printed;
}	t_print;

int		ft_printf(const char *str, ...);
int		ft_print_c(t_print *tab);
int		ft_print_s(t_print *tab);
int		ft_print_i(t_print *tab);
int		ft_print_u(t_print *tab);
int		ft_print_x(t_print *tab, char format);
void	ft_puthex(unsigned int i, char format);
int		hex_digits(unsigned int i);
int		ft_print_ptr(t_print *tab);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);

#endif