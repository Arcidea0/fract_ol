/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:24:08 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:11 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx/mlx.h"

float	modul(float a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

void	keyer1(int keycode, t_fractol *fr)
{
	static int	i;

	if (keycode == 8)
	{
		i++;
		if (i % 3 == 1)
		{
			fr->color = 0x03FC0000;
			fr->colorn = 18;
		}
		else if (i % 3 == 2)
		{
			fr->color = 0x000003FC;
			fr->colorn = 2;
		}
		else
		{
			fr->color = 0x0003FC00;
			fr->colorn = 10;
		}
	}
	else if (keycode == 83 || keycode == 84)
		change_max_iteration(keycode, fr);
	else if (keycode == 49)
		fr->space = !fr->space;
}

void	keyer(int keycode, t_fractol *fr)
{
	if (keycode == 53)
		freeex(fr);
	else if (keycode == 123 || keycode == 0)
	{
		fr->max.r -= modul(fr->max.r - fr->min.r) * 0.05;
		fr->min.r -= modul(fr->max.r - fr->min.r) * 0.05;
	}
	else if (keycode == 124 || keycode == 2)
	{
		fr->max.r += modul(fr->max.r - fr->min.r) * 0.05;
		fr->min.r += modul(fr->max.r - fr->min.r) * 0.05;
	}
	else if (keycode == 126 || keycode == 13)
	{
		fr->max.i -= modul(fr->max.i - fr->min.i) * 0.05;
		fr->min.i -= modul(fr->max.i - fr->min.i) * 0.05;
	}
	else if (keycode == 125 || keycode == 1)
	{
		fr->max.i += modul(fr->max.i - fr->min.i) * 0.05;
		fr->min.i += modul(fr->max.i - fr->min.i) * 0.05;
	}
	else
		keyer1(keycode, fr);
}

int	key_cross(t_fractol *fr, int keycode)
{
	ft_putstr("Avart\n");
	(void)keycode;
	if (fr->mlx && fr->win)
		mlx_destroy_window(fr->mlx, fr->win);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	exit(0);
}
