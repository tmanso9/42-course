#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	write_circle(t_data *img)
{
	int	x = img->line_length / (img->bits_per_pixel / 8) / 2;
	int	x1 = x - 75;
	int x2 = x + 75;
	int	y = 150;
	int	y1 = y / 2;
	int	y2 = y + 75;
	int	i = 0;

	while (x2 > x1)
	{
		while (y1 < y2 && i < 75)
		{
			my_mlx_pixel_put(img, x2, y1, create_trgb(0, 255, 255, 255));
			y1++;
			i++;
		}
		x2--;
		y1 = 75;
		i = 0;
	}
	/*my_mlx_pixel_put(img, x - 1, y1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x, y1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x + 1, y1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x - 2, y1 + 1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x - 1, y1 + 1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x, y1 + 1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x + 1, y1 +1, create_trgb(0, 255, 255, 255));
	my_mlx_pixel_put(img, x + 2, y1 +1, create_trgb(0, 255, 255, 255));*/
	

}

int	handle_no_event(void *vars)
{
	return (0);
}

void	handle_no_event()

int	handle_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	//printf("keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_vars *vars)
{
	//printf("key relase: %d\n", keysym);
	return (0);
}

int	handle_wheel(int button, int x, int y, t_vars *vars)
{
	printf("button %d, %d, %d\n", button, x, y);
	if (button == 4)
	{
	}
	return (0);
}

int	handle_motion(int x, int y, t_vars *vars)
{
	printf("hello at %d %d\n", x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, 500, 300, "Fract'ol");
	if (!vars.win)
	{
		free (vars.mlx);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(vars.mlx, 500, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	write_circle(&img);
	//my_mlx_pixel_put(&img, 15, 20, create_trgb(0, 255, 255, 255));
	/*int	x = 15;
	int	y = 15;
	while (y < 100)
	{
		my_mlx_pixel_put(&img, x, y, create_trgb(0, 255, y * 2, 0));
		y++;
	}
	y = 15;
	while (x < 100)
	{
		my_mlx_pixel_put(&img, x, y, create_trgb(0, 255, 0, x * 2));
		x++;
	}
	while (y < 100)
	{
		my_mlx_pixel_put(&img, x, y, create_trgb(0, 200 - (y * 2), 0, 255));
		y++;
	}
	while (x > 14)
	{
		my_mlx_pixel_put(&img, x, y, create_trgb(0, 0, 255 - (x * 2), 255));
		x--;
	}*/
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, handle_no_event, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, handle_keypress, &vars);
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, handle_keyrelease, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, handle_wheel, &vars);
	mlx_hook(vars.win, DestroyNotify, 0, handle_button, &vars);
	//mlx_hook(vars.win, MotionNotify, PointerMotionMask, handle_motion, &vars);

	mlx_loop(vars.mlx);

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}