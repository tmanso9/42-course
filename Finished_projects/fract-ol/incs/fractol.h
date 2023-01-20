/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:04:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 11:57:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/incs/libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	char	fractal;
	char	julia_set;
	double	change_julia_re;
	double	change_julia_im;
	char	follow_mouse;
	char	color;
	char	help;
}	t_vars;

typedef struct s_fract
{
	double	real;
	double	im;
	double	ca;
	double	cb;
}	t_fract;

//Utils
void	check_args(int argc, char **argv, t_vars *vars);
void	init_struct(t_vars *vars);
void	clean_exit(t_vars *vars);
void	print_help(t_vars *vars);

//Handles
int		handle_cross(t_vars *vars);
int		handle_mouse(int button, int x, int y, t_vars *vars);
int		handle_key(int keysym, t_vars *vars);
int		render(t_vars *vars);
void	key_fractal_utils(int keysym, t_vars *vars);

//Draw
int		get_rgb(int r, int g, int b);
void	my_pixel_put(t_data *img, int x, int y, int color);
void	palette(t_vars *vars, int bright, double x, double y);

//Fractal math
void	zoom_in(t_vars *vars, int x, int y);
void	zoom_out(t_vars *vars, int x, int y);
double	get_coords(double x, double zoom, char type);
double	calc_iterations(t_vars *vars, double iterations);
double	map(double x, double in_max, double out_min, double out_max);

//Sets
void	do_fractal(t_vars *vars, char set);
void	mandelbrot(t_vars *vars);
int		get_color_mandel(t_vars *vars, double x, double y, double iterations);
void	julia(t_vars *vars);
int		get_color_julia(t_vars *vars, double x, double y, double iterations);

#endif