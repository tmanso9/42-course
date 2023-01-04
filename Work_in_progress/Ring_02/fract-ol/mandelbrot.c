/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:54:23 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/04 18:35:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * > It takes a value, a maximum out value, a minimum out value, and a maximum
 * in value, and returns a value that
 * is scaled to the new range.
 */
double	map(double x, double in_max, double out_min, double out_max)
{
	return ((x * (out_max - out_min) / in_max) + out_min);
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
	double	maxval = 1.2 * vars->img.x;
	double	minval = -1.2 * vars->img.x;
	// printf("zoom is %f\n", vars->img.offset_x);
	
	double	a = map(x + vars->img.offset_x, WIN_WIDTH - .1, minval, maxval);
	double	b = map(y + vars->img.offset_y, WIN_HEIGTH - .1, minval, maxval);
	double	ca = a;
	double	cb = b;
	i = 0;
	bright = 0;
	double	temp = vars->img.x;
	double	zoom_times = 1;
	while (temp > 1)
	{
		temp = temp / 1.1;
		zoom_times += 1;
	}
	iterations = 40 * 1.1 * zoom_times;
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
		if (fabs(aa) > 16.0)
			break ;
		i++;
	}

	bright = map(i, iterations, 0, 1);
	bright = map(sqrt(bright), 1, 0, 255);

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
			my_pixel_put(&vars->img, x, y, get_rgb(bright, bright, 100));
			y += .5;
		}
		x += .5;
		y = 0;
	}
}
