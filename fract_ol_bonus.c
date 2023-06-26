/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:28:17 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/26 22:28:19 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

void	init(t_fractol *fr_value)
{
	fr_value->c.i = 0;
	fr_value->c.r = 0;
	fr_value->image.addr = 0;
	fr_value->image.bits_per_pixel = 0;
	fr_value->image.endian = 0;
	fr_value->image.img = 0;
	fr_value->image.line_length = 0;
	fr_value->max.r = 1;
	fr_value->max.i = 0;
	fr_value->min.r = -2;
	fr_value->min.i = -1.5;
	fr_value->k.i = -0.15;
	fr_value->k.r = -0.77;
	fr_value->mlx = 0;
	fr_value->win = 0;
	fr_value->iter = 50;
	fr_value->colorn = 10;
	fr_value->color = 0x0;
	fr_value->w = 1000;
	fr_value->h = 1000;
	fr_value->space = 0;
	fr_value->help = true;
}

void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == 83)
	{
		if (fractol->iter < 50)
			fractol->iter += 1;
		else if (fractol->iter < 1000000000)
			fractol->iter = (int)(fractol->iter * 1.05);
	}
	if (key == 84)
	{
		if (fractol->iter > 50)
			fractol->iter = (int)(fractol->iter / 1.05);
		else if (fractol->iter > 1)
			fractol->iter -= 1;
	}
}

int	main(int c, char **v)
{
	t_fractol	fr_value;
	t_fractol	*fr;

	init(&fr_value);
	fr = &fr_value;
	stugum(c, v);
	fr->mlx = mlx_init();
	if (ft_atoi(v[1]) == 1)
	{
		fr->win = mlx_new_window(fr->mlx, fr->w, fr->h, "Mandelbrot");
		mlx_hook(fr->win, 02, 0, key_hookm, fr);
		mlx_hook(fr->win, 4, 0, mouse_hookm, fr);
		mlx_hook(fr->win, 17, (1L << 17), key_cross, fr);
		drow(fr, mandelnkar, ft_atoi(v[1]));
	}
	else if (ft_atoi(v[1]) == 2)
		julskzb(fr, v);
	mlx_loop(fr->mlx);
	return (0);
}

void	drow(t_fractol *fr, void (*funk)(t_fractol *fr), int n)
{
	if (n == 2)
	{
		fr->min.i = -1.7;
		fr->min.r = -1.8;
		fr->max.r = 1.7;
	}
	fr->max.i = fr->min.i + (fr->max.r - fr->min.r) * fr->h / fr->w;
	if (!(fr->win))
		return ;
	fr->image.img = my_mlx_new_image(fr->mlx, fr->w, fr->h);
	fr->image.addr = mlx_get_data_addr(fr->image.img, &fr->image.bits_per_pixel,
			&fr->image.line_length, &fr->image.endian);
	funk(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.img, 0, 0);
}
