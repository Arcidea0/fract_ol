/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:40:08 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:40:10 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	sxal_input(int i)
{
	if (i == 1)
	{
		ft_putstr("//// Miayn hamary bavarar e.\\\\\\\\\n");
		ft_putstr("Miguce srancic mekn yntres?\n");
		ft_putstr("1. Mandelbrot\n");
		ft_putstr("2. Julia (ays depqum karox eq nermucel ");
		ft_putstr("evs erku tiv (-2, 2) mijakayqum)\n");
	}
	else if (i == 2)
	{
		ft_putstr("Try to input numbers in diapason (-2, 2)");
	}
	exit(1);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

struct mlx_image	*my_mlx_new_image(void *mlx, int width, int height)
{
	return (mlx_new_image(mlx, width, height));
}

void	freeex(t_fractol *fr)
{
	if (fr->mlx && fr->win)
		mlx_destroy_window(fr->mlx, fr->win);
	if (fr->mlx && fr->image.img)
		mlx_destroy_image(fr->mlx, fr->image.img);
	exit(1);
}

void	stugum(int c, char **v)
{
	if (c < 2 || (ft_atoi(v[1]) == 1 && c > 2)
		|| (ft_atoi(v[1]) != 1 && ft_atoi(v[1]) != 2))
		sxal_input(1);
	else if (c > 2 && ft_atoi(v[1]) == 2)
	{
		if (c > 4 || c == 3)
			sxal_input(1);
		ft_atof(v[2]);
		ft_atof(v[3]);
	}
}
