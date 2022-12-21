/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:54:23 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/21 20:20:53 by touteiro         ###   ########.fr       */
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
	double	maxval = 1.2;
	double	minval = -1.7;
	// printf("zoom is %f\n", vars->img.offset_x);
	
	double	a = map(x, 0, WIN_WIDTH - .1, minval, maxval);
	double	b = map(y, 0, WIN_HEIGTH - .1, minval, maxval);
	double	ca = a;
	double	cb = b;
	i = 0;
	bright = 0;
	iterations = 50;
	// printf("here\n");
	while (i < iterations)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (abs(a + b) > 16)
			break ;
		i++;
	}

	bright = map(i, 0, iterations, 0, 1);
	bright = map(sqrt(bright), 0, 1, 0, 255);
	
	if (i == iterations)
		bright = 0;
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
			my_pixel_put(&vars->img, x, y, get_rgb(bright, bright, bright));
			y += .1;
		}
		x += .1;
		y = 0;
	}
}
