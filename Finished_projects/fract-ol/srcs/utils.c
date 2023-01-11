/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:27:18 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/09 19:31:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	list_fractal_commands(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 200, 53, \
		get_rgb(255, 255, 255), "mandelbrot:                 m");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 200, 66, \
		get_rgb(255, 255, 255), "julia:                      j");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 200, 79, \
		get_rgb(255, 255, 255), "change julia set:       0 - 6");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 200, 92, \
		get_rgb(255, 255, 255), "change seed:          . , ; l");
}

void	list_window_commands(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 40, 40, get_rgb(255, 255, 255), \
		"quit:                      ESC / q");
	mlx_string_put(vars->mlx, vars->win, 40, 53, get_rgb(255, 255, 255), \
		"move around:     arrow keys / wasd");
	mlx_string_put(vars->mlx, vars->win, 40, 66, get_rgb(255, 255, 255), \
		"zoom in / out:         mouse wheel");
	mlx_string_put(vars->mlx, vars->win, 40, 79, get_rgb(255, 255, 255), \
		"reset view:                      r");
	mlx_string_put(vars->mlx, vars->win, 40, 92, get_rgb(255, 255, 255), \
		"change color scheme:             c");
	mlx_string_put(vars->mlx, vars->win, 40, 105, get_rgb(255, 255, 255), \
		"toggle zoom follow mouse:        f");
}

void	print_help(t_vars *vars)
{
	if (vars->help)
	{
		mlx_string_put(vars->mlx, vars->win, 40, 20, get_rgb(255, 255, 255), \
			"AVAILABLE COMMANDS");
		list_window_commands(vars);
		list_fractal_commands(vars);
	}
	else
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 70, WIN_HEIGHT - 8, \
			get_rgb(255, 255, 255), "h for help");
}
