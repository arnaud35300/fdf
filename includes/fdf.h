/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:23 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/08 16:54:52 by arguilla         ###   ########.fr       */
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
# include <math.h>

# define	HEIGHT	500
# define	WIDTH	500
# define	ESC		65307
# define	WHITE	0xFFFFFF

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_fdf
{
	int		**matrix;
	int		xmax;
	int		ymax;
	t_mlx	*m;
}				t_fdf;

int	print_error(char *error, int code);
int	parse_map(t_fdf *f, char *filename);
int	free_struct(t_fdf *f, int code);
int	free_matrix(int **matrix, int xmax, int code);
int	free_mlx(t_mlx *mlx, int code);
int	init_mlx_struct(t_mlx	**m);
t_fdf	*init_fdf_struct(void);

# endif
