/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:42:04 by ireva             #+#    #+#             */
/*   Updated: 2017/11/16 20:43:32 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mand_norma(t_fract *fract, int x, int y)
{
	int		i;

	i = 0;
	fract->pr = 1.5 * (x - fract->w / 2) /
			(0.5 * fract->zoom * fract->w) + fract->move_x;
	fract->pi = (y - fract->h / 2) /
			(0.5 * fract->zoom * fract->h) + fract->move_y;
	fract->new_re = 0;
	fract->new_im = 0;
	fract->old_re = 0;
	fract->old_im = 0;
	while (i < fract->max_iterations)
	{
		fract->old_re = fract->new_re;
		fract->old_im = fract->new_im;
		fract->new_re = fract->old_re * fract->old_re
			- fract->old_im * fract->old_im + fract->pr;
		fract->new_im = 2 * fract->old_re * fract->old_im + fract->pi;
		if ((fract->new_re * fract->new_re +
			fract->new_im * fract->new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

void		mandelbrotz(t_fract *fract)
{
	int		i;
	int		y;
	int		x;
	int		z;

	z = 0;
	i = 0;
	y = 0;
	while (y < fract->h)
	{
		x = 0;
		while (x < fract->w)
		{
			i = mand_norma(fract, x, y);
			z++;
			fract->continuous_index = i + 1 - (log(2) / 1) / log(2);
			write_pix(fract, z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->mlx_image, 0, 0);
	mlx_hook(fract->win, 2, 5, key_pressed, fract);
	mlx_loop(fract->mlx);
}
