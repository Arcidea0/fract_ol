/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:25:26 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:27 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mandelnkar(t_fractol *fr)
{
	int			x;
	int			y;
	static int	i;

	y = -1;
	while (++y < fr->h)
	{
		x = -1;
		while (++x < fr->w)
		{
			fr->c.r = fr->min.r + (double)x * (fr->max.r - fr->min.r) / fr->w;
			fr->c.i = fr->min.i + (double)y * (fr->max.i - fr->min.i) / fr->h;
			mandelbrot(fr, x, y);
		}
	}
	if (!i++)
		printf("Mandelbrot done\n");
}

void	mandelbrot(t_fractol *fr, int x, int y)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	int		mejn_e;

	zr = 0;
	zi = 0;
	n = -1;
	mejn_e = 1;
	while (++n < fr->iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			mejn_e = 0;
			break ;
		}
		tmp = 2 * zr * zi + fr->c.i;
		zr = zr * zr - zi * zi + fr->c.r;
		zi = tmp;
	}
	if (mejn_e == 1)
		my_mlx_pixel_put(&(fr->image), x, y, 0x000000);
	else
		my_mlx_pixel_put(&(fr->image), x, y, get_color(fr, n));
}

int	key_hookm(int keycode, t_fractol *fr)
{
	keyer(keycode, fr);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	fr->image.img = mlx_new_image(fr->mlx, fr->w, fr->h);
	mandelnkar(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.img, 0, 0);
	return (0);
}

int	mouse_hookm(int mcode, int x, int y, t_fractol *fr)
{
	mouse_hook(mcode, x, y, fr);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	fr->image.img = mlx_new_image(fr->mlx, fr->w, fr->h);
	mandelnkar(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.img, 0, 0);
	return (0);
}
