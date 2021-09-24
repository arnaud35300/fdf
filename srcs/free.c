/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:55:46 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/25 01:31:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_matrix(int **matrix, int xmax, int code)
{
	int	i;

	i = -1;
	if (!matrix)
		return (code);
	while (++i < xmax)
		free(matrix[i]);
	free(matrix);
	return (code);
}

int	free_struct(t_fdf *f, int code)
{
	if (!f)
		return (code);
	if (f->matrix)
		free_matrix(f->matrix, f->xmax, 1);
	free(f);
	return (code);
}
