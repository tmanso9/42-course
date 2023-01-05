/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:14:53 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/05 20:18:20 by touteiro         ###   ########.fr       */
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

double	get_coords(double x, double zoom)
{
	return (map(x, WIN_WIDTH - 1, -zoom, zoom));
}

double	calc_iterations(t_vars *vars, double iterations)
{
	double	temp;

	temp = vars->img.x;
	iterations = 70;
	while (temp < 1)
	{
		temp = temp * 1.1;
		iterations += 1;
	}
	return (iterations);
}

void	do_fractal(t_vars *vars, char set)
{
	int		x;
	int		y;
	int		bright;
	double	iterations;

	x = 0;
	y = 0;
	iterations = calc_iterations(vars, iterations);
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			if (set == 'm')
				bright = get_color_mandel(vars, x + vars->img.offset_x, \
					y + vars->img.offset_y, iterations);
			else
				bright = get_color_julia(vars, x + vars->img.offset_x, \
					y + vars->img.offset_y, iterations);
			my_pixel_put(&vars->img, x, y, get_rgb(bright, bright, 100));
			y++;
		}
		x++;
		y = 0;
	}
}
