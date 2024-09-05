/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:35:11 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/22 19:32:06 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_mandelbrot(void *fractal)
{
	t_fractol	*f;

	f = (t_fractol *)fractal;
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_mandelbrot(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}

void	*draw_julia(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_julia(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}

void	*draw_burning_ship(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_burning_ship(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}
