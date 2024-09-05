/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:08:04 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/27 18:15:11 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xFCBE11;
	f->zoom = 300;
	f->offset_x = -1.8;
	f->offset_y = -1.21;
	f->max_iterations = 42;
}

void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 700, 700, "fract-ol");
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->addr = mlx_get_data_addr(f->img,
			&f->bits_per_pixel,
			&f->size_line,
			&f->endian);
}
