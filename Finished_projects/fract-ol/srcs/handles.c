/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:00:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/09 18:47:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	render(t_vars *vars)
{
	if (!vars->win)
		return (1);
	if (vars->fractal == 1)
		mandelbrot(vars);
	if (vars->fractal == 2)
		julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	print_help(vars);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		zoom_out(vars, x, y);
	if (button == 5)
		zoom_in(vars, x, y);
	return (0);
}

int	handle_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
	return (0);
}
