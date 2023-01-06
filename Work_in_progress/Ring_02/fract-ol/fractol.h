/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:04:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/06 00:53:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "libft/incs/libft.h"

# define MLX_ERROR 1
# define WIN_WIDTH 720
# define WIN_HEIGHT 720

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	double	offset_x;
	double	offset_y;
	double	mousex;
	double	mousey;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	char	fractal;
	char	julia_set;
}	t_vars;

typedef struct s_fract
{
	double	real;
	double	im;
	double	ca;
	double	cb;
}	t_fract;


typedef struct s_rect
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		color;
}	t_rect;

typedef struct s_circle
{
	double	x;
	double	y;
	double	r;
	int		color;
}	t_circle;

//Utils
int		ft_strcmp(char *s1, char *s2);
int		get_rgb(int r, int g, int b);
void	my_pixel_put(t_data *img, int x, int y, int color);
int		in_bounds(int x, int y);
void	zoom_in(t_vars *vars, int x, int y);
void	zoom_out(t_vars *vars, int x, int y);
double	map(double x, double in_max, double out_min, double out_max);
double	get_coords(double x, double zoom);
double	calc_iterations(t_vars *vars, double iterations);
//Shapes
void	rectangle(t_vars *vars, t_rect rect);
void	circle(t_vars *vars, t_circle circle);

//Sets
void	do_fractal(t_vars *vars, char set);
void	mandelbrot(t_vars *vars);
int		get_color_mandel(t_vars *vars, double x, double y, double iterations);
void	julia(t_vars *vars);
int		get_color_julia(t_vars *vars, double x, double y, double iterations);

#endif