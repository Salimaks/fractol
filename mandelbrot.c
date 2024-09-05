/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:25:33 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/24 21:22:56 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractol	*f)
{
	int		i;
	double	x_temp;

	f->name = "mandelbrot";
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	while ((f->zx * f->zx + f->zy * f->zy) < 4.0 && ++i < f->max_iterations)
	{
		x_temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
		f->zx = x_temp;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, (f->color * i));
}
