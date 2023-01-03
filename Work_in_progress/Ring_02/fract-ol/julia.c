/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:31:02 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/03 18:44:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(t_vars *vars, double x, double y)
{
	double	aa;
	double	bb;
	// double	z;
	int		i;
	double	bright;
	double		iterations;

	// z = 0;
	double	maxval = 1.2 * vars->img.x;
	double	minval = -1.2 * vars->img.x;
	// printf("zoom is %f\n", vars->img.offset_x);
	
	double	a = map(x, WIN_WIDTH - .1, minval, maxval);
	double	b = map(y, WIN_HEIGTH - .1, minval, maxval);

	i = 0;
	bright = 0;
	double	temp = vars->img.x;
	double	zoom_times = 1;
	while (temp > 1)
	{
		temp = temp / 1.2;
		zoom_times += 1;
	}
	iterations = 40 * (4 * zoom_times);
	// double	ca = map(vars->img.mousex, 0, WIN_WIDTH - .1, -1, 1);
	// double	cb = map(vars->img.mousey, 0, WIN_HEIGTH - .1, -1, 1);
	double	const_a[6];
	const_a[0] = -.4;
	const_a[1] = 0.285;
	const_a[2] = -0.70176;
	const_a[3] = -0.8;
	const_a[4] = -0.7269;
	const_a[5] = 0;
	double	const_b[6];
	const_b[0] = .6;
	const_b[1] = 0.01;
	const_b[2] = -0.3842;
	const_b[3] = 0.156;
	const_b[4] = 0.1889;
	const_b[5] = -0.8;
	double	ca;
	double	cb;
	if (vars->julia_set)
	{
		ca = const_a[vars->julia_set - 1];
		cb = const_b[vars->julia_set - 1];
	}
	else
	{
		ca = -.8;
		cb = 0;
	}
	// double	ca = -0.4;
	// double	cb = 0.6;
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
		if (fabs(aa) > 4.0)
			break ;
		a = aa + ca;
		b = bb + cb;
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

void	julia(t_vars *vars)
{
	double	x;
	double	y;
	int		bright;
	
	x = 0;
	y = 0;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGTH)
		{
			bright = get_color(vars, x, y);
			// printf("x %d, y %d, bright %d\n", x, y, bright);
			my_pixel_put(&vars->img, x, y, get_rgb(bright, bright, 100));
			y += 1;
		}
		x += 1;
		y = 0;
	}
}
