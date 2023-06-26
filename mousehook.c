/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:25:51 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:52 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	interpolate(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	mouse_hook(int mcode, int x, int y, t_fractol *fr)
{
	t_complex	mouse;
	float		zoom;

	mouse.r = (double)x / (fr->w / (fr->max.r - fr->min.r)) + fr->min.r;
	mouse.i = (double)y / (fr->h / (fr->max.i - fr->min.i)) + fr->min.i;
	if (mcode == 4 || mcode == 5)
	{
		if (mcode == 4)
			zoom = 0.9;
		if (mcode == 5)
			zoom = 1.1;
		fr->min.i = interpolate(mouse.i, fr->min.i, zoom);
		fr->min.r = interpolate(mouse.r, fr->min.r, zoom);
		fr->max.r = interpolate(mouse.r, fr->max.r, zoom);
		fr->max.i = interpolate(mouse.i, fr->max.i, zoom);
	}
	julia_motion(x, y, fr);
	mlx_clear_window(fr->mlx, fr->win);
	return (0);
}
