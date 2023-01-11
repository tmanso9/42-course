/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:03:18 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/09 18:46:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	init_struct(t_vars *vars)
{
	vars->img.zoom = 1.1;
	vars->fractal = 1;
	vars->julia_set = 0;
	vars->follow_mouse = 1;
	vars->color = 0;
	vars->help = 0;
	vars->change_julia_im = 0;
	vars->change_julia_re = 0;
	vars->img.offset_y = 0;
	vars->mlx = 0;
}

void	clean_exit(t_vars *vars)
{
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
	exit(0);
}
