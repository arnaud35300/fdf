/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:23 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/25 03:23:52 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>

typedef struct	s_fdf
{
	int	**matrix;
	int	xmax;
	int	ymax;
}				t_fdf;

int	print_error(char *error, int code);
int	parse_map(t_fdf *f, char *filename);
int	free_struct(t_fdf *f, int code);
int	free_matrix(int **matrix, int xmax, int code);
# endif
