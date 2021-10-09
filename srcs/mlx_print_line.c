/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:41:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 02:44:15 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(t_mlx *m, t_bresenham *b, t_dot dot)
{
	int	i;

	i = -1;
	while (++i <= b->const_dx)
	{
		mlx_pixel_put(m->mlx, m->win, dot.x, dot.y, WHITE);
		dot.x += b->x_shift;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			dot.y += b->y_shift;
			b->ex += b->dx;
		}
	}
}

static void	reverse_bresenham(t_mlx *m, t_bresenham *b, t_dot dot)
{
	int	i;

	i = -1;
	while (++i <= b->const_dy)
	{
		mlx_pixel_put(m->mlx, m->win, dot.x, dot.y, WHITE);
		dot.y += b->y_shift;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			dot.x += b->x_shift;
			b->ey += b->dy;
		}
	}
}

int	mlx_print_line(t_mlx *m, t_dot dot1, t_dot dot2)
{
	t_bresenham	*b;

	if (!init_bresenham_struct(&b, dot1, dot2))
		return (0);
	if (b->const_dx > b->const_dy)
		bresenham(m, b, dot1);
	if (b->const_dx < b->const_dy)
		reverse_bresenham(m, b, dot1);
	free(b);
	return (1);
}
