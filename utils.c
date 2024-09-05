/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:33:45 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/27 14:33:52 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x
				/ (f->zoom * zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y
				/ (f->zoom * zoom_level));
		f->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x
				/ (f->zoom / zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y
				/ (f->zoom / zoom_level));
		f->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_fractol *f)
{
	if (key_code == ESC_KEY)
		exit_fractal(f);
	else if (key_code == LEFT_KEY)
		f->offset_x -= 30 / f->zoom;
	else if (key_code == RIGHT_KEY)
		f->offset_x += 30 / f->zoom;
	else if (key_code == UP_KEY)
		f->offset_y -= 30 / f->zoom;
	else if (key_code == DOWN_KEY)
		f->offset_y += 30 / f->zoom;
	draw_fractal(f, f->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractol *f)
{
	if (mouse_code == MOUSE_UP)
		zoom(f, x, y, 1);
	else if (mouse_code == MOUSE_DOWN)
		zoom(f, x, y, -1);
	draw_fractal(f, f->name);
	return (0);
}

void	put_color_to_pixel(t_fractol *f, int x, int y, int color)
{
	int	*buffer;

	buffer = f->addr;
	buffer[(y * f->size_line / 4) + x] = color;
}
