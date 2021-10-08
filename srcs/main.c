/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:33 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 01:18:08 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_window(int keycode, t_fdf *f)
{
	if (keycode != ESC)
		return (0);
	mlx_destroy_window(f->m->mlx, f->m->win);
	mlx_destroy_display(f->m->mlx);
	free_struct(f, 0);
	exit(0);
}

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_line(t_mlx *mlx, int dot1[], int dot2[])

void	fdf(t_fdf *f)
{
	int x1 = 200, y1 = 40;
	int	x2 = 150, y2 = 300;

	
	int	ex = abs(x2 - x1);
	int	ey = abs(y2 - y1);
	int dx = 2 * ex;
	int	dy = 2 * ey;
	int Dx = ex;
	int Dy = ey;
	int i = 0;
	int Xincr = 1;
	int Yincr = 1;
	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	if (Dx > Dy)
	{
		while(i <= Dx)
		{
			mlx_pixel_put(f->m->mlx, f->m->win, x1, y1, WHITE);
			i++;
			x1+=Xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += Yincr;
				ex += dx;
			}
		}
	}
	
	if (Dx < Dy)
	{
		while(i <= Dy)
		{
			mlx_pixel_put(f->m->mlx, f->m->win, x1, y1, WHITE);
			i++;
			y1+=Yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += Xincr;
				ey += dy;
			}
		}
	}


}

int	main(int ac, char **av)
{
	t_fdf	*f;

	f = init_fdf_struct();
	if (!f || ac != 2 || !ft_strrstr(av[1], ".fdf") || !parse_map(f, av[1])
		|| !init_mlx_struct(&(f->m)))
		return (free_struct(f, print_error("Usage: ./fdf 42.fdf\n", 1)));

	int x = -1,  y = -1;
	while (++y < f->ymax)
	{
		x = -1;
		while (++x < f->xmax)
			printf("%d ", f->matrix[y][x]);
		printf("\n");
	}

	fdf(f);
	mlx_key_hook(f->m->win, &exit_window, f);
	mlx_loop(f->m->mlx);
	return (free_struct(f, 0));
}
