/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:31:02 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_loop(t_fract *julia, double iterations)
{
	int		i;
	double	aa;
	double	bb;

	i = 0;
	while (i < iterations)
	{
		aa = pow(julia->real, 2) - pow(julia->im, 2);
		bb = 2.0 * julia->real * julia->im;
		if (fabs(aa) > 16.0)
			break ;
		julia->real = aa + julia->ca;
		julia->im = bb + julia->cb;
		i++;
	}
	return (i);
}

static void	find_set(t_vars *vars, t_fract *julia)
{
	double	const_a[6];
	double	const_b[6];

	const_a[0] = -.4 + vars->change_julia_re;
	const_b[0] = .6 + vars->change_julia_im;
	const_a[1] = 0.285 + vars->change_julia_re;
	const_b[1] = -0.01 + vars->change_julia_im;
	const_a[2] = -0.70176 + vars->change_julia_re;
	const_b[2] = 0.3842 + vars->change_julia_im;
	const_a[3] = -0.8 + vars->change_julia_re;
	const_b[3] = 0.156 + vars->change_julia_im;
	const_a[4] = -0.7269 + vars->change_julia_re;
	const_b[4] = -0.1889 + vars->change_julia_im;
	const_a[5] = -0.835 + vars->change_julia_re;
	const_b[5] = 0.232 + vars->change_julia_im;
	if (vars->julia_set)
	{
		julia->ca = const_a[vars->julia_set - 1];
		julia->cb = const_b[vars->julia_set - 1];
	}
	else
	{
		julia->ca = -.8 + vars->change_julia_re;
		julia->cb = 0 + vars->change_julia_im;
	}
}

int	get_color_julia(t_vars *vars, double x, double y, double iterations)
{
	int		i;
	double	bright;
	t_fract	julia;

	julia.real = get_coords(x, vars->img.zoom, 'x');
	julia.im = get_coords(y, vars->img.zoom, 'y');
	find_set(vars, &julia);
	i = julia_loop(&julia, iterations);
	bright = map(i, iterations, 0, 1);
	bright = map(sqrt(bright), 1, 0, 255);
	if (i == (int)iterations)
		bright = 0;
	return (bright);
}

void	julia(t_vars *vars)
{
	do_fractal(vars, 'j');
}
