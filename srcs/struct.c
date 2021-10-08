/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:26 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/08 16:40:23 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_mlx_struct(t_mlx **m)
{
	*m = malloc(sizeof(t_mlx));
	if (!(*m))
		return (0);
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
	return (f);
}
