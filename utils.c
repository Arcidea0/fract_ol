/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:26:11 by armgevor          #+#    #+#             */
/*   Updated: 2023/06/19 23:26:12 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		write (1, &str[i], 1);
}

int	ft_atoi(const char *ptr)
{
	int	nshan;
	int	i;
	int	tiv;

	tiv = 0;
	i = 0;
	nshan = 1;
	while (ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == ' ' || ptr[i] == '\r')
		i++;
	if (ptr[i] == '+')
		i++;
	if (ptr[i] == '-')
	{
		nshan = -1;
		i++;
	}
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		tiv = tiv * 10 + (ptr[i] - '0');
		i++;
	}
	nishstub(ptr[i]);
	return (nshan * tiv);
}

double	ft_af(const char *ptr, int i)
{
	double	tiv;
	double	ket;

	tiv = 0;
	ket = .1;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		tiv = tiv * 10 + (ptr[i] - '0');
		i++;
	}
	if (ptr[i] == '.')
		i++;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		tiv += (ptr[i] - '0') * ket;
		ket *= 0.1;
		i++;
	}
	nishstub(ptr[i]);
	return (tiv);
}

double	ft_atof(const char *ptr)
{
	double	nshan;
	int		i;

	i = 0;
	nshan = 1.;
	while (ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == ' ' || ptr[i] == '\r')
		i++;
	if (ptr[i] == '+')
		i++;
	if (ptr[i] == '-')
	{
		nshan = -1.;
		i++;
	}
	return (nshan * ft_af(ptr, i));
}

void	nishstub(char ptr)
{
	if (ptr)
		sxal_input(1);
}
