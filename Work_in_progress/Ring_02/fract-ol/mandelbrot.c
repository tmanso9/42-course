/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:54:23 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/26 18:00:42 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static int	get_color(t_vars *vars, double x, double y)
{
	double	aa;
	double	bb;
	// double	z;
	int		i;
	double		bright;
	int		iterations;

	// z = 0;
	double	maxval = 1.2 * vars->img.y;
	double	minval = -1.7 * vars->img.x;
	// printf("zoom is %f\n", vars->img.offset_x);
	
	double	a = map(x, 0, WIN_WIDTH - .1, minval, maxval);
	double	b = map(y, 0, WIN_HEIGTH - .1, minval, maxval);
	double	ca = a;
	double	cb = b;
	i = 0;
	bright = 0;
	iterations = 75;
	// printf("here\n");
	/*
	f(z) = z^2 + c
	starting at z = 0
	f(z2) = c^2 + c
			c^2:
			(a + bi)^2
			a^2 - b^2 + 2(a + bi)
	*/
	while (i < iterations)
	{
		aa = a * a - b * b;
		bb = 2.0 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (abs(aa) > 16.0)
			break ;
		i++;
	}

	bright = map(i, 0, iterations, 0, 1);
	bright = map(sqrt(bright), 0, 1, 0, 255);

	if (i == iterations)
		bright = 0;
	// else if (i >= 0 && i <85)
	// 	bright += 30;
	// else if (i >= 85 && i < 170)
	// 	bright += 50;
	return (bright);
}


void	mandelbrot(t_vars *vars)
{
	double	x;
	double	y;
	int	bright;
	
	x = 0;
	y = 0;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGTH)
		{
			bright = get_color(vars, x, y);
			// printf("x %d, y %d, bright %d\n", x, y, bright);
			my_pixel_put(&vars->img, x, y, get_rgb(100, bright, 210));
			y += .1;
		}
		x += .1;
		y = 0;
	}
}
