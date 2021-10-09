/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:23 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 02:44:24 by arguilla         ###   ########.fr       */
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

typedef	struct	s_bresenham
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	const_dx;
	int	const_dy;
	int	x_shift;
	int	y_shift;
}				t_bresenham;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef	struct	s_dot
{
	int	x;
	int	y;
	int	z;
}				t_dot;

typedef struct	s_fdf
{
	t_dot	**matrix;
	int		xmax;
	int		ymax;
	t_mlx	*m;
}				t_fdf;

int		print_error(char *error, int code);
int		parse_map(t_fdf *f, char *filename);
int		free_struct(t_fdf *f, int code);
int		free_matrix(t_dot **matrix, int xmax, int code);
int		free_mlx(t_mlx *mlx, int code);
int		init_mlx_struct(t_mlx	**m);
int		init_bresenham_struct(t_bresenham **b, t_dot dot1, t_dot dot2);
t_fdf	*init_fdf_struct(void);
int		mlx_print_line(t_mlx *m, t_dot dot1, t_dot dot2);

# endif
