/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:18 by skassimi          #+#    #+#             */
/*   Updated: 2024/08/27 18:07:47 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define SIZE 800
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define DOWN_KEY 65362
# define UP_KEY 65364
# define ESC_KEY 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}	t_fractol;

int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strdup(const char *s1);
int		draw_fractal(t_fractol *f, char *fractal);
void	*draw_mandelbrot(void *f);
void	*draw_julia(t_fractol *f);
void	*draw_burning_ship(t_fractol *f);
void	calculate_mandelbrot(t_fractol	*f);
void	calculate_julia(t_fractol *f);
void	calculate_burning_ship(t_fractol *f);
void	put_color_to_pixel(t_fractol *fractal, int x, int y, int color);
void	init_fractal(t_fractol *f);
void	init_mlx(t_fractol *f);
void	zoom(t_fractol *f, int x, int y, int zoom);
int		key_hook(int key_code, t_fractol *f);
int		mouse_hook(int mouse_code, int x, int y, t_fractol *f);
int		exit_fractal(t_fractol *f);
void	error_msg(void);

#endif