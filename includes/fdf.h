/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:23 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 05:49:29 by arguilla         ###   ########.fr       */
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

# define HEIGHT	1500
# define WIDTH	1500
# define ESC	65307

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF

# define CADMIUM	0x0A1195
# define CERULEAN	0x2A52BE
# define CELTIC		0x2C70C6
# define VIVID		0xFF9A00
# define ORANGE_CW	0xFF8301
# define ORANGE		0xFF6601

typedef struct s_bresenham
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		color;
}				t_mlx;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
}				t_dot;

typedef struct s_fdf
{
	t_dot	**matrix;
	int		xmax;
	int		ymax;
	int		space;
	int		x_start;
	int		y_start;
	t_mlx	*m;
}				t_fdf;

int		print_error(char *error, int code);
int		parse_map(t_fdf *f, char *filename);
int		free_struct(t_fdf *f, int code);
int		free_matrix(t_dot **matrix, int xmax, int code);
int		free_mlx(t_mlx *mlx, int code);
int		init_mlx_struct(t_mlx	**m);
void	init_bresenham_struct(t_bresenham *b, t_dot dot1, t_dot dot2);
t_fdf	*init_fdf_struct(void);
int		mlx_print_line(t_fdf f, t_dot dot1, t_dot dot2);
int		get_color(t_fdf *f, t_dot dot);
void	fdf(t_fdf *f);
int		exit_window(int keycode, t_fdf *f);
int		zoom_window(int keycode, int x, int y, t_fdf *f);
int		destroy_fdf(t_fdf	*f);

#endif
