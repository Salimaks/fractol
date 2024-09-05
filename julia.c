/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:44:14 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/24 19:36:25 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractol *f)
{
	int		i;
	double	x_temp;

	f->name = "julia";
	i = 0;
	f->zx = (f->x / f->zoom) + f->offset_x;
	f->zy = (f->y / f->zoom) + f->offset_y;
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
