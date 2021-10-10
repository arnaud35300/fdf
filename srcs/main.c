/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:33 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/10 06:46:20 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*f;

	f = init_fdf_struct();
	if (!f || ac != 2 || !ft_strrstr(av[1], ".fdf") || !parse_map(f, av[1])
		|| !init_mlx_struct(&(f->m)))
		return (free_struct(f, print_error("Usage: ./fdf 42.fdf\n", 1)));
	f->x_start = WIDTH / 2;
	if (f->xmax > 0)
		f->space = WIDTH / f->xmax / 2;
	fdf(f);
	mlx_key_hook(f->m->win, &exit_window, f);
	mlx_mouse_hook(f->m->win, &zoom_window, f);
	mlx_hook(f->m->win, 33, 0, &destroy_fdf, f);
	mlx_loop(f->m->mlx);
	return (free_struct(f, 0));
}
