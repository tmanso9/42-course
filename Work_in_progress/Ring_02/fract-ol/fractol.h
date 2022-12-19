#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# define MLX_ERROR 1
# define WIN_WIDTH 1500
# define WIN_HEIGTH 1500

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
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

typedef struct s_rect
{
	double	x;
	double	y;
	double	width;
	double	height;
	int	color;
}	t_rect;

typedef struct s_circle
{
	double	x;
	double	y;
	double	r;
	int		color;
}	t_circle;

//Utils
int		get_rgb(int r, int g, int b);
void	my_pixel_put(t_data *img, int x, int y, int color);
int		in_bounds(int x, int y);
void	zoom_in(t_vars *vars);
void	zoom_out(t_vars *vars);

//Shapes
void	rectangle(t_vars *vars, t_rect rect);
void	circle(t_vars *vars, t_circle circle);

#endif