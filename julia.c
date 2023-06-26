/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:24:59 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:01 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julskzb(t_fractol *fr, char **v)
{
	if (v[2] && v[3])
	{
		fr->k.r = ft_atof(v[2]);
		fr->k.i = ft_atof(v[3]);
		if (fr->k.r < -2. || fr->k.r > 2. || fr->k.i < -2. || fr->k.i > 2.)
			sxal_input(2);
	}
	fr->space = 1;
	fr->win = mlx_new_window(fr->mlx, fr->w, fr->h, "Julia");
	mlx_hook(fr->win, 4, 0, mouse_hookj, fr);
	mlx_hook(fr->win, 02, (1L << 0), key_hookj, fr);
	mlx_hook(fr->win, 17, (1L << 17), key_cross, fr);
	mlx_hook(fr->win, 6, (1L << 6), julia_motion, fr);
	drow(fr, julnkar, ft_atoi(v[1]));
}

void	julnkar(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	p;
	static int	i;

	x = -1;
	while (++x < f->w)
	{
		y = -1;
		while (++y < f->h)
		{
			p.r = f->min.r + (double)x * (f->max.r - f->min.r) / f->w;
			p.i = f->min.i + (double)y * (f->max.i - f->min.i) / f->h;
			julia(f, x, y, &p);
		}
	}
	if (!i++)
		printf("Julia done\n");
}

void	julia(t_fractol *f, int x, int y, t_complex *z)
{
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < f->iter)
	{
		if ((z->r * z->r + z->i * z->i) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * z->r * z->i + f->k.i;
		z->r = z->r * z->r - z->i * z->i + f->k.r;
		z->i = tmp;
	}
	if (is_in_set == 1)
		my_mlx_pixel_put(&f->image, x, y, 0x000000);
	else
		my_mlx_pixel_put(&f->image, x, y, get_color(f, n));
}

int	key_hookj(int keycode, t_fractol *fr)
{
	if (keycode == 24)
	{
		fr->k.i += 0.03;
		fr->k.r += 0.03;
	}
	if (keycode == 27)
	{
		fr->k.i -= 0.03;
		fr->k.r -= 0.05;
	}
	keyer(keycode, fr);
	mlx_clear_window(fr->mlx, fr->win);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	fr->image.img = mlx_new_image(fr->mlx, fr->w, fr->h);
	julnkar(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.img, 0, 0);
	return (0);
}

int	mouse_hookj(int mcode, int x, int y, t_fractol *fr)
{
	mouse_hook(mcode, x, y, fr);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	fr->image.img = mlx_new_image(fr->mlx, fr->w, fr->h);
	julnkar(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.img, 0, 0);
	return (0);
}
