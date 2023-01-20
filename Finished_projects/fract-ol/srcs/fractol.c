/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:53:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		exit(0);
	init_struct(vars);
	check_args(argc, argv, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	mlx_key_hook(vars->win, &handle_key, vars);
	mlx_mouse_hook(vars->win, &handle_mouse, vars);
	mlx_hook(vars->win, DestroyNotify, 0, &handle_cross, vars);
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	clean_exit(vars);
}
