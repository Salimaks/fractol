/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:39:30 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/27 16:41:18 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractol *f, char *fractal)
{
	if (ft_strncmp(fractal, "mandelbrot", 11) == 0)
		draw_mandelbrot(f);
	else if (ft_strncmp(fractal, "julia", 6) == 0)
	{
			f->cx = -0.766667;
			f->cy = -0.090000;
		draw_julia(f);
	}
	else if (ft_strncmp(fractal, "burningship", 12) == 0)
		draw_burning_ship(f);
	else
	{
		error_msg();
		exit_fractal(f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	*f;

	if (ac != 2)
	{
		error_msg();
		return (0);
	}
	f = (t_fractol *)malloc(sizeof(t_fractol));
	init_fractal(f);
	init_mlx(f);
	mlx_hook(f->win, 17, 0, exit_fractal, f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	draw_fractal(f, av[1]);
	mlx_loop(f->mlx);
	return (0);
}
