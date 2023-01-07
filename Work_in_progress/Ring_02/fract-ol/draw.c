/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:03:09 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/07 00:22:39 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	in_bounds(int x, int y)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		return (1);
	return (0);
}

void	palette(t_vars *vars, int bright, double x, double y)
{
	if (bright == 0)
		my_pixel_put(&vars->img, x, y, get_rgb(155, 30, 245));
	else if (bright < 55)
		my_pixel_put(&vars->img, x, y, get_rgb(10, bright * .5, bright * .6));
	else if (bright < 85)
		my_pixel_put(&vars->img, x, y, get_rgb(10, bright * .7, bright * .8));
	else if (bright < 170)
		my_pixel_put(&vars->img, x, y, get_rgb(10, bright * .8, bright * .9));
	else
		my_pixel_put(&vars->img, x, y, get_rgb(0, bright * .9, bright * .9));
}
