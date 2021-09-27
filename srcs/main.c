/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:33 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/27 23:16:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*f;

	f = malloc(sizeof(t_fdf));
	if (!f || ac != 2 || !ft_strrstr(av[1], ".fdf") || !parse_map(f, av[1]))
		return (free_struct(f, print_error("Usage: ./fdf 42.fdf\n", 1)));
	void	*mlx;
	void	*win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "bonjour");
	mlx_loop(mlx);

	int i = -1;

	while (++i <= 200)
		mlx_pixel_put(mlx, win, i, i, 0x00FFFFFF);
	(void)mlx;
	return (free_struct(f, 0));
}
