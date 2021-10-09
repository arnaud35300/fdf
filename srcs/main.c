/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:33 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 03:39:27 by arguilla         ###   ########.fr       */
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

void	fdf(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;

# define SPACE 40
# define X_START 50
# define Y_START 50
	while (++y < f->ymax)
	{
		x = -1;
		while (++x < f->xmax)
		{
			/*if (x < f->xmax - 1)
				mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z}, (t_dot){f->matrix[y][x + 1].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z});
			if (y < f->ymax -1)
				mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z}, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y + 1][x].y * SPACE + Y_START, f->matrix[y][x].z});
			*/
			mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z}, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START + 40, f->matrix[y][x].z});
			mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z}, (t_dot){f->matrix[y][x].x * SPACE + X_START + 40, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z});
			mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START + 40, f->matrix[y][x].y * SPACE + Y_START + 40, f->matrix[y][x].z}, (t_dot){f->matrix[y][x].x * SPACE + X_START + 40, f->matrix[y][x].y * SPACE + Y_START, f->matrix[y][x].z});
			mlx_print_line(f->m, (t_dot){f->matrix[y][x].x * SPACE + X_START, f->matrix[y][x].y * SPACE + Y_START + 40, f->matrix[y][x].z}, (t_dot){f->matrix[y][x].x * SPACE + X_START + 40, f->matrix[y][x].y * SPACE + Y_START + 40, f->matrix[y][x].z});	
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

	/*int x = -1,  y = -1;
	while (++y < f->ymax)
	{
		x = -1;
		while (++x < f->xmax)
		{
			printf("y: %d ", f->matrix[y][x].y);
			printf("x: %d ", f->matrix[y][x].x);
			printf("z: %d | ", f->matrix[y][x].z);
		}
		printf("\n");
	}
*/
	fdf(f);
	mlx_key_hook(f->m->win, &exit_window, f);
	mlx_loop(f->m->mlx);
	return (free_struct(f, 0));
}
