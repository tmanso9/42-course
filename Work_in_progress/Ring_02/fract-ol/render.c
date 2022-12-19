/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:26:53 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/17 01:52:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_vars *vars)
{
	vars->img.x *= 1.2;
	vars->img.y *= 1.2;
//	vars->img.offset_x -= 2;
//	vars->img.offset_y -= 2;
}

void	zoom_out(t_vars *vars)
{
	vars->img.x /= 1.2;
	vars->img.y /= 1.2;
//	vars->img.offset_x += 2;
//	vars->img.offset_y += 2;
}