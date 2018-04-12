/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:04:16 by ireva             #+#    #+#             */
/*   Updated: 2017/11/16 20:12:05 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include "mlx.h"
# include <math.h>
# include "./libft/libft.h"

typedef struct			s_fract
{
	float				x;
	float				y;
	int					line_size;
	int					map_size;
	void				*win;
	void				*mlx;
	void				*mlx_image;
	int					pix;
	int					size_line;
	int					endian;
	char				*my_fractol;
	int					h;
	int					w;
	double				c_re;
	double				c_im;
	double				new_re;
	double				new_im;
	double				old_re;
	double				old_im;
	double				zoom;
	double				move_x;
	double				move_y;
	int					max_iterations;
	double				pr;
	double				pi;
	int					continuous_index;
	int					stop;
	int					fr;
	int					color_b;
	int					color_g;
	int					color_r;
}						t_fract;

void					mandelbrotz(t_fract *fract);
void					write_pix(t_fract *fract, int z);
int						key_pressed(int x, t_fract *fract);
void					julia(t_fract *fract);
void					move_julia(t_fract *fract, int flag);
int						mouse_action(int x, int y, t_fract *fract);
void					write_back(t_fract *fract, int x, int y, int z);
void					my_fractal(t_fract *fract);
void					tree_(t_fract *fract);
int						mouse_action2(int key, int x, int y, t_fract *fract);
void					init_my_fractal(t_fract *fract);
void					init_mandelbrot(t_fract *fract);
void					init_julia(t_fract *fract);
void					change_iteration(t_fract *fract, int flag);

#endif
