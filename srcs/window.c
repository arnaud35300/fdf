/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 05:41:47 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:43:53 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_fdf(t_fdf	*f)
{
	mlx_destroy_window(f->m->mlx, f->m->win);
	mlx_destroy_display(f->m->mlx);
	free_struct(f, 0);
	exit(0);
}

int	exit_window(int keycode, t_fdf *f)
{
	if (keycode == ESC)
		destroy_fdf(f);
	return (1);
}

int	zoom_window(int keycode, int x, int y, t_fdf *f)
{
	(void)x;
	(void)y;
	if (keycode == 4 || keycode == 5)
	{
		mlx_clear_window(f->m->mlx, f->m->win);
		if (keycode == 4)
			f->space += 1;
		else
			f->space -= 1;
		fdf(f);
	}
	return (0);
}
