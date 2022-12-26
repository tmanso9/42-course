/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:53:45 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/26 18:34:15 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	render_background(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGTH)
	{
		j = 0;
		while (j < WIN_WIDTH)
			my_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render(t_vars *vars)
{
	if (!vars->win)
		return (1);
	render_background(&vars->img, get_rgb(0, 0, 0));
	//circle(vars, (t_circle){WIN_WIDTH / 2 + vars->img.offset_x, \
		WIN_HEIGTH / 2 + vars->img.offset_y, \
		200 * vars->img.x, get_rgb(0, 0, 180)});
	// rectangle(vars, (t_rect){10 + vars->img.offset_x, \
		10 + vars->img.offset_y, 10 * vars->img.x, \
		5 * vars->img.y, get_rgb(180, 0, 0)});
	if (vars->fractal == 1)
		mandelbrot(vars);
	if (vars->fractal == 2)
		julia(vars);
	// circle(vars, (t_circle){WIN_WIDTH / 2 + vars->img.offset_x, \
		WIN_HEIGTH / 2 + vars->img.offset_y, \
		10 * vars->img.x, get_rgb(255, 0, 0)});
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	handle_key(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape || keysym == XK_q)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (keysym == XK_Right || keysym == XK_d)
		vars->img.offset_x += 20;
	if (keysym == XK_Left || keysym == XK_a)
		vars->img.offset_x -= 20;
	if (keysym == XK_Up || keysym == XK_w)
		vars->img.offset_y -= 20;
	if (keysym == XK_Down || keysym == XK_s)
		vars->img.offset_y += 20;
	if (keysym == XK_plus)
		zoom_in(vars);
	if (keysym == XK_minus)
		zoom_out(vars);
	if (keysym == XK_1)
		vars->fractal = 1;
	if (keysym == XK_2)
		vars->fractal = 2;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		zoom_in(vars);

	}
	if (button == 5)
	{
		zoom_out(vars);

	}
	return (0);
}

int	handle_motion(int x, int y, t_vars *vars)
{
	vars->img.mousex = x;
	vars->img.mousey = y;
	printf("%d %d\n", x, y);
}

int	handle_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGTH, "First window");
	vars->img.x = 1;
	vars->img.y = 1;
	vars->img.mousex = 0;
	vars->img.mousey = 0;
	vars->fractal = 0;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandel") || (!ft_strcmp(argv[1], "1")))
			vars->fractal = 1;
		else if (!ft_strcmp(argv[1], "julia") || (!ft_strcmp(argv[1], "2")))
			vars->fractal = 2;
	}
	vars->img.offset_x = 0;
	vars->img.offset_y = 0;
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_key_hook(vars->win, &handle_key, vars);
	mlx_mouse_hook(vars->win, &handle_mouse, vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, &handle_motion, vars);
	mlx_hook(vars->win, DestroyNotify, 0, &handle_cross, vars);
	mlx_loop(vars->mlx);
	
	//printf("got here\n");
	
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
}
