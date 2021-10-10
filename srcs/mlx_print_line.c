/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:41:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:46:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

static void	bresenham(t_mlx *m, t_bresenham b, t_dot dot)
{
	int	i;

	i = -1;
	while (++i <= b.const_dx)
	{
		mlx_pixel_put(m->mlx, m->win, dot.x, dot.y, m->color);
		dot.x += b.x_shift;
		b.ex -= b.dy;
		if (b.ex < 0)
		{
			dot.y += b.y_shift;
			b.ex += b.dx;
		}
	}
}

static void	reverse_bresenham(t_mlx *m, t_bresenham b, t_dot dot)
{
	int	i;

	i = -1;
	while (++i <= b.const_dy)
	{
		mlx_pixel_put(m->mlx, m->win, dot.x, dot.y, m->color);
		dot.y += b.y_shift;
		b.ey -= b.dx;
		if (b.ey < 0)
		{
			dot.x += b.x_shift;
			b.ey += b.dy;
		}
	}
}

int	mlx_print_line(t_fdf f, t_dot dot1, t_dot dot2)
{
	t_bresenham	b;

	dot1.x = dot1.x * f.space + f.x_start;
	dot1.y = dot1.y * f.space + f.y_start;
	dot2.x = dot2.x * f.space + f.x_start;
	dot2.y = dot2.y * f.space + f.y_start;
	isometric(&(dot1.x), &(dot1.y), dot1.z);
	isometric(&(dot2.x), &(dot2.y), dot2.z);
	init_bresenham_struct(&b, dot1, dot2);
	if (b.const_dx > b.const_dy)
		bresenham(f.m, b, dot1);
	if (b.const_dx <= b.const_dy)
		reverse_bresenham(f.m, b, dot1);
	return (1);
}
