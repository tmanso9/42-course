/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:43:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_utils(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape || keysym == XK_q)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (keysym == XK_h)
	{
		if (vars->help)
			vars->help = 0;
		else
			vars->help = 1;
	}
	if (keysym == XK_c)
	{
		if (vars->color)
			vars->color = 0;
		else
			vars->color = 1;
	}
}

static void	move_and_zoom(int keysym, t_vars *vars)
{
	if (keysym == XK_Right || keysym == XK_d)
		vars->img.offset_x += 50;
	if (keysym == XK_Left || keysym == XK_a)
		vars->img.offset_x -= 50;
	if (keysym == XK_Up || keysym == XK_w)
		vars->img.offset_y -= 50;
	if (keysym == XK_Down || keysym == XK_s)
		vars->img.offset_y += 50;
	if (keysym == XK_r)
	{
		vars->img.zoom = 1.1;
		vars->img.offset_x = 0;
		if (vars->fractal == 1)
			vars->img.offset_x = -150;
		vars->img.offset_y = 0;
		vars->change_julia_im = 0;
		vars->change_julia_re = 0;
	}
	if (keysym == XK_f)
	{
		if (vars->follow_mouse)
			vars->follow_mouse = 0;
		else
			vars->follow_mouse = 1;
	}
}

int	handle_key(int keysym, t_vars *vars)
{
	key_utils(keysym, vars);
	move_and_zoom(keysym, vars);
	key_fractal_utils(keysym, vars);
	return (0);
}
