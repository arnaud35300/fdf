/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 05:37:54 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:46:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_fdf *f)
{	
	int	x;
	int	y;

	y = -1;
	while (++y < f->ymax)
	{
		x = -1;
		while (++x < f->xmax)
		{
			f->m->color = get_color(f, f->matrix[y][x]);
			if (x < f->xmax - 1)
				mlx_print_line(*f, f->matrix[y][x], f->matrix[y][x + 1]);
			if (y < f->ymax - 1)
				mlx_print_line(*f, f->matrix[y][x], f->matrix[1 + y][x]);
		}
	}
}
