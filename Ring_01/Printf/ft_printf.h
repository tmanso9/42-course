/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:47 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/20 01:37:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "Libft/libft.h"
# include <limits.h>
# include <inttypes.h>

int	ft_printf(const char *str, ...);
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_i(int i);
int	ft_print_u(unsigned int i);
int	ft_print_x(unsigned int i, char format);
int	ft_print_ptr(uintptr_t i);

#endif