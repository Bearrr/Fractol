/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:20:29 by ireva             #+#    #+#             */
/*   Updated: 2017/11/16 21:49:55 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_fract *fract, int flag)
{
	if (flag == 0)
		fract->color_r--;
	if (flag == 1)
		fract->color_g--;
	if (flag == 2)
		fract->color_b--;
	if (flag == 3)
		fract->color_r++;
	if (flag == 4)
		fract->color_g++;
	if (flag == 5)
		fract->color_b++;
	if (fract->fr == 1)
		julia(fract);
	if (fract->fr == 2)
		mandelbrotz(fract);
	if (fract->fr == 3)
		my_fractal(fract);
}

void	move(t_fract *fract, int flag)
{
	if (flag == 0)
		fract->move_x += 0.02;
	if (flag == 1)
		fract->move_x -= 0.02;
	if (flag == 2)
		fract->move_y += 0.02;
	if (flag == 3)
		fract->move_y -= 0.02;
	if (fract->fr == 1)
		julia(fract);
	if (fract->fr == 2)
		mandelbrotz(fract);
	if (fract->fr == 3)
		my_fractal(fract);
}

int		key_pressed(int x, t_fract *fract)
{
	(x == 53) ? exit(1) : 0;
	(x == 123) ? move(fract, 0) : 0;
	(x == 126) ? move(fract, 2) : 0;
	(x == 125) ? move(fract, 3) : 0;
	(x == 124) ? move(fract, 1) : 0;
	if (x == 258)
	{
		fract->stop = 1;
		mlx_hook(fract->win, 6, 5, mouse_action, fract);
	}
	(x == 269) ? fract->stop = 0 : 0;
	(x == 83) ? change_color(fract, 0) : 0;
	(x == 84) ? change_color(fract, 1) : 0;
	(x == 85) ? change_color(fract, 2) : 0;
	if (x == 69)
		change_iteration(fract, 0);
	if (x == 78)
		change_iteration(fract, 1);
	if (x == 86)
		change_color(fract, 3);
	if (x == 87)
		change_color(fract, 4);
	if (x == 88)
		change_color(fract, 5);
	return (0);
}

void	write_pix(t_fract *fract, int z)
{
	z = z * 4;
	fract->my_fractol[z] = (unsigned char)(sin(0.016
		* fract->continuous_index + 4) * fract->color_b + 25);
	fract->my_fractol[z + 1] = (unsigned char)(sin(0.013
		* fract->continuous_index + 2) * fract->color_g + 25);
	fract->my_fractol[z + 2] = (unsigned char)(sin(0.01 *
		fract->continuous_index + 1) * fract->color_r + 25);
}

int		main(int argc, char **argv)
{
	t_fract fract;

	if (argc == 2)
	{
		fract.color_r = 275;
		fract.color_g = -9;
		fract.color_b = -2000;
		fract.stop = 0;
		if (ft_strcmp(argv[1], "Julia") == 0)
			init_julia(&fract);
		if (ft_strcmp(argv[1], "Mand") == 0)
			init_mandelbrot(&fract);
		if (ft_strcmp(argv[1], "Burn") == 0)
			init_my_fractal(&fract);
		else
			write(1, "Wrog fractal, u can choose: \nJulia\nMand\nBurn\n", 45);
	}
	else
		write(1, "Wrog fractal, u can choose: \nJulia\nMand\nBurn\n", 45);
	return (0);
}
