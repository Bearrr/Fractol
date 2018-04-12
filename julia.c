/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:48:58 by ireva             #+#    #+#             */
/*   Updated: 2017/11/16 20:49:50 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_action2(int key, int x, int y, t_fract *fract)
{
	int p;
	int g;

	p = x;
	g = y;
	if (key == 5)
	{
		fract->zoom /= 1.1;
		fract->move_x += -((fract->h / 2 - fract->x) / 2000) / fract->zoom;
		fract->move_y += -((fract->w / 2 - fract->y) / 2000) / fract->zoom;
	}
	if (key == 4)
	{
		fract->zoom *= 1.1;
		fract->move_x += -((fract->h / 2 - fract->x) / 2000) / fract->zoom;
		fract->move_y += -((fract->w / 2 - fract->y) / 2000) / fract->zoom;
	}
	if (fract->fr == 1)
		julia(fract);
	if (fract->fr == 2)
		mandelbrotz(fract);
	if (fract->fr == 3)
		my_fractal(fract);
	return (0);
}

int		mouse_action(int x, int y, t_fract *fract)
{
	if (fract->stop == 1)
	{
		if (x >= fract->w / 2 && x < fract->w)
		{
			fract->c_im += ((x - fract->w / 2) * 0.00002);
			fract->c_re += ((x - fract->w / 2) * 0.00002);
		}
		if (x < fract->w / 2 && x > 0)
		{
			fract->c_im -= ((fract->w / 2 - x) * 0.00002);
			fract->c_re -= ((fract->w / 2 - x) * 0.00002);
		}
	}
	fract->x = x;
	fract->y = y;
	mlx_mouse_hook(fract->win, mouse_action2, fract);
	if (fract->fr == 1)
		julia(fract);
	if (fract->fr == 2)
		mandelbrotz(fract);
	if (fract->fr == 3)
		my_fractal(fract);
	return (0);
}

int		julia_norma(t_fract *fract, int x, int y)
{
	int i;

	i = 0;
	fract->new_re = 1.5 * (x - fract->w / 2)
		/ (0.5 * fract->zoom * fract->w) + fract->move_x;
	fract->new_im = (y - fract->h / 2)
		/ (0.5 * fract->zoom * fract->h) + fract->move_y;
	while (i < fract->max_iterations)
	{
		fract->old_re = fract->new_re;
		fract->old_im = fract->new_im;
		fract->new_re = fract->old_re * fract->old_re
			- fract->old_im * fract->old_im + fract->c_re;
		fract->new_im = 2 * fract->old_re * fract->old_im + fract->c_im;
		if ((fract->new_re * fract->new_re
			+ fract->new_im * fract->new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

void	julia(t_fract *fract)
{
	int	y;
	int	x;
	int	i;
	int	z;

	y = 0;
	i = 0;
	z = 0;
	while (y < fract->h)
	{
		x = 0;
		while (x < fract->w)
		{
			i = julia_norma(fract, x, y);
			z++;
			fract->continuous_index = i + 1 - (log(2) / fract->c_im) / log(2);
			write_pix(fract, z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->mlx_image, 0, 0);
	mlx_hook(fract->win, 2, 5, key_pressed, fract);
	mlx_loop(fract->mlx);
}
