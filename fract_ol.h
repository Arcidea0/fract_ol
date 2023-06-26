/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:24:49 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:24:51 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_image
{
	struct mlx_image	*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			iter;
	t_image		image;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	k;
	int			color;
	int			colorn;
	int			w;
	int			h;
	bool		space;
	bool		help;
}				t_fractol;

struct mlx_image	*my_mlx_new_image(void *mlx, int width, int height);

void				ft_putstr(char *s);
int					ft_atoi(const char *ptr);
double				ft_af(const char *ptr, int i);
double				ft_atof(const char *ptr);
void				sxal_input(int i);
void				my_mlx_pixel_put(t_image *data, int x, int y, int color);
void				mandelnkar(t_fractol *fr);
void				mandelbrot(t_fractol *fr, int x, int y);
void				julskzb(t_fractol *fr, char **v);
void				julnkar(t_fractol *f);
void				julia(t_fractol *f, int x, int y, t_complex *z);
int					julia_motion(int x, int y, t_fractol *fr);
void				*draw_fractal(t_fractol *f);
void				drow(t_fractol *fr, void (*funk)(), int n);
void				init(t_fractol *fr_value);
int					key_hookm(int keycode, t_fractol *fr);
int					key_hookj(int keycode, t_fractol *fr);
int					key_cross(t_fractol *data, int keycode);
void				change_max_iteration(int key, t_fractol *fractol);
int					mouse_hook(int mcode, int x, int y, t_fractol *fr);
int					mouse_hookm(int mcode, int x, int y, t_fractol *fr);
int					mouse_hookj(int mcode, int x, int y, t_fractol *fr);
void				keyer(int keycode, t_fractol *fr);
void				keyer1(int keycode, t_fractol *fr);
float				modul(float a);
int					get_color(t_fractol *fr, int iteration);
void				freeex(t_fractol *fr);
void				nishstub(char ptr);
void				stugum(int c, char **v);

#endif
