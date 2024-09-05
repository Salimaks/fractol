/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:45:01 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/23 22:18:40 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(void)
{
	write(1, "Usage: ./fractol <NAME>\n", 24);
	write(1, "Available Fractals:\n", 21);
	write(1, "---> mandelbrot\n", 17);
	write(1, "---> julia\n", 13);
	write(1, "---> burningship\n", 18);
}

int	exit_fractal(t_fractol *f)
{
	if (!f)
		exit(0);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->mlx && f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	free(f);
	exit(0);
	return (0);
}
