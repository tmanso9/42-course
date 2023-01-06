/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:26:53 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/06 00:52:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_vars *vars, int x, int y)
{
	vars->img.x /= 1.1;
	vars->img.offset_x *= 1.1;
	vars->img.offset_y *= 1.1;
	
	// printf("%d %d DIFF %d | %d %d DIFF %d\n", x, WIN_WIDTH, x - WIN_WIDTH / 2, y, WIN_HEIGHT, y - WIN_HEIGHT / 2);
	// printf("Offset x: %f | offset y: %f\n", vars->img.offset_x, vars->img.offset_y);
	// printf("Zoom x: %f\n", vars->img.x);
	
	// vars->img.y *= 1.2;
	// vars->img.offset_x += (x - WIN_WIDTH / 2);
	// vars->img.offset_y += (y - WIN_HEIGHT / 2);
	// printf("Offset x: %f | offset y: %f\n", vars->img.offset_x, vars->img.offset_y);
	// printf("Zoom x: %f\n", vars->img.x);
}

void	zoom_out(t_vars *vars, int x, int y)
{
	vars->img.x *= 1.1;
	vars->img.offset_x /= 1.1;
	vars->img.offset_y /= 1.1;
	// vars->img.y /= 1.2;
	// vars->img.offset_x += (x - WIN_WIDTH / 2);
	// vars->img.offset_y += (y - WIN_HEIGHT / 2);
}