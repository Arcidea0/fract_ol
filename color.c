/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:24:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:24:29 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_color(t_fractol *fr, int iteration)
{
	float	x;

	x = 256. / (double)iteration;
	if (iteration > 255 && fr->colorn != 2)
		return (fr->color);
	else if (iteration <= 255 && fr->colorn != 2)
		fr->color = iteration << fr->colorn;
	else if (iteration < 64 && fr->colorn == 2)
		fr->color = iteration << fr->colorn;
	else if (iteration >= 64 && fr->colorn == 2)
	{
		if (iteration >= 64 && iteration < 128)
			fr->color = fr->color | ((iteration - 64) << 16);
		else if (iteration >= 128 && iteration < 256)
			fr->color = fr->color | ((iteration - 64) << 8) + (0xFF << 16);
	}
	return (fr->color);
}

int	julia_motion(int x, int y, t_fractol *fr)
{
	if (!fr->space && !fr->help)
	{
		fr->k.r = 5 * ((double)x / fr->w - 0.5);
		fr->k.i = 5 * ((double)(fr->h - y) / fr->h - 0.5);
		fr->space = 0;
	}
	return (0);
}
