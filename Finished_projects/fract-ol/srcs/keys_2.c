/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:53:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_julia_values(int keysym, t_vars *vars)
{
	if (keysym == XK_period)
		vars->change_julia_im += .05;
	if (keysym == XK_comma)
		vars->change_julia_im -= .05;
	if (keysym == XK_semicolon)
		vars->change_julia_re += .05;
	if (keysym == XK_l)
		vars->change_julia_re -= .05;
}

static void	zero_to_three(int keysym, t_vars *vars)
{
	if (keysym == XK_0)
	{
		vars->julia_set = 0;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_1)
	{
		vars->julia_set = 1;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_2)
	{
		vars->julia_set = 2;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_3)
	{
		vars->julia_set = 3;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
}

static void	four_to_six(int keysym, t_vars *vars)
{
	if (keysym == XK_4)
	{
		vars->julia_set = 4;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_5)
	{
		vars->julia_set = 5;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_6)
	{
		vars->julia_set = 6;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
}

static void	key_julia_set(int keysym, t_vars *vars)
{
	zero_to_three(keysym, vars);
	four_to_six(keysym, vars);
}

void	key_fractal_utils(int keysym, t_vars *vars)
{
	if (keysym == XK_m)
	{
		if (vars->fractal == 2)
			vars->img.offset_x -= 150;
		vars->fractal = 1;
	}
	if (keysym == XK_j)
	{
		if (vars->fractal == 1)
			vars->img.offset_x += 150;
		vars->fractal = 2;
	}
	key_julia_set(keysym, vars);
	key_julia_values(keysym, vars);
}
