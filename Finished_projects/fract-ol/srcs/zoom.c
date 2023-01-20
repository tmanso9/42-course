/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:26:53 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:46:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_vars *vars, int x, int y)
{
	vars->img.zoom /= 1.1;
	vars->img.offset_x *= 1.1;
	vars->img.offset_y *= 1.1;
	if (vars->follow_mouse)
	{
		vars->img.offset_x += ((x - WIN_WIDTH / 2) * .1);
		vars->img.offset_y += ((y - WIN_HEIGHT / 2) * .1);
	}
}

void	zoom_out(t_vars *vars, int x, int y)
{
	vars->img.zoom *= 1.1;
	vars->img.offset_x /= 1.1;
	vars->img.offset_y /= 1.1;
	if (vars->follow_mouse)
	{
		vars->img.offset_x -= ((x - WIN_WIDTH / 2) * .1);
		vars->img.offset_y -= ((y - WIN_HEIGHT / 2) * .1);
	}
}
