/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:26 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:35:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bresenham_struct(t_bresenham *b, t_dot dot1, t_dot dot2)
{
	b->ex = ft_abs(dot2.x - dot1.x);
	b->ey = ft_abs(dot2.y - dot1.y);
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->const_dx = b->ex;
	b->const_dy = b->ey;
	b->x_shift = 1;
	b->y_shift = 1;
	if (dot1.x > dot2.x)
		b->x_shift = -1;
	if (dot1.y > dot2.y)
		b->y_shift = -1;
}

int	init_mlx_struct(t_mlx **m)
{
	*m = malloc(sizeof(t_mlx));
	if (!(*m))
		return (0);
	(*m)->color = WHITE;
	(*m)->mlx = mlx_init();
	if (!(*m)->mlx)
		return (0);
	(*m)->win = mlx_new_window((*m)->mlx, WIDTH, HEIGHT, "fdf");
	if (!(*m)->win)
		return (0);
	return (1);
}

t_fdf	*init_fdf_struct(void)
{
	t_fdf	*f;

	f = malloc(sizeof(t_fdf));
	if (!f)
		return (f);
	f->matrix = NULL;
	f->m = NULL;
	f->space = 40;
	f->x_start = 400;
	f->y_start = 100;
	return (f);
}
