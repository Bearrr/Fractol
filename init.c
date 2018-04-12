/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:54:12 by ireva             #+#    #+#             */
/*   Updated: 2017/11/21 20:54:22 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iteration(t_fract *fract, int flag)
{
	if (flag == 0 && fract->max_iterations < 1000)
		fract->max_iterations++;
	if (flag == 1 && fract->max_iterations > 50)
		fract->max_iterations--;
	if (fract->fr == 1)
		julia(fract);
	if (fract->fr == 2)
		mandelbrotz(fract);
	if (fract->fr == 3)
		my_fractal(fract);
}

void	init_julia(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, 700, 700, "Julia");
	fract->mlx_image = mlx_new_image(fract->mlx, 700, 700);
	fract->my_fractol = mlx_get_data_addr(fract->mlx_image, &fract->pix,
		&fract->size_line, &fract->endian);
	fract->color_r = 230;
	fract->color_g = 230;
	fract->color_b = 230;
	fract->move_x = 0;
	fract->c_re = -0.7;
	fract->c_im = 0.27015;
	fract->zoom = 1;
	fract->move_y = 0;
	fract->max_iterations = 110;
	fract->fr = 1;
	fract->h = 700;
	fract->w = 700;
	julia(fract);
}

void	init_mandelbrot(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, 700, 700, "Mandelbrot");
	fract->mlx_image = mlx_new_image(fract->mlx, 700, 700);
	fract->my_fractol = mlx_get_data_addr(fract->mlx_image, &fract->pix,
		&fract->size_line, &fract->endian);
	fract->zoom = 1;
	fract->move_x = -0.5;
	fract->move_y = 0;
	fract->max_iterations = 110;
	fract->fr = 2;
	fract->h = 700;
	fract->w = 700;
	mandelbrotz(fract);
}

void	init_my_fractal(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, 700, 700, "Burningship");
	fract->mlx_image = mlx_new_image(fract->mlx, 700, 700);
	fract->my_fractol = mlx_get_data_addr(fract->mlx_image, &fract->pix,
		&fract->size_line, &fract->endian);
	fract->zoom = 1;
	fract->move_x = -0.5;
	fract->move_y = -0.5;
	fract->max_iterations = 110;
	fract->fr = 3;
	fract->h = 700;
	fract->w = 700;
	my_fractal(fract);
}
