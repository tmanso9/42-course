/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:04:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/04 17:55:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	offset_check(t_rect *rect)
{
	//printf("%f %f\n", rect->x, rect->width);
	if (in_bounds(rect->x, rect->y))
		return ;
	while (rect->x < 0)
	{
		rect->x += .5;
		rect->width -= 1.1;
	}
	while (rect->y < 0)
	{
		rect->y += .5;
		rect->height -= 1.1;
	}
	while (rect->x > WIN_WIDTH - 1)
	{
		rect->x -= .5;
		rect->width += 1.1;
	}
	while (rect->y >= WIN_HEIGTH - 1)
	{
		rect->y -= .5;
		rect->height += 1.1;
	}
	offset_check(rect);
}

void	rectangle(t_vars *vars, t_rect rect)
{
	double	i;
	double	j;

	if (!vars->win)
		return ;
	offset_check(&rect);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width && in_bounds(j, i))
		{
			my_pixel_put(&vars->img, j, i, rect.color);
			j = j + 1;
		}
		i = i + 1;
	}
}

void	circle(t_vars *vars, t_circle circ)
{
	double	i;
	double	j;

	i = -1;
	j = -1;
	while (sqrt(pow(++i, 2) + pow(j, 2)) < circ.r)
	{
		while (sqrt(pow(i, 2) + pow(++j, 2)) < circ.r)
		{
			if (in_bounds(circ.x + i, circ.y + j))
				my_pixel_put(&vars->img, circ.x + i, circ.y + j, circ.color);
			if (in_bounds(circ.x - i, circ.y - j))
				my_pixel_put(&vars->img, circ.x - i, circ.y - j, circ.color);
			if (in_bounds(circ.x + i, circ.y - j))
				my_pixel_put(&vars->img, circ.x + i, circ.y - j, circ.color);
			if (in_bounds(circ.x - i, circ.y + j))
				my_pixel_put(&vars->img, circ.x - i, circ.y + j, circ.color);
		}
		j = -1;
	}
}
