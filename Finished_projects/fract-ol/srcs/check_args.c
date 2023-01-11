/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:21:49 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/09 19:34:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage: ./fractol <type of fractal> <additional params>\n");
	ft_printf("\nTypes of fractals: mandelbrot (m or 1) or julia (j or 2)\n");
	ft_printf("Additional params for julia: ");
	ft_printf("number from 0-6 to chose the set (defaults to 0)\n");
	ft_printf("\nExamples:\n./fractol m OR ");
	ft_printf("./fractol 1\n./fractol j 2 OR ./fractol 2 6\n\n");
}

static void	print_error(t_vars *vars)
{
	ft_printf("\nINCORRECT ARGUMENTS!\n\n");
	print_usage();
	clean_exit(vars);
}

static void	print_missing(t_vars *vars)
{
	ft_printf("\nMISSING ARGUMENTS!\n\n");
	print_usage();
	clean_exit(vars);
}

void	check_args(int argc, char **argv, t_vars *vars)
{
	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "m", 2) || (!ft_strncmp(argv[1], "1", 2)))
		{
			vars->img.offset_x = -150;
			vars->fractal = 1;
		}
		else if (!ft_strncmp(argv[1], "j", 2) || (!ft_strncmp(argv[1], "2", 2)))
		{
			vars->img.offset_x = 0;
			vars->fractal = 2;
			if (argv[2])
				vars->julia_set = ft_atoi(argv[2]);
		}
		else
			print_error(vars);
	}
	else
		print_missing(vars);
}
