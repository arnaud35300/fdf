/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:19:16 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:29:00 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_max(t_fdf *f)
{
	int	x;
	int	y;
	int	max;

	y = -1;
	max = 0;
	while (++y < f->ymax)
	{
		x = -1;
		while (++x < f->xmax)
			if (f->matrix[y][x].z > max)
				max = f->matrix[y][x].z;
	}
	return (max);
}

int	get_color(t_fdf *f, t_dot dot)
{
	int	max;
	int	color;
	int	div;

	max = get_max(f);
	color = WHITE;
	div = max / 6;
	if (div * 1 < dot.z)
		color = CADMIUM;
	if (div * 2 < dot.z)
		color = CERULEAN;
	if (div * 3 < dot.z)
		color = CELTIC;
	if (div * 4 < dot.z)
		color = VIVID;
	if (div * 5 < dot.z)
		color = ORANGE_CW;
	if (div * 6 < dot.z)
		color = ORANGE;
	return (color);
}
