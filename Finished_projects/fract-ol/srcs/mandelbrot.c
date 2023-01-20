/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:54:23 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:57 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
------THE LOOP WORKS BECAUSE------
f(z) = z^2 + c
starting at z = 0
f(z2) = c^2 + c
		c^2:
		(a + bi)^2
		a^2 - b^2 + 2(a + bi)
*/
static int	mandel_loop(t_fract *mandel, double iterations)
{
	int		i;
	double	aa;
	double	bb;

	i = 0;
	while (i < iterations)
	{
		aa = pow(mandel->real, 2) - pow(mandel->im, 2);
		bb = 2.0 * mandel->real * mandel->im;
		if (fabs(aa) > 25.0)
			break ;
		mandel->real = aa + mandel->ca;
		mandel->im = bb + mandel->cb;
		i++;
	}
	return (i);
}

int	get_color_mandel(t_vars *vars, double x, double y, double iterations)
{
	int		i;
	double	bright;
	t_fract	mandel;

	mandel.real = get_coords(x, vars->img.zoom, 'x');
	mandel.im = get_coords(y, vars->img.zoom, 'y');
	mandel.ca = mandel.real;
	mandel.cb = mandel.im;
	i = mandel_loop(&mandel, iterations);
	bright = map(i, iterations, 0, 1);
	bright = map(sqrt(bright), 1, 0, 255);
	if (i == (int)iterations)
		bright = 0;
	return (bright);
}

void	mandelbrot(t_vars *vars)
{
	do_fractal(vars, 'm');
}
