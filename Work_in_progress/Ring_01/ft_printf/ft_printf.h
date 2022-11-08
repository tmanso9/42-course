/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:47 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/07 18:05:50 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>
# include <inttypes.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		printed;
	int		width;
	int		precision;
	int		dot;
	int		dash;
	int		zero;
	int		cardinal;
	int		space;
	int		plus;
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
int		initial_str_loop(t_print *tab, const char *str, int i);
t_print	*initialize_struct(t_print *tab);
void	ft_process_i_dash(t_print *tab, char *str, int len, int i);
void	ft_process_i_width(t_print *tab, char *str, int len, int i);
void	ft_process_i_dot(t_print *tab, char *str, int len, int i);
void	ft_process_x_dash(t_print *tab, unsigned int num, char format, int i);
void	ft_process_x_width(t_print *tab, unsigned int num, char format, int i);
void	ft_process_x_dot(t_print *tab, unsigned int num, char format, int i);

#endif