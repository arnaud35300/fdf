/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:55:46 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/08 16:50:21 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_matrix(int **matrix, int ymax, int code)
{
	int	i;

	i = -1;
	if (!matrix)
		return (code);
	while (++i < ymax)
		free(matrix[i]);
	free(matrix);
	return (code);
}

int	free_mlx(t_mlx *m, int code)
{
	if (!m)
		return (code);
	if (m->mlx)
		free(m->mlx);
	free(m);
	return (code);
}

int	free_struct(t_fdf *f, int code)
{
	if (!f)
		return (code);
	if (f->matrix)
		free_matrix(f->matrix, f->ymax, 1);
	if (f->m)
		free_mlx(f->m, code);
	free(f);
	return (code);
}
